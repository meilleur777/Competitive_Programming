#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    vector<int> attack(1e3+1, 0);
    int last=0;
    for (auto v:attacks) {
        last=max(last, v[0]);
        attack[v[0]]+=v[1];
    }
        
    int cnt=0;
    int now=health;
    for (int i=1; i<=1e3; i++) {
        if (attack[i]!=0) {
            now-=attack[i];
            if (now<=0) return -1;
            cnt=0;
            
            if (i==last) {
                break;
            }
        }
        else {
            now=min(health, now+bandage[1]);
            cnt++;
            if (cnt>=bandage[0]) {
                cnt=0;
                now=min(health, now+bandage[2]);
            }
        }
    }
    return now;
}