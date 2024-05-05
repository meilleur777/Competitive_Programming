#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {

    vector<int> ret;
    for (auto i:commands) {
        int st=i[0], ed=i[1], k=i[2];
        vector<int> tarr=array;
        sort(tarr.begin()+st-1, tarr.begin()+ed);
        ret.push_back(tarr[st+k-2]);
    }
    
    return ret;
}