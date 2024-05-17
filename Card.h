#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card {
  string CardName;
  string CardDescription;
  vector<Card> Deck;

public:
  Card();
  Card(string, string);
  Card DrawCard(vector<Card> Deck);
  void CardsToDraw(vector<Card> Deck, int);
  friend istream &operator>>(istream &in, Card &c);
  friend ostream &operator<<(ostream &out, const Card &c);
};

#endif
