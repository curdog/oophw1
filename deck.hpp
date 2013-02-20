#ifndef DECK_OOP
#define DECK_OOP

#include "card.hpp"

class Deck{
public:
  Deck();
  ~Deck();
  void shuffle();
  Card* deal( int cards = 1);
private:
  void swap( Card*, Card* ); //internal helper function
  Card* deck;
  int index; // for dealing purposes
  const int DECK_SIZE = 30; //tempting to put as a define
  const int SUITS = 3;
};
#endif
