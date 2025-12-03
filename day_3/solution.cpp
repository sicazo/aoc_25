#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void part_1() {
  ifstream file("input");
  string line;
  long long solution = 0;

  while (getline(file, line)) {
    int best = 0;

    for (int i = 0; i < (int)line.size(); i++) {
      int a = line[i] - '0';
      for (int j = i + 1; j < (int)line.size(); j++) {
        int b = line[j] - '0';

        int value = a * 10 + b;
        if (value > best)
          best = value;
      }
    }

    solution += best;
  }

  cout << "Part 1: " << solution << endl;
}
string best_subsequence(const string &s, int k) {
  string result;
  int n = s.size();
  int start = 0;

  for (int choose = 0; choose < k; choose++) {
    int max_digit = -1;
    int max_pos = start;

    int end = n - (k - choose);

    for (int i = start; i <= end; i++) {
      int d = s[i] - '0';
      if (d > max_digit) {
        max_digit = d;
        max_pos = i;
      }
    }

    result.push_back(s[max_pos]);
    start = max_pos + 1;
  }

  return result;
}
void part_2() {
  string line;
  int k = 12;
  uint_fast64_t solutione = 0;
  ifstream file("input");

  while (getline(file, line)) {
    string best = best_subsequence(line, k);
    solutione += stoll(best);
  }

  cout << "Part 2: " << solutione << endl;
}
int main() {
  part_1();
  part_2();
}
