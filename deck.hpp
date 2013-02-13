#ifndef DECK_OOP
#define DECK_OOP

#include "card.hpp"

class Deck{
public:
  Deck();
  ~Deck();
  void shuffle();
  Card* getCard();
private:
  Card* deck;
  int index;
};
#endif
