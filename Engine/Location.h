#pragma once
struct Location
{
	bool operator==(const Location& other) const
	{
		return x == other.x&&y == other.y;
	}
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x;
	int y;
};