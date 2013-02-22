#include "card.hpp"
#include "deck.hpp"
#include <cstdlib>
#include <time.h>


Deck::Deck(){
  DECK_SIZE = 30;
  SUITS = 3;

  deck = new Card*[DECK_SIZE];
  char base = '<';

  for( int i = 0; i < SUITS; i++ ){
    for( int j = 0; j < (DECK_SIZE / SUITS); j++ ){
      deck[i + j] = new  Card( j, base + (char)i );
    }
  }

}

Deck::~Deck(){
  delete[] deck;
}

void Deck::shuffle(){
  srand( time( 0 ) );
 
  for( int i = 0; i < 2000; i++ ){
    swap( deck[rand() % DECK_SIZE ], deck[rand() % DECK_SIZE ] );
  }
  index = 0;
}

Card* Deck::deal(){
  if( index > DECK_SIZE ){
    return 0;
  }  
  //possible bug here, trying
  return deck[index++];
}

void Deck::swap( Card* a, Card* b){
  Card* c;
  c = a;
  a = b;
  b = c;
}
