#include "Goal.h"


Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	ReSpawn(rng, brd, snake);
}

const Location & Goal::GetLocation() const
{
	return loc;
}

void Goal::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
}

void Goal::ReSpawn(std::mt19937 & rng, const Board & brd, const Snake & snake)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetHeight() - 1);
	Location temp;
	do
	{
		temp.x = xDist(rng);
		temp.y = yDist(rng);
	} while (snake.isOverLap(temp));
	loc = temp;
}
