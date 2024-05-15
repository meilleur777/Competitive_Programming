#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    int cnty=0, cntp=0;
    for (auto c:s) {
        char lc=tolower(c);
        if (lc=='p') cntp++;
        else if (lc=='y') cnty++;
    }
    
    return cntp==cnty;
}