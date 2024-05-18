#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    map<string, int> mp;
    for (int i=0; i<(int)name.size(); i++)  {
        mp[name[i]]=yearning[i];
    }
    vector<int> ret;
    for (int i=0; i<(int)photo.size(); i++) {
        int sum=0;
        for (auto j:photo[i]) {
            sum+=mp[j];
        }
        ret.push_back(sum);
    }
    return ret;
}