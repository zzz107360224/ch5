#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wface[], const char *wsuit[]);
int main(void)
{
	const char *suit[4] = { "hears","diamonds","clubs","spades" };

	const char *face[13] = { "ace","deuce","three","four","five","six","seven","eight","nine","ten","jack","queen","king" };
	int deck[4][13] = { 0 };
	srand(time(0));
	shuffle(deck);
	deal(deck, face, suit);
	system("pause");
	return 0;






}
void shuffle(int wDeck[][13])
{
	int row;
	int column;
	int card;
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column]!=0);
		wDeck[row][column] = card;
	}



}
void deal(const int wDeck[][13], const char *wface[], const char *wsuit[])
{
	int card;
	int row;
	int column;
	for (card = 1; card < 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wface[column], wsuit[row], card % 2 == 0 ? '\n' : '\t');

				}
			}
		}
	}



}