#include <bits/stdc++.h>
using namespace std;

int solution(string word) {
    int ret=0;
    string now="";
    map<char, char> mp={{'A', 'E'},
                       {'E', 'I'},
                       {'I', 'O'},
                       {'O', 'U'},
                       {'U', 'e'}};
    
    while (now!=word) {
        if ((int)now.length()<5) {
            now+="A";
        }
        else {
            int ptr=4;
            while (ptr>=0) {
                now[ptr]=mp[now[ptr]];
                if (now[ptr]=='e') {
                    now.pop_back();
                    ptr--;
                }
                else {
                    break;
                }
            }
        }
        ret++;
    }
    
    return ret;
}