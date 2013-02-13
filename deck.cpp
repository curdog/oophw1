#include "card.hpp"
#include "deck.hpp"
#include <cstdlib>

Deck::Deck(){
  deck = new Deck[30];
  char base = '<'
  for( int i = 0; i < 3; i++ ){
    for( int j = 0; j < 10; j++ ){
      deck[i + j] = new Card( j, base + (char)i );
    }
  }
}

~Deck::Deck(){

delete
}

void Deck::shuffle(){
  for( int i = 0; i < 2000; i++ ){
    
  }
}

Card* Deck::getCard(){
  if( index > 29 ){
    return 0;
  }
  return deck[++index];
}
