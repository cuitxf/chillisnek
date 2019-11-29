#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& gfx);
	int GetWidth() const;
	int GetHeight() const;
	void DrawCell(const Location& loc, Color c);
	bool isInsideGrid(const Location& loc) const;
	void DrawBoundry() const;
private:
	static constexpr int dimension = 20;
	static constexpr int width = 30, height = 25;
	Graphics& gfx;
};