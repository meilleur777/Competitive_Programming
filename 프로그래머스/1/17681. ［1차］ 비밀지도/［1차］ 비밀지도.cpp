#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
        
    vector<string> ret(n, "");
    for (int i=0; i<n; i++) {
        int tmp=(arr1[i]|arr2[i]);
        for (int j=n-1; j>=0; j--) {
            if (tmp&(1<<j)) ret[i]+='#';
            else ret[i]+=' ';
        }
    }
    
    return ret;
}