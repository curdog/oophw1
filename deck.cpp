#include "card.hpp"
#include "deck.hpp"
#include <cstdlib>
#include <time.h>

#include <iostream>

Deck::Deck(){
  DECK_SIZE = 30;
  SUITS = 3;

	index = 0;
	
  deck = new Card*[DECK_SIZE];
  char base = '<';
	int total_index = 0;
  for( int i = 0; i < SUITS; i++){
    for( int j = 0; j < (DECK_SIZE / SUITS); j++ ){
      deck[total_index] = new  Card( j, base + (char)i );
			total_index++;
			
    }
  }

}

Deck::~Deck(){
  delete[] deck;
}

void Deck::shuffle(){
  srand( time( 0 ) );
  for( int i = 0; i < 20; i++ ){
    swap( rand() % DECK_SIZE, rand() % DECK_SIZE  );
  }
  index = 0;
}

Card* Deck::deal(){
  if( index > DECK_SIZE ){
		std::cout << "Should not be here" << std::endl;
    return 0;
  }  
  index++;
  std::cout << "dealing card" << index << std::endl;
	std::cout << deck[index-1]->getSuit() << " " << deck[index -1]->getNumber() << std::endl;
  return deck[index-1];
}

void Deck::swap( int a, int b){
  Card* c;
	c = deck[a];
  deck[a] = deck[b];
  deck[b] = c;
}
