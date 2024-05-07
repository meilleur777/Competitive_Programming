#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {

    long long ret=0;
    long long left=0, right=(long long)n*(*max_element(times.begin(), times.end()))+1;
    while (left+1<right) {
        long long mid=(left+right)/2;

        long long sum=0;
        for (int i=0; i<(int)times.size(); i++) {
            sum+=(mid)/(times[i]);
        }
        
        if (sum>=n) {
            right=mid;
            ret=mid;
        }
        else left=mid;
    }

    return ret;
}