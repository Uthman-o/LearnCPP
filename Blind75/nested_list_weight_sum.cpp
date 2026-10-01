#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
   private:
    bool is_integer;
    int value;
    vector<NestedInteger> list;

   public:
    NestedInteger(int x) : is_integer(true), value(x) {}
    NestedInteger(vector<NestedInteger> nestedList)
        : is_integer(false), value(0), list(nestedList) {}

    bool isInteger() const {
        return is_integer;
    }

    int getInteger() const {
        return value;
    }

    const vector<NestedInteger>& getList() const {
        return list;
    }
};

class NestedListWeightSum {
   private:
    int dfs(const vector<NestedInteger>& nestedList, int depth) {
        int total = 0;

        for (const auto& item : nestedList) {
            if (item.isInteger()) {
                total += item.getInteger() * depth;
            } else {
                total += dfs(item.getList(), depth + 1);
            }
        }

        return total;
    }

   public:
    int depthSum(const vector<NestedInteger>& nestedList) {
        return dfs(nestedList, 1);
    }
};

int main() {
    vector<NestedInteger> nestedList = {
        NestedInteger(vector<NestedInteger>{NestedInteger(1), NestedInteger(1)}),
        NestedInteger(2),
        NestedInteger(vector<NestedInteger>{NestedInteger(1), NestedInteger(1)})
    };

    NestedListWeightSum s;
    assert(s.depthSum(nestedList) == 10);

    cout << "Passed\n";
    return 0;
}
