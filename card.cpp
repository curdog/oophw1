#include "card.hpp"

Card::Card( int card_num, char card_suit ){
  number = card_num;
  suit = card_suit;
}

int Card::getNumber() const{
  return number;
}

char Card::getSuit() const{
  return suit;
}
