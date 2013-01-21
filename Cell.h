class Cell
{
public:
  Cell(void);
  ~Cell(void);
  bool IsAlive();
  void SetNeighbors(Cell* cells);
  Cell& BecomeAlive();
  Cell& BecomeDead();
  Cell& NextTick(void);
private:
  static const int NUMBER_OF_NEIGHBORS = 8;
  Cell* cells;
  bool isAlive;
};

