#include "deck.hpp"
#include "ai.hpp"
#include <iostream>

#define HAND_SIZE 10

using namespace std;

void printHand( Card**, int );
int pickCard( Card**, int );

int main() {
<<<<<<< HEAD
  Deck deck =  Deck();
=======
  Dec::deck = new Deck();
>>>>>>> 51320ad7e67f8cf6c979e21b15cdd86ebeb813e1
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
<<<<<<< HEAD
    Ai a = Ai( HAND_SIZE );
    Ai b = Ai( HAND_SIZE );
=======
    Ai a,b;
    a = Ai( HAND_SIZE );
    b = Ai( HAND_SIZE );
>>>>>>> 51320ad7e67f8cf6c979e21b15cdd86ebeb813e1
    
    
    //order player first, ai a, ai b
    //bids'
    int bids[] = {0,0,0};
    //scores'
<<<<<<< HEAD
    int scores[] = {0,0,0};
    //players remaining cards
    int numCards = 0;

=======
    int scores[] = {0,0,0}
   
>>>>>>> 51320ad7e67f8cf6c979e21b15cdd86ebeb813e1
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
 
    bool winner = false;
   
    Card** board = new Card*[3];
    while( !winner ){
    
    //play bard music
    
    //player plays ( in function pickCard returns a Card pointer)
    int pickedCard = pickCard(  hand,  numCards );
    board[0] = hand[ pickedCard ];//change
    hand[pickedCard] = 0;//remove card from hand
    
    //arrayShift to put zeros at end;
<<<<<<< HEAD
    for(int i = 0; i < HAND_SIZE; i++){
            if( hand[i]==0){
	      hand[i]= hand[i+1]; //swap
	      hand[i+1] = 0;
=======
    for( int i = 0; i < HAND_SIZE; i++ ){
            if(Card** hand[i]==0){
            Card** hand[i]=temp;
            Card** hand[i+1]=Card** hand[i]; //swap
            temp=Card** hand[i+1];
>>>>>>> 51320ad7e67f8cf6c979e21b15cdd86ebeb813e1
            }
    }
    //ai a plays
    a.play_Card( board, 3 );
    //ai b plays
    b.play_Card( board, 3 );
    
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
<<<<<<< HEAD
    cout<<"Play a card.";
    for( int i = 0; i < numCards; i++ ){
      cout << "Choice: " << i << " " << hand[i]->getNumber() << " of " << hand[i]->getSuit() << endl;
    }
    while( !(cin>> choice) ){
      cout << "Bad entry" <<endl;
      
    }
    
  
  
  return choice;
}
=======
for( i=0,i< HAND_SIZE,i++ ){
    cout << "Choice: " <<
    cout << hand[i]->getNumber() << " " << hand[i]->getSuit() << endl;
    cout << "Play a card." ;
    cin >> choice;
    hand[i]->getNumber();
  }
  
  return choice;
}

// Classes not defined
// errors with identifiers
// errors with how coding that is unfamilar is running - program is returning an error stating
// the misuse of certain code requiring certain pointers in  main.cpp \ identifiers need fixed mainly.
>>>>>>> 51320ad7e67f8cf6c979e21b15cdd86ebeb813e1
