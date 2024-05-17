#include "Card.h"

// default constructor to initialize CardName and CardDescription to empty
// strings.
Card::Card() {
  CardName = " ";
  CardDescription = " ";
}

// overloaded constructor to assign values to CardName and CardDescription.
Card::Card(string name, string description) {
  CardName = name;
  CardDescription = description;
}

// function to draw a card from the deck.
Card Card::DrawCard(vector<Card> Deck) {
  // if Deck is empty, return an empty card object.
  if (Deck.empty()) {
    return Card(" ", " ");
  }
  // assign the last card in deck to 'temp' and remove it from deck.
  Card temp = Deck.back();
  Deck.pop_back();
  return temp;
}

void Card::CardsToDraw(vector<Card> Deck, int NumCards) {
  for (int i = 0; i < NumCards; i++) {
    if (Deck.empty()) { // if there are no more cards in deck, display error
                        // message and break loop.
      cout << "No more cards in deck\n";
      break;
    }
    Card drawn_card = DrawCard(Deck); // draw a card.
    cout << drawn_card.CardName << ": " << drawn_card.CardDescription
         << endl; // print card's name and description.
  }
}

istream &operator>>(istream &in, Card &c) {
  getline(in, c.CardName);
  getline(in, c.CardDescription);
  return in;
}

ostream &operator<<(ostream &out, const Card &c) {
  out << c.CardName << endl;
  out << c.CardDescription << endl;
  return out;
}
