#pragma once
#include <ostream>
#include <vector>

#include "card.h"

class Deck
{
	std::vector<Card> cards_;
public:
	Deck();

	~Deck();

	void Shuffle();

	std::vector<Card> Deal(int num);

	std::vector<Card> GetDeck() const;

private:
	friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};
