#include <bits/stdc++.h>
using namespace std;

string solution(int a, int b) {
    map<int, string> mp={{1, "FRI"}, {2, "SAT"}, {3,"SUN"}, {4, "MON"}, {5, "TUE"}, {6, "WED"}, {0, "THU"}};
    vector<int> mon({-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30});
    int cnt=b;
    for (int i=1; i<a; i++) cnt+=mon[i];

    return mp[cnt%7];
}