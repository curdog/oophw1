#ifndef CARD_HW1
#define CARD_HW1

class Card{
public:
	//takes the value and suit of card
  Card(int, char);
  int getNumber() const;
  char getSuit() const;
private:
  int number;
  char suit;

};

#endif
