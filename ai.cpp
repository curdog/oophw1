#include "ai.hpp"
#include "card.hpp"

Ai::Ai( int hand_size ){
  size_hand = hand_size;
  hand = new Card[size_hand];
}

Ai::~Ai( ){
  for( int i = 0; i < size_hand; i++ ){
    hand[i] = 0;
  }
  delete hand;
}


Card* Ai::play_Card( const Card** board, int players ){
  if( board == 0 ){
    return 0;
  }
  
  
  Card* highest_suit = hand[0];
  Card* lowest_suit = hand[0];
  Card* lowest_all = hand[0];
  
  
  for( int x=0; x<size_hand; x++){
    if( board[0]->getSuit() == hand[x]->getSuit() ){
      
    }
    
  
  }
}


int recieveDelt( const Card* delt ){
  
}
