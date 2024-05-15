#include <bits/stdc++.h>
using namespace std;

string solution(int n) {
    string ret="";
    for (int i=0; i<n; i++) {
        if (i%2==0) ret+="수";
        else ret+="박";
    }
    return ret;
}