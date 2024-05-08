#include <bits/stdc++.h>
using namespace std;

//Binary Search
int solution(vector<int> stones, int k) {

    int n=stones.size();
    int mx=*max_element(stones.begin(), stones.end());

    int left=-1;
    int right=mx+1;
    int ret=0;

    while (left+1<right) {
        
        int mid=(left+right)/2;
        bool flag=true;
        
        int ptr=0;
        int last=-1;
        while (ptr<n) {
            while (ptr<n && stones[ptr]<mid) {
                ptr++;
            }

            if (ptr-last>k) {
                flag=false;
                break;
            }
            else {
                last=ptr;
                ptr++;
            }
        }
        if (ptr-last>k) flag=false;

        if (flag) {
            ret=mid;
            left=mid;
        }
        else {
            right=mid;
        }
    }

    return ret;
}