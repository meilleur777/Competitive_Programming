#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int ret=0;
    int n=absolutes.size();
    for (int i=0; i<n; i++) {
        if (signs[i]) ret+=absolutes[i];
        else ret-=absolutes[i];
    }
    return ret;
}