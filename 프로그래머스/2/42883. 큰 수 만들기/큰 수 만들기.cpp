#include <bits/stdc++.h>
using namespace std;

//Greedy
//delete if deletion can make highest digit bigger
//if digits are in descending order, delete from lowest digit
string solution(string number, int k) {
    int now=0;
    while (k>0) {
        int ind=now;
        for (int i=1; i<=k; i++) {
            if (number[now+i]>number[ind]) {
                ind=now+i;
            }
        }
        if (ind>=(int)number.size()) {
            while (k--) {
                number.pop_back();
            }
        }
        else if (ind!=now) {
            k-=ind-now;
            number.erase(now, ind-now);
        }
        else {
            now++;
        }
    }

    return number;
}
