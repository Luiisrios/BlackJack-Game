// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>


using namespace std;
void print(string message, int card_value)
{
	cout << message;
	if (card_value == 21)
	{
		cout << "Jack\n";
	}
	else if (card_value == 32)
	{
		cout << "Queen\n";
	}
	else if (card_value == 43)
	{
		cout << "king\n";
	}
	else if (card_value == 1)
	{
		cout << "Ace count as 1\n";
	}
	else if (card_value == 11)
	{
		cout << "Ace count as 11\n";
	}
	else
	{
		cout << card_value << endl;;
	}
	

}
void suffle(int card_value[], int length)
{
	int temp = 0;
	int randome_index = rand() % length;

	for (int i = 0; i < length; i++)
	{
		randome_index = rand() % length;
		temp = card_value[i];
		card_value[i] = card_value[randome_index];
		card_value[randome_index] = temp;
	}
}
void suffle_string(string suits[], int length)
{
	string temp;
	int randome_index = rand() % length;

	for ( int i = 0; i < length; i++)
	{
		randome_index = rand() % length;
		temp = suits[i];
		suits[i] = suits[randome_index];
		suits[randome_index] = temp;
	}
}



int main()
{
	int card_total= 0, jack = 21, q = 32, king = 43, ace = 1;
	char first_hit;
	char hit_stick;
	int dealer_hand_total = 0;
	int card;
	srand(time(NULL));

	
	vector <int> deck; // we can add, and remove index(card)
	
	int card_value[13] =
	{
		1, 2, 3, 4, 5, 6, 7,
		8, 9, 10, jack, q, king
	};
	for (int suits = 0; suits < 4; suits++) // each of the 13 card x 4 to make 52 cards
	{
		
		for (int i = 0; i < 13; i++)
		{
			deck.push_back(card_value[i]); // takes one argument and pushes it back
											// pushes back each element of card value
		}
	}
	

	/*string suits[4] =
	{
		"Spades", "Clubs", "Diamonds", "Heart"
	};*/
	//suffle(card_value, 13);
	//suffle_string(suits, 4);
	
	cout << "Welcome to the Black Jack Table" << endl;
	cout << "_______________________________" << endl;
	cout << endl;
	cout << "Press 'Y' to get your first two cards or 'X' to exit 'T' for test mode" << endl;
	cin >> first_hit;
	if (cin.fail())
	{
		cout << "not a valid input";
		return 0;
	
	}
	first_hit = toupper(first_hit);
	if(first_hit == 'X')
	{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "No game today" << endl;
			return 0;
	}
	if (first_hit == 'T')
	{
		int player_card = -1;
		int dealer_card = -1;
		cout << "Enter your cards (enter 0 to enter delaer cards): ";
		while (player_card != 0)
		{


			cin >> player_card;
			card_total += player_card;
		}
		cout << "Enter dealer cards (enter 0 to stop): ";
		while (dealer_card != 0)
		{


			cin >> dealer_card;
			dealer_hand_total += dealer_card;

		}
		if (card_total > 21)
		{
			cout << "you busted\n";
		}
		else if (dealer_hand_total > 21)
		{
			cout << "dealer busted\n";
		}
		else if (card_total > dealer_hand_total)
		{
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "you won " << endl;

		}
		else if (card_total == dealer_hand_total)
		{
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "it a draw" << endl;
		}
		else if (card_total < dealer_hand_total)
		{
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "Bust!!! you lost" << endl;
		}
		return 0;
	}
	
	if (first_hit == 'Y')
	{
		cout << "\t Your Cards" << endl;
		
	}

	else
	{
		cout << "not a valid input" << endl;
		return 0;
		
	}
	
	/*switch (card_value[13])
	{
	case '1':
		cout << card_value[1] << " Ace";
		break;
	case '2':
		cout << card_value[2] << " Two";
		break;
	case '3':
		cout << card_value[3] << " Three";
		break;
	case '4':
		cout << card_value[4] << " Four";
		break;
	case '5':
		cout << card_value[5] << " Five";
		break;
	case '6':
		cout << card_value[6] << " Six";
		break;
	case '7':
		cout << card_value[7] << " Seven";
		break;
	case '8':
		cout << card_value[8] << " Eight";
		break;
	case '9':
		cout << card_value[9] << " Nine";
		break;
	case '10':
		cout << card_value[10] << " Ten";
		cout << "switch worked";
		break;
	case 'jack':
		cout << card_value[11] << " Jack";
		cout << "switch worked";
		break;
	case 'q':
		cout << card_value[12] << " Queen";
		cout << "switch worked";
		break;
	case 'king':
		cout << card_value[13] << " King";
		cout << "switch worked";
		break;

	}*/

	card = rand() % deck.size();
	print("Your card is: ", deck[card]);
	if (deck[card] == 1)
	{
		if (card_total + 11 > 21)
		{
			card_total += 1;

		}
		else
		{
			card_total += 11;
		}
	}
	else
	{
		card_total += deck[card] % 11; // add the card
	}
	deck.erase(card + deck.begin());// erase card chosen can no longer go back in deck
	card = rand() % deck.size();
	print("Your card is: ", deck[card]);
	if (deck[card] == 1)
	{
		if (card_total + 11 > 21)
		{
			card_total += 1;

		}
		else
		{
			card_total += 11;
		}
	}
	else
	{
		card_total += deck[card] % 11;
	}
	deck.erase(card + deck.begin());
	cout << "Card Total: " << card_total << endl;
	
	cout << "\t Dealer hand " << endl;
	card = rand() % deck.size();
	if (deck[card] == 1)
	{
		if (dealer_hand_total + 11 > 21)
		{
			dealer_hand_total += 1;

		}
		else
		{
			dealer_hand_total += 11;
		}
	}
	else
	{
		dealer_hand_total += deck[card] % 11;
	}
	deck.erase(card + deck.begin());
	card = rand() % deck.size();
	print("Dealer Card: ", deck[card]);
	if (deck[card] == 1)
	{
		if (dealer_hand_total + 11 > 21)
		{
			dealer_hand_total += 1;

		}
		else
		{
			dealer_hand_total += 11;
		}
	}
	else
	{
		dealer_hand_total += deck[card] % 11;
	}
	deck.erase(card + deck.begin());

	cout << "Dealer Card: ****" << endl;
	if (card_total == 21)
	{
		if (dealer_hand_total == 21)
		{
			cout << "Draw" << endl;
		}
		else
		{
			cout << "You won with blackjack\n";

		}
		return 0;
	}
	else if (dealer_hand_total == 21)
	{
		cout << "Bust dealer got blackjack\n";
		return 0;
	}


	/*if (card_total >= 21)
	{
		cout << "sorry you lost" << endl;
		cin.clear();
		cin.ignore(80, '\n');
	}*/
	while (true)
	{

	
		cout << "Hit (H) or tick(S)" << endl;
		cin >> hit_stick;
		hit_stick = toupper(hit_stick);
		if (hit_stick == 'H')
		{
			card = rand() % deck.size();
			print("Your card is: ", deck[card]);
			if (deck[card] == 1)
			{
				if (card_total + 11 > 21)
				{
					card_total += 1;

				}
				else
				{
					card_total += 11;
				}
			}
			else
			{
				card_total += deck[card] % 11;
			}
			deck.erase(card + deck.begin());
			cout << "your card total: " << card_total << endl;

			if (card_total > 21)
			{
				cout << "you lose" << endl;
				return 0;
			}


		}

		else if (hit_stick == 'S')
		{

			break;
		}
		else
		{
			cout << "Not a valid input Try again..\n";
		}
		
	}
	while (dealer_hand_total < 17)
	{
		
		card = rand() % deck.size();
		if (deck[card] == 1)
		{
			if (dealer_hand_total + 11 > 21)
			{
				dealer_hand_total += 1;

			}
			else
			{
				dealer_hand_total += 11;
			}
		}
		else
		{
			dealer_hand_total += deck[card] % 11;
		}
		print("Dealer card is: ", deck[card]);
		deck.erase(card + deck.begin());

		if (dealer_hand_total > 21)
		{
			cout << "Dealer lose" << endl;
			return 0;
		}
	}
	if (card_total > dealer_hand_total)
	{
		cout << "dealer had " << dealer_hand_total << endl;
		cout << "you had " << card_total << endl;
		cout << "you won " << endl;

	}
	else if (card_total == dealer_hand_total)
	{
		cout << "dealer had " << dealer_hand_total << endl;
		cout << "you had " << card_total << endl;
		cout << "it a draw" << endl;
	}
	else if (card_total < dealer_hand_total)
	{
		cout << "dealer had " << dealer_hand_total << endl;
		cout << "you had " << card_total << endl;
		cout << "Bust!!! you lost" << endl;
	}
	return 0;
		//cout << "your card: " << card_value[5] << " " << suits[1]  << endl;
		//cout << "Hit (H) or stick(S)" << endl;
		//cin >> hit_stick;
	
	/*while (hit_stick == 'S')
	{
		if (card_total > dealer_hand_total)
		{ 
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "you won " << endl;

		}
		else if (card_total == dealer_hand_total)
		{
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "BUST it a draw" << endl;
		}
		else if (card_total < dealer_hand_total)
		{
			cout << "dealer had " << dealer_hand_total << endl;
			cout << "you had " << card_total << endl;
			cout << "you lost" << endl;
		}
	}*/



}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
