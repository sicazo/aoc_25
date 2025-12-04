#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printGrid(const vector<vector<char>> &grid) {
  for (const auto &row : grid) {
    for (char c : row) {
      cout << c;
    }
    cout << "\n";
  }
}

int countAdjacentRolls(const vector<vector<char>> &grid, int row, int col) {
  int count = 0;
  int rows = grid.size();
  int cols = grid[0].size();

  for (int dr = -1; dr <= 1; dr++) {
    for (int dc = -1; dc <= 1; dc++) {
      if (dr == 0 && dc == 0)
        continue;

      int newRow = row + dr;
      int newCol = col + dc;

      if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
        if (grid[newRow][newCol] == '@') {
          count++;
        }
      }
    }
  }

  return count;
}

void part_1() {
  ifstream file("input");
  long long solution = 0;
  string line;
  vector<vector<char>> grid;

  while (getline(file, line)) {
    vector<char> layer(line.begin(), line.end());
    grid.push_back(layer);
  }

  int rows = grid.size();
  int cols = grid[0].size();

  cout << "Grid (" << rows << "x" << cols << "):\n";
  printGrid(grid);
  cout << "\n";

  vector<vector<char>> visualGrid = grid;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (grid[r][c] == '@') {
        int adjacentRolls = countAdjacentRolls(grid, r, c);
        if (adjacentRolls < 4) {
          solution++;
          visualGrid[r][c] = 'x';
        }
      }
    }
  }

  cout << "part_1: " << solution << endl;
}

void part_2() {
  ifstream file("input");
  long long solution = 0;
  string line;
  vector<vector<char>> grid;

  while (getline(file, line)) {
    vector<char> layer(line.begin(), line.end());
    grid.push_back(layer);
  }

  int rows = grid.size();
  int cols = grid[0].size();

  bool changed = true;
  int iteration = 0;

  while (changed) {
    changed = false;
    iteration++;
    vector<pair<int, int>> toRemove;

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == '@') {
          int adjacentRolls = countAdjacentRolls(grid, r, c);
          if (adjacentRolls < 4) {
            toRemove.push_back({r, c});
            changed = true;
          }
        }
      }
    }

    for (auto [r, c] : toRemove) {
      grid[r][c] = '.';
      solution++;
    }
  }

  cout << "part_2: " << solution << endl;
}

int main() {
  // part_1();
  part_2();
  return 0;
}
