#include <cassert>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
class IPToCIDR {
    uint32_t toInt(const string& ip) {
        stringstream ss(ip);
        string part;
        uint32_t x = 0;
        while (getline(ss, part, '.')) x = (x << 8) | stoul(part);
        return x;
    }
    string toBlock(uint32_t ip, int prefix) {
        return to_string((ip>>24)&255) + "." + to_string((ip>>16)&255) + "." +
               to_string((ip>>8)&255) + "." + to_string(ip&255) + "/" + to_string(prefix);
    }
public:
    vector<string> ipToCIDR(string ip, int n) {
        uint32_t cur = toInt(ip);
        vector<string> ans;
        while (n > 0) {
            uint64_t lowbit = cur == 0 ? (1ULL<<32) : (uint64_t)(cur & -cur);
            uint64_t block = lowbit;
            while (block > (uint64_t)n) block >>= 1;
            int bits = 0;
            uint64_t t = block;
            while (t > 1) { ++bits; t >>= 1; }
            ans.push_back(toBlock(cur, 32 - bits));
            cur += (uint32_t)block;
            n -= (int)block;
        }
        return ans;
    }
};
int main() {
    IPToCIDR s;
    vector<string> expected={"255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"};
    assert(s.ipToCIDR("255.0.0.7",10)==expected);
    cout << "Passed\n";
    return 0;
}
