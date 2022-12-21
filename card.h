#pragma once
#include <string>
#include <utility>

class Card
{
public:
	Card(std::string suit, int value) : suit_(std::move(suit)), value_(value) {}

	std::string GetSuit() const;

	int GetValue() const;

private:
	std::string suit_;
	int value_;

	friend std::ostream& operator<<(std::ostream& os, const Card& card);
};
