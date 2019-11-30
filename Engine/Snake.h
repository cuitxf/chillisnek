#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include "Goal.h"
#include <random>
class Goal;
class Snake
{
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool isBitedSelf() const;
	bool isBitedGoal(const Goal& goal) const;
	bool isOverLap(const Location& otherloc) const;
	int GetLen() const;

private:
	class Segment
	{
	public:
		const Location& GetLocation() const;
		void InitHead(const Location& loc);
		void InitBody(Color c);
		void MoveBy(const Location& delta_loc);
		void Follow(const Segment& next);
		void Draw(Board& brd) const;
	private:
		Location loc;
		Color c;
	};

private:
	static constexpr Color headColor = Colors::Red;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};