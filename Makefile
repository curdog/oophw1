all: game

game: main.cpp deck.o card.o
	g++ main.cpp deck.o card.o -o game


deck.o: deck.cpp deck.hpp card.o
	g++ -c deck.cpp deck.hpp

card.o: card.hpp card.cpp
	g++ -c card.hpp card.cpp