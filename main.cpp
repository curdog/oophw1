#include "deck.hpp"
#include "ai.hpp"
#include <iostream>

#define HAND_SIZE 10

using namespace std;

void printHand( Card**, int );
int pickCard( Card**, int );

int main() {
  Deck deck =  Deck();
  int choice = 1;
  
  while( choice ){
    
    cout << "1: Play Game" << endl;
    cout << "0: Quit" << endl;
    cin >> choice;
    
    if( !choice ) continue;
    
    deck.shuffle();
    
    //players hand
    Card** hand = new Card*[10];
    //AI's
    Ai a = Ai( HAND_SIZE );
    Ai b = Ai( HAND_SIZE );
    
    
    //order player first, ai a, ai b
    //bids'
    int bids[] = {0,0,0};
    //scores'
    int scores[] = {0,0,0};
    //players remaining cards
    int numCards = 0;

   //deal
    for( int i = 0; i < HAND_SIZE; i++ ){
      hand[i] = deck.deal();
      numCards++;
      a.recieveDelt( deck.deal() );
      b.recieveDelt( deck.deal() );
    }

    //bid
    cout << "Players bid: ";
    cin >> bids[0];
    
    bids[1] = a.makeBid();
    bids[2] = b.makeBid();
 
    bool winner = false;
   
    Card** board = new Card*[3];
    while( !winner ){
    
    //play bard music
    
    //player plays ( in function pickCard returns a Card pointer)
    int pickedCard = pickCard(  hand,  numCards );
    board[0] = hand[ pickedCard ];//change
    hand[pickedCard] = 0;//remove card from hand
    
    //arrayShift to put zeros at end;
    for(int i = 0; i < HAND_SIZE; i++){
            if( hand[i]==0){
	      hand[i]= hand[i+1]; //swap
	      hand[i+1] = 0;
            }
    }
    //ai a plays
    a.play_Card( board );
    //ai b plays
    b.play_Card( board );
    
    //function to pick a winner win condition is highest card of suit
    //score
    
    //after all this works then work on changing player order with who wins.
    
    }
    
  }//input loop
  
  return 0;
}

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
      
    }
    
  
  
  return choice;
}
