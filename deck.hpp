#ifndef DECK_OOP
#define DECK_OOP

#include "card.hpp"

class Deck{
public:
  Deck();
  ~Deck();
  void shuffle();
  Card* deal( );
private:
  void swap( Card*, Card* ); //internal helper function
  Card** deck; //array of pointers to Cards
  int index; // for dealing purposes
  int DECK_SIZE; //tempting to put as a define
  int SUITS;
};
#endif
