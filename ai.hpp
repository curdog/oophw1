#ifndef _AI
#define _AI

#include "card.hpp"

class Ai {
public:
	//takes the hand size
  Ai( int );
  ~Ai();
	//takes the board of cards and the number of players, returns the card to be played
  Card* play_Card(  Card**, int );
	//takes the card and stores it in the ai's hand
	int recieveDelt(  Card* );
  //makes a bid of tricks maybe to make
	int makeBid();

private:
	void arrayShift(); //helper function
  Card** hand;
  int size_hand;
  int max_hand_size;
};

#endif
