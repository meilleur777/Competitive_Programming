#include <bits/stdc++.h>
using namespace std;

//Divide and Conquer
vector<vector<int>> solution(int n) {

    vector<vector<int>> ret;
    
    function<void(int, int, int, int)> sol=[&](int a, int b, int c, int s) {
        if (s==0) return;
        sol(a, c, b, s-1);
        ret.push_back({a, c});
        sol(b, a, c, s-1);
    };
    sol(1, 2, 3, n);
    
    return ret;
}