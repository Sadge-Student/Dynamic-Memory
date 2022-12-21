#include "deck.h"
#include <algorithm>
#include <random>

Deck::Deck()
{
	const std::vector<std::string> suits = { "hearts", "spades", "diamonds", "clubs" };

	for (const std::string& suit : suits)
	{
		for (int i = 1; i <= 13; i++)
		{
			Card card(suit, i);
			cards_.push_back(card);
		}
	}
}

Deck::~Deck()
{
	cards_.clear();
}

void Deck::Shuffle()
{
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(cards_), std::end(cards_), rng);
}

std::vector<Card> Deck::Deal(int num)
{
	std::vector<Card> dealt_cards;
	for (int i = 0; i < num; i++)
	{
		dealt_cards.push_back(cards_[i]);
	}
	cards_.erase(cards_.begin(), cards_.begin() + num);
	return dealt_cards;
}

std::vector<Card> Deck::GetDeck() const
{
	return cards_;
}


std::ostream& operator<<(std::ostream& os, const Deck& deck)
{
	for (const Card& card : deck.cards_)
	{
		os << card;
	}
	return os;
}
