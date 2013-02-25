#include "ai.hpp"
#include "card.hpp"

Ai::Ai( int hand_size ){
  size_hand = 0;
  max_hand_size = 10;
  hand = new Card*[size_hand];
}

Ai::~Ai( ){
  for( int i = 0; i < size_hand; i++ ){
    hand[i] = 0;
  }
  delete hand;
}


Card* Ai::play_Card(  Card** board, int players ){
  if( board == 0 | players < 0 ){
    return 0;
  }
  
  
  Card* highest_suit = hand[0];
  Card* lowest_suit = hand[0];
  Card* lowest_all = hand[0];
  
  Card* highest_board_card = board[0];

  //if h
  for( int i =i; i<players; i++){
    if( board[i] == 0 ) continue;
    
    if( board[i]->getNumber() > highest_board_card->getNumber() &&
	highest_board_card->getSuit() == board[i]->getSuit() ){
      
    }
  }

  
  for( int x=0; x<size_hand; x++){
   
    
    if( board[0]->getSuit() == hand[x]->getSuit() ){
      
    }
    
  
  }
}


int Ai::recieveDelt( Card* delt ){
  if( size_hand > max_hand_size )
    return -1;
  hand[size_hand] = delt;
  size_hand++;
  return 0;
}

int Ai::makeBid( ){
  int bid = 0;
  //8 9 10 are good cards to count for a bid
  for( int i = 0; i < size_hand; i++ ){
    if( hand[i]->getNumber() > 7 ){
      bid++;
    }
  }
  return bid;
}
