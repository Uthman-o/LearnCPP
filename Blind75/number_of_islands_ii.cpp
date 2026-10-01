#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class NumberOfIslandsII {
    vector<int> parent, rankv;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if (rankv[a] == rankv[b]) ++rankv[a];
        return true;
    }
public:
    vector<int> numIslands2(int m, int n, const vector<vector<int>>& positions) {
        parent.assign(m*n, -1);
        rankv.assign(m*n, 0);
        vector<int> ans;
        int islands = 0;
        int dirs[5] = {1,0,-1,0,1};
        for (const auto& p : positions) {
            int r = p[0], c = p[1], id = r*n+c;
            if (parent[id] != -1) { ans.push_back(islands); continue; }
            parent[id] = id;
            ++islands;
            for (int d=0; d<4; ++d) {
                int nr=r+dirs[d], nc=c+dirs[d+1];
                if (nr<0||nr>=m||nc<0||nc>=n) continue;
                int nid=nr*n+nc;
                if (parent[nid] != -1 && unite(id,nid)) --islands;
            }
            ans.push_back(islands);
        }
        return ans;
    }
};
int main() {
    NumberOfIslandsII s;
    vector<vector<int>> pos={{0,0},{0,1},{1,2},{2,1},{1,1}};
    assert((s.numIslands2(3,3,pos) == vector<int>{1,1,2,3,1}));
    cout << "Passed\n";
    return 0;
}
