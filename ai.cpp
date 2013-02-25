#include "ai.hpp"
#include "card.hpp"

Ai::Ai( int hand_size ){
  size_hand = 0;
  max_hand_size = 10;
  hand = new Card*[max_hand_size];
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
  
  
  int highest_suit = -1;
  int lowest_suit = -1;
  int lowest_all = 0;
  
	Card* returnMeTemp = 0;
	
	//always first card played has suit
  Card* highest_board_card = board[0];

  
  for( int i =i; i<players; i++){
    if( board[i] == 0 ) continue;
    
    if( board[i]->getNumber() > highest_board_card->getNumber() &&
			 highest_board_card->getSuit() == board[i]->getSuit() ){
			
			highest_board_card = board[i];
    }
  }

  //find a card to play
  for( int x=0; x<size_hand; x++){
   
    //highest then return it immediately
    if( highest_board_card->getSuit() == hand[x]->getSuit() && highest_board_card->getNumber() < hand[x]->getNumber() ){
      returnMeTemp = hand[x];
			hand[x] = 0;
			//array shift
			arrayShift();
			return returnMeTemp;
    }
		//finding lowest suit in case
    if ( highest_board_card->getSuit() == hand[x]->getSuit() && hand[x]->getNumber() < highest_board_card->getNumber() ) {
			if( lowest_suit == -1 ){
				lowest_suit = x;
				
			} else if (hand[lowest_suit]->getNumber() < hand[x]->getNumber()) {
		
				lowest_suit = x;
			}
		}
		//finding lowest overall
		if( hand[lowest_all]->getNumber() < hand[x]->getNumber() ){
			lowest_all = x;
		}

  
  }
	//retrun lowest suit first if there
	if ( lowest_suit != -1) {
		returnMeTemp = hand[lowest_suit ];
		hand[lowest_suit] = 0;
		arrayShift();
		return returnMeTemp;
	}
	//return lowest over all
	returnMeTemp = hand[lowest_all ];
	hand[lowest_all] = 0;
	arrayShift();
	return returnMeTemp;
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

//arrayShift to put zeros at end;
//minus one to prevent overflow also doesn't matter if there is a zero already at end
void Ai::arrayShift() {
	for(int i = 0; i < max_hand_size - 1; i++){
		if( hand[i]==0){
			hand[i]= hand[i+1]; //swap
			hand[i+1] = 0;
		}
	}
}


