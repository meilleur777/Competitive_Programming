#include <bits/stdc++.h>
using namespace std;

//Binary Search
int solution(int distance, vector<int> rocks, int n) {

    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    int ret=0;
    int left=0;
    int right=distance+1;
    while (left+1<right) {
        int mid=(left+right)/2;

        int removed=0;
        int ptr=0;
        while (ptr<(int)rocks.size()-1) {
            int now=ptr;
            ptr++;
            while (ptr<(int)rocks.size() && rocks[ptr]-rocks[now]<mid) {
                ptr++;
                removed++;
            }
        }

        if (removed<=n) {
            left=mid;
            ret=mid;
        }
        else right=mid;
    }

    return ret;
}