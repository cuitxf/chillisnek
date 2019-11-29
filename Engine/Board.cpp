#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}

void Board::DrawCell(const Location & loc, Color c)
{
	gfx.DrawRectDim(loc.x*dimension+2, loc.y*dimension+2, dimension-4, dimension-4, c);
}

bool Board::isInsideGrid(const Location & loc) const
{
	return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height;
}

void Board::DrawBoundry() const
{
	gfx.DrawRect(width*dimension, 0, width*dimension + 10, height*dimension,Colors::LightGray);
	gfx.DrawRect(0, height*dimension, width*dimension + 10, height*dimension+10,Colors::LightGray);
}
