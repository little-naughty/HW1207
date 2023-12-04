#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct card
{
	const char *face;
	const char *suit;
}card;

void fillDeck(card * const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle(card *const wDeck);
void deal(const card *const wDeck);

int main()
{
	card deck[52];

	const char *face[] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
	const char *suit[] = { "Heart","Diamonds","Clubs","Spades" };

	srand(time(NULL));

	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);

	return 0;
}
void fillDeck(card * const wDeck, const char *wFace[], const char *wSuit[])
{
	for (int x = 0; x < 52; x++)
	{
		wDeck[x].face = wFace[x % 13];
		wDeck[x].suit = wSuit[x / 13];
	}
}
void shuffle(card *const wDeck)
{
	card temp;

	for (int x = 0; x < 52; x++)
	{
		int y = rand() % 52;

		temp = wDeck[x];
		wDeck[x] = wDeck[y];
		wDeck[y] = temp;
	}
}
void deal(const card *const wDeck)
{
	for (int x = 0; x < 52; x++)

	{
		printf("%5s of %-8s%s", wDeck[x].face, wDeck[x].suit, (x + 1) % 4 ? " " : "\n");
	} }