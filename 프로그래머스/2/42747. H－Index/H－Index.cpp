#include <bits/stdc++.h>
using namespace std;

//Implementation
int solution(vector<int> citations) {

    int ret=0;
    
    sort(citations.begin(), citations.end());
    int tmp=0;
    for (int i=0; i<=10000; i++) {
        int ind=lower_bound(citations.begin(), citations.end(), i)-citations.begin();
        if (ind>(int)citations.size()-1) continue;
        if ((int)citations.size()-ind>=i) ret=max(ret, i);
    }
    
    return ret;
}