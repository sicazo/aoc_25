#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
  ifstream file("input");
  string line;

  int location = 50;
  long long one = 0; // Part 1
  long long two = 0; // Part 2

  while (getline(file, line)) {
    if (line.empty())
      continue;

    char dir = line[0];                // 'L' oder 'R'
    int amount = stoi(line.substr(1)); // der Zahlenwert

    int start = location;

    if (dir == 'R') {
      location += amount;
    } else { // 'L'
      start = (100 - start) % 100;
      location -= amount;
    }

    int range_modulo = amount % 100;
    two += (start + range_modulo) / 100 + amount / 100;

    location = (location % 100 + 100) % 100;

    if (location == 0) {
      one++;
    }
  }

  cout << one << endl; // Part 1 → 1145
  cout << two << endl; // Part 2 → richtige Antwort

  return 0;
}
