#include <CppUTest/TestHarness.h>
#include "Cell.h"

/*
Rules for Game of Life
The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells,
each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbours,
which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overcrowding.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

The initial pattern constitutes the seed of the system.
The first generation is created by applying the above rules simultaneously to every cell in the seed—births and deaths occur simultaneously,
and the discrete moment at which this happens is sometimes called a tick
(in other words, each generation is a pure function of the preceding one).
The rules continue to be applied repeatedly to create further generations.
*/
TEST_GROUP(CellTest) {
  Cell cells[8];
  Cell cell;
  void setup() {
    cell.SetNeighbors(cells);
  }
  void teardown() {

  }
};

TEST(CellTest, TestCellInitialStateIsNotAlive) {
  CHECK_FALSE(cell.IsAlive());
}

// Implement Rule #4 first, turn a dead cell to become alive.
TEST(CellTest, TestCellWithThreeLiveNeighborsBecomeAlive) {
  // Three neighbors are alive.
  cells[0].BecomeAlive();
  cells[1].BecomeAlive();
  cells[2].BecomeAlive();

  CHECK_TRUE(cell.NextTick().IsAlive());
}

// Implement Rule #1, 0 live neighbor, the cell become dead.
TEST(CellTest, TestAliveCellWithZeroNeighborsDies) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.

  CHECK_FALSE(cell.NextTick().IsAlive());
}

// Implement Rule #1, 1 live neighbor, the cell become dead.
TEST(CellTest, TestAliveCellWithOneNeighborsDies) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.
  cells[0].BecomeAlive();

  CHECK_FALSE(cell.NextTick().IsAlive());
}

// Implement Rule #2, 2 live neighbors, lives on to the next generation.
TEST(CellTest, TestAliveCellWithTwoNeighborsRemainsAlive) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.
  cells[0].BecomeAlive();
  cells[1].BecomeAlive();

  CHECK_TRUE(cell.NextTick().IsAlive());
}

// Implement Rule #2, 3 live neighbors, lives on to the next generation.
TEST(CellTest, TestAliveCellWithThreeNeighborsRemainsAlive) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.
  cells[0].BecomeAlive();
  cells[1].BecomeAlive();
  cells[2].BecomeAlive();

  CHECK_TRUE(cell.NextTick().IsAlive());
}

// Implement Rule #3, 4 live neighbors, become dead.
TEST(CellTest, TestAliveCellWithFourNeighborsDies) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.
  cells[0].BecomeAlive();
  cells[1].BecomeAlive();
  cells[2].BecomeAlive();
  cells[4].BecomeAlive();

  CHECK_FALSE(cell.NextTick().IsAlive());
}

// Implement Rule #3, more than 4 live neighbors, become dead.
TEST(CellTest, TestAliveCellWithMoreThanFourNeighborsDies) {
  cell.BecomeAlive(); // Set it to be alive in the beginning.
  cells[0].BecomeAlive();
  cells[1].BecomeAlive();
  cells[2].BecomeAlive();
  cells[4].BecomeAlive();
  cells[5].BecomeAlive();
  cells[6].BecomeAlive();
  cells[7].BecomeAlive();

  CHECK_FALSE(cell.NextTick().IsAlive());
}
