#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<int, string> rankToName;
    map<string, int> nameToRank;
    for (int i=0; i<(int)players.size(); i++) {
        rankToName[i+1]=players[i];
        nameToRank[players[i]]=i+1;
    }
    for (auto name:callings) {
        int nowRank=nameToRank[name];
        string frontName=rankToName[nowRank-1];
        nameToRank[frontName]++;
        nameToRank[name]--;
        rankToName[nowRank-1]=name;
        rankToName[nowRank]=frontName;
    }
    vector<string> ret((int)players.size());
    for (auto [p, q]:nameToRank) {
        ret[q-1]=p;
    }
    return ret;
}