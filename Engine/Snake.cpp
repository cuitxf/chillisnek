#include "Snake.h"
#include "Goal.h"
Snake::Snake(const Location & loc)
{
	constexpr int n = 3;
	constexpr Color greenc[n] = {
		{10,100,32},
		{10,130,48},
		{18,160,48}
	};
	for (int i = 1; i < nSegmentsMax; i++)
	{
		segments[i].InitBody(greenc[i % n]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location ret(segments[0].GetLocation());
	ret.Add(delta_loc);
	return ret;
}

bool Snake::isBitedSelf() const
{
	for (int i = 1; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == segments[0].GetLocation())
		{
			return true;
		}
	}
	return false;
}

bool Snake::isBitedGoal(const Goal & goal) const
{
	return segments[0].GetLocation() == goal.GetLocation();
}

bool Snake::isOverLap(const Location& otherloc) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == otherloc)
		{
			return true;
		}
	}
	return false;
}

int Snake::GetLen() const
{
	return nSegments;
}



const Location& Snake::Segment::GetLocation() const
{
	return loc;
}

void Snake::Segment::InitHead(const Location & otherloc)
{
	loc = otherloc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(Color otherc)
{
	c = otherc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	loc.Add(delta_loc);
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}
