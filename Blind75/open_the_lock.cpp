#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class OpenTheLock {
public:
    int openLock(const vector<string>& deadends, const string& target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        queue<string> q;
        unordered_set<string> seen={"0000"};
        q.push("0000");
        int turns=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string cur=q.front(); q.pop();
                if(cur==target) return turns;
                for(int i=0;i<4;++i){
                    for(int delta:{-1,1}){
                        string next=cur;
                        int d=(cur[i]-'0'+delta+10)%10;
                        next[i]=char('0'+d);
                        if(!dead.count(next) && !seen.count(next)){
                            seen.insert(next); q.push(next);
                        }
                    }
                }
            }
            ++turns;
        }
        return -1;
    }
};
int main(){
    OpenTheLock s;
    vector<string> dead={"0201","0101","0102","1212","2002"};
    assert(s.openLock(dead,"0202")==6);
    cout<<"Passed\n";
    return 0;
}
