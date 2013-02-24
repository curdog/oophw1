#include "deck.hpp"
#include <iostream>

#define HAND_SIZE 10

using namespace std;

void printHand( Card[], int ); 

int main() {
  Deck deck = new Deck();
  int choice = 1;
  
  while( choice ){
    //
    
    cout << "1:  Play Game" << endl;
    cout << "0:  Quit" << endl;
    cin >> choice;
    
    if( !choice ) continue;
    
    deck.shuffle();
    
    //players hand
    Card** hand = new Card*[10];
    //AI's
    Ai a,b;
    a = Ai( HAND_SIZE );
    b = Ai( HAND_SIZE );
    
    
    //order player first, ai a, ai b
    //bids'
    int bids[] = {0,0,0};
    //scores'
    int scores[] = {0,0,0}
   
   //deal
    for( int i = 0; i < HAND_SIZE; i++ ){
      hand[i] = deck.deal();
      a.recieveDelt( deck.deal() );
      b.recieveDelt( deck.deal() );
    }

    //bid
    cout << "Players bid: ";
    cin >> bids[0];
    
    bids[1] = a.makeBid();
    bids[2] = b.makeBid();
 
    bool winner = false;
   
    Card** board = new Card*[];
    while( !winner ){
    
    //play bard music
    
    //player plays
    cout<<"Play a card.";
    cin>> ;
    
    
    
    //ai a plays
    a.play_Card( board );
    //ai b plays 
    b.play_Card( board );
    
    }
    
  }//input loop
  
  return 0;
}

void printHand( Card[] hand, int numCards ){
  for( int i = 0; i < numCards; i++ ){
    cout << hand[i].getNumber() << " " << hand[i].getSuit() << endl;
  }
} 

void 
