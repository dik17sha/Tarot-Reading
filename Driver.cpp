#include <fstream>
#include <iostream>
#include <iomanip>
#include<ctime>

#include "Card.h"

int main() {
  vector<Card> ourDeck;
  Card c;
  int choice;
  string cardEdge = "---------------------";
  string cardMid = "|                   |";
  
  //USER READING SELECTION
  cout << "For generalized reading enter '0' and for personalized  reading "
          "enter '1': ";
  cin >> choice;
  
  //GENERAL READING
  if (choice == 0) {
    ifstream infile;
    infile.open("General.txt");

    while (infile >> c) {
      ourDeck.push_back(c);
    }

    for (int i = 0; i < 3; i++) {
      srand(time(NULL)); // seed rand with current time.
      random_shuffle(ourDeck.begin(), ourDeck.end());
      c.CardsToDraw(ourDeck, 1);
      c.DrawCard(ourDeck);
      cout << endl << endl << endl;
    }
  }
  
  //PERSONALIZED READING
  if (choice == 1) {
    ifstream infile;
    infile.open("Personalized.txt");

    while (infile >> c) {
      ourDeck.push_back(c);
    }

    int shuffleNum = 0;
    cout << "How many times do you want to shuffle the deck? ";
    cin >> shuffleNum;

    for (int i = 0; i < shuffleNum; i++) {
      cout << "Shuffling the deck for " << (i + 1) << " time! " << endl;
      srand(time(NULL)); // seed rand with current time.
      random_shuffle(ourDeck.begin(), ourDeck.end());
    }

    cout << "5 Cards Have Been Drawn After Shuffling the Deck " << shuffleNum << " Times" 
      << endl;

    //Card Display Output
    for (int i = 1; i < 6; i++) {
        cout << cardEdge << "\t";
    }
    cout << endl;
    for (int i = 1; i < 6; i++) {
        cout << "|" << i << setw(19) << "|" << "\t";
    }
    cout << endl;
    for (int i = 1; i < 14; i ++) {
        for(int j = 1; j < 6; j++)
            cout << cardMid << "\t";
        cout << endl;
    }
    for (int i = 1; i < 6; i++) {
        cout << "|" << setw(19) << i << "| " << "\t";
    }
    cout << endl;
    for (int i = 1; i < 6; i++) {
        cout << cardEdge << "\t";
    }
    cout << endl << endl;

    cout << "Pick 3 Cards to Recieve Your Reading! (Choose From [1, 2, 3, 4, 5]) " << endl
      << endl;
    //Read in card selection
    int card1, card2, card3;
    cin >> card1 >> card2 >> card3;
    cout << endl << endl;
    //Output cards
    cout << "FIRST CARD:" << endl << ourDeck.at(card1) << endl;
    cout << "SECOND CARD:" << endl << ourDeck.at(card2) << endl;
    cout << "THIRD CARD:" << endl << ourDeck.at(card3) << endl;
    
    return 0;
  }
}
