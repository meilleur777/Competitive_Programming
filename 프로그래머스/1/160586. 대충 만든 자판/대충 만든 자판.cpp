#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> ret;
    vector<int> alphabet(26, 0x3f3f3f3f);
    for (int i=0; i<(int)keymap.size(); i++) {
        for (int j=0; j<(int)keymap[i].size(); j++) {
            alphabet[keymap[i][j]-'A']=min(alphabet[keymap[i][j]-'A'], j+1);
        }
    }

    for (int i=0; i<(int)targets.size(); i++) {
        bool possible=true;
        int cnt=0;
        for (int j=0; j<(int)targets[i].size(); j++) {
            int tmp=alphabet[targets[i][j]-'A'];
            if (tmp==0x3f3f3f3f) {
                possible=false;
                break;
            }
            cnt+=tmp;
        }
        if (possible) ret.push_back(cnt);
        else ret.push_back(-1);
    }

    return ret;
}