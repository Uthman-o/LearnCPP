#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::vector;

int main() {
    vector<pair<double, string>> grades;

    grades.push_back({3.56, "James"});
    grades.emplace_back(3.88, "Lily");
    grades.emplace_back(3.47, "Severus");
    grades.emplace_back(2.56, "Goyle");
    grades.emplace_back(2.56, "Crabb");

    sort(grades.begin(), grades.end());

    for (const auto& [gpa, name] : grades) {
        cout << gpa << " " << name << endl;
    }

    return 0;
}
