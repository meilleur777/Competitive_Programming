#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
    vector<bool> inNumbers(10, false);
    for (auto i:numbers) inNumbers[i]=true;
    int ret=0;
    for (int i=0; i<10; i++) {
        if (!inNumbers[i]) ret+=i;
    }
    return ret;
}