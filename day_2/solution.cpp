#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

vector<string> split(const std::string &str, char delimiter) {
  vector<string> tokens;
  stringstream ss(str);
  string item;

  while (getline(ss, item, delimiter)) {
    tokens.push_back(item);
  }

  return tokens;
}

size_t countUniqueChars(const string &s) {
  unordered_set<char> unique;
  for (char c : s) {
    unique.insert(c);
  }

  return unique.size();
}

void part_1() {
  ifstream file("input");
  // ifstream file("input.test");
  ostringstream ss;
  ss << file.rdbuf();
  vector<std::string> parts = split(ss.str(), ',');
  long long solution = 0;
  for (const string &item : parts) {
    vector<string> numbers = split(item, '-');
    long long a = stoll(numbers[0]);
    long long b = stoll(numbers[1]);
    for (long long x = a; x <= b; x++) {
      string temp = to_string(x);
      int length = temp.length();
      if (length % 2 == 0) {
        string left = temp.substr(0, (length / 2));
        string right = temp.substr((length / 2), length - 1);

        if (left == right) {
          solution += x;
        }
      }
    }
  }
  cout << "part_1: " << solution << endl;
}
bool isRepeated(const string &s) {
  string doubled = s + s;
  string chopped = doubled.substr(1, doubled.size() - 2);
  return chopped.find(s) != std::string::npos;
}

void part_2() {
  ifstream file("input");
  // ifstream file("input.test");

  long long solution = 0;

  string line;
  while (getline(file, line, ',')) {
    vector<string> numbers = split(line, '-');
    long long a = stoll(numbers[0]);
    long long b = stoll(numbers[1]);

    for (long long x = a; x <= b; x++) {
      string s = to_string(x);
      if (isRepeated(s)) {
        solution += x;
      }
    }
  }

  cout << "part_2: " << solution << endl;
}

int main() {
  part_1();
  part_2();
}
