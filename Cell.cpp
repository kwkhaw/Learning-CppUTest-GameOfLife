#include "Cell.h"
#include <string>

Cell::Cell(void)
: isAlive(false)
, cells(NULL)
{
}

Cell::~Cell(void)
{
}

bool Cell::IsAlive()
{
  return this->isAlive;
}

void Cell::SetNeighbors(Cell* cells)
{
  this->cells = cells;
}

Cell& Cell::BecomeAlive(void)
{
  this->isAlive = true;
  return *this;
}

Cell& Cell::NextTick(void)
{
  int aliveCount = 0;
  for (int i = 0; i < NUMBER_OF_NEIGHBORS; i++)
  {
    if (this->cells[i].IsAlive())
      aliveCount++;
  }

  // Implement Rule #4
  if (aliveCount == 3)
    BecomeAlive();

  // Implement Rule #1 and #3
  if (aliveCount < 2 || aliveCount >= 4)
    BecomeDead();

  // Rule #2: Any live cell with 2 or 3 live neighbors lives on to the next generation.
  // 2 live neighbors: No state change, if the cell is alive, it remains alive for the next generation.
  // 3 live neighbors: Covered by Rule #4.

  return *this;
}

Cell& Cell::BecomeDead()
{
  this->isAlive = false;
  return *this;
}
