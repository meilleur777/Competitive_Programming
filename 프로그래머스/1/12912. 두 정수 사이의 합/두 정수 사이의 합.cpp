#include <bits/stdc++.h>
using namespace std;

long long solution(int a, int b) {
    long long ret=0;
    for (int i=min(a, b); i<=max(a, b); i++) ret+=i;
    return ret;
}