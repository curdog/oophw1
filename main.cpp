#include "deck.hpp"
#include "ai.hpp"
#include <iostream>

#define HAND_SIZE 10
#define PLAYERS 3

using namespace std;

void printHand( Card**, int );
int pickCard( Card**, int );

int main() {
  Deck deck =  Deck();
  bool won = false;
  
	//players hand
	Card** hand = new Card*[HAND_SIZE];
	//AI's
	Ai a = Ai( HAND_SIZE );
	Ai b = Ai( HAND_SIZE );
	
	//order player first, ai a, ai b
	//bids'
	int bids[] = {0,0,0};
	//scores'
	int scores[] = {0,0,0};
	//made tricks
	int tricks[] = {0,0,0};
	//players remaining cards
	int numCards = 0;
	
	
  while( !won ){
    
    //deck.shuffle();
    
		//deal
    for( int i = 0; i < HAND_SIZE; i++ ){
      hand[i] = deck.deal();
      numCards++;
      a.recieveDelt( deck.deal() );
      b.recieveDelt( deck.deal() );
    }
    
    //print cards
    printHand( hand, numCards);
		
    //bid
    cout << "Players bid: ";
    cin >> bids[0];
    
    bids[1] = a.makeBid();
    bids[2] = b.makeBid();
		
		
    Card** board = new Card*[PLAYERS];
		
		while ( numCards > 0 ){
			//play bard music
			
			//player plays ( in function pickCard returns a Card pointer)
			int pickedCard = pickCard(  hand,  numCards );
			board[0] = hand[ pickedCard ];//change
			hand[pickedCard] = 0;//remove card from hand
			
			//arrayShift to put zeros at end;
			//minus one to prevent overflow also doesn't matter if there is a zero already at end
			for(int i = 0; i < HAND_SIZE - 1; i++){
				if( hand[i]==0){
					hand[i]= hand[i+1]; //swap
					hand[i+1] = 0;
				}
			}
			
			//ai a plays
			a.play_Card( board, PLAYERS );
			//ai b plays
			b.play_Card( board, PLAYERS );
			
			//hand winner
			int highest = 0;
			for( int i =0; i < PLAYERS; i++ ){
				if (board[i]->getNumber() > board[highest]->getNumber() && board[0]->getSuit() == board[i]->getSuit() ) {
					highest = i;
				}
			}
			tricks[highest]++;
			
			//clear board of cards
			for (int i =0; i<PLAYERS; i++) {
				board[i]=0;
			}
			
		}//end of hand
		
		//compute scores
		for( int i = 0; i < PLAYERS; i++ ){
			//made bid
			if( bids[i] >= tricks[i] ){
				scores[i] += tricks[i] * 10;
			}
			//did not make bid
			else {
				scores[i] += -( tricks[i] * 10 );
			}

		}
		
		//check for wins
		for (int i = 0; i < PLAYERS; i++) {
			
		}
		
	} //next hand
	
	//end screen
	cout << "Player: " << scores[0] << endl;
	cout << "Computer A: " << scores[1] << endl;
	cout << "Computer B: " << scores[2] << endl;
	
	return 0;
}

//auxillary functions for readiblity

void printHand( Card** hand, int numCards ){
  for( int i = 0; i < numCards; i++ ){
    cout << hand[i]->getNumber() << " " << hand[i]->getSuit() << endl;
  }
}

//returns index of selected card
int pickCard( Card** hand, int numCards ){
    int choice;
    cout<<"Play a card.";
    for( int i = 0; i < numCards; i++ ){
      cout << "Choice: " << i << " " << hand[i]->getNumber() << " of " << hand[i]->getSuit() << endl;
    }
    while( !(cin>> choice) ){
      cout << "Bad entry" <<endl;
      cin.clear();
			cin.ignore(1000,'\n');
    }
    
  return choice;
}
