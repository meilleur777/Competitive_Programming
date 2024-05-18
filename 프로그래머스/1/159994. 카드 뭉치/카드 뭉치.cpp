#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int ptr1=0, ptr2=0, ptrg=0;
    while (ptrg<(int)goal.size()) {
        if (ptr1<(int)cards1.size() && cards1[ptr1]==goal[ptrg]) {
            ptr1++;
            ptrg++;
        }
        else if (ptr2<(int)cards2.size() && cards2[ptr2]==goal[ptrg]) {
            ptr2++;
            ptrg++;
        }
        else break;
    }
    if (ptrg==(int)goal.size()) return "Yes";
    return "No";
}