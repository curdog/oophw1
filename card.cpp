#include "card.hpp"

Card::Card( int card_num, char card_suit ){
  const_cast<int>(number) = card_num;
  const_cast<char>(suit) = card_suit;5D
}

int Card::getNumber() const{
  return number;
}

char Card::getSuit() const{
  return suit;
}
