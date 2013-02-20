#ifndef _AI
#define _AI

#include "card.hpp"

class Ai {
public:
  Ai( int hand_size );
  ~Ai();
  Card* play_Card( const Card* );
  int recieveDelt( const Card* );

private:
  Card* hand;
  int size_hand;  
};

#endif
