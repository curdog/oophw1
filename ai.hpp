#ifndef _AI
#define _AI

#include "card.hpp"

class Ai {
public:
  Ai( int );
  ~Ai();
  Card* play_Card( const Card**, int );
  int recieveDelt( const Card* );
  int makeBid();

private:
  Card** hand;
  int size_hand;
  int max_hand_size;
};

#endif
