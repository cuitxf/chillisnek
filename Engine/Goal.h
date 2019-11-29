#pragma once
#include "Board.h"
#include "Location.h"
#include "Snake.h"
#include <random>
class Snake;
class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	const Location& GetLocation() const;
	void Draw(Board& brd);
	void ReSpawn(std::mt19937& rng,const Board& brd,const Snake& snake);
private:
	Location loc;
	static constexpr Color c = { 255,255,255 };
};