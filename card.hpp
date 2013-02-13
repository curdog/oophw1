#ifndef CARD_HW1
#define CARD_HW1

class Card{
public:
  Card(int, char);
  int getNumber() const;
  char getSuit() const;
private:
  const int number;
  const char suit;

};

#endif
