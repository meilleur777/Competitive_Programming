#include <bits/stdc++.h>
using namespace std;

//Greedy
//borrow from adjacent student
int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> v(n, 1);
    for (auto i:lost) v[i-1]--;
    for (auto i:reserve) v[i-1]++;

    for (int i=0; i<n; i++) {
        if (v[i]==0) {
            if (i>0 && v[i-1]>=2) {
                v[i-1]--;
                v[i]++;
            }
            else if (i<n-1 && v[i+1]>=2) {
                v[i+1]--;
                v[i]++;
            }
        }
    }

    int ret=0;
    for (int i=0; i<n; i++) {
        ret+=(v[i]>=1);
    }

    return ret;
}   