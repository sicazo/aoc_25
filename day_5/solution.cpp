#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Range {
    long long start;
    long long end;
};

vector<Range> mergeRanges(vector<Range> ranges) {
    if (ranges.empty()) return ranges;
    
    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        return a.start < b.start;
    });
    
    vector<Range> merged;
    merged.push_back(ranges[0]);
    
    for (size_t i = 1; i < ranges.size(); i++) {
        Range& last = merged.back();
        Range& current = ranges[i];
        
        if (current.start <= last.end + 1) {
            last.end = max(last.end, current.end);
        } else {
            merged.push_back(current);
        }
    }
    
    return merged;
}

long long countFreshIDs(const vector<Range>& ranges) {
    vector<Range> merged = mergeRanges(ranges);
    
    long long count = 0;
    for (const auto& range : merged) {
        count += (range.end - range.start + 1);
    }
    
    return count;
}

bool isFresh(long long id, const vector<Range>& ranges) {
    for (const auto& range : ranges) {
        if (id >= range.start && id <= range.end) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream file("input");
    
    vector<Range> ranges;
    vector<long long> ingredients;
    string line;
    bool readingRanges = true;
    
    while (getline(file, line)) {
        if (line.empty()) {
            readingRanges = false;
            continue;
        }
        
        if (readingRanges) {
            size_t dashPos = line.find('-');
            if (dashPos != string::npos) {
                long long start = stoll(line.substr(0, dashPos));
                long long end = stoll(line.substr(dashPos + 1));
                ranges.push_back({start, end});
            }
        } else {
            ingredients.push_back(stoll(line));
        }
    }
    
    file.close();
    
    int freshCount = 0;
    for (long long id : ingredients) {
        if (isFresh(id, ranges)) {
            freshCount++;
        }
    }
    
    cout << "Part 1: " << freshCount << endl;
    
    long long totalFreshIDs = countFreshIDs(ranges);
    cout << "Part 2: " << totalFreshIDs << endl;
    
    return 0;
}
