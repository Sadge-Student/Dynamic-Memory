#include "card.h"
#include <ostream>

std::string Card::GetSuit() const
{
	return suit_;
}

int Card::GetValue() const
{
	return value_;
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << card.GetValue() << " of " << card.GetSuit() << std::endl;
	return os;
}
