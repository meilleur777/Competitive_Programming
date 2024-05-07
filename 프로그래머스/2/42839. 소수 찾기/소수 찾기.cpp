#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n<=1) return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

//Bruteforce
int solution(string numbers) {

    set<int> ret;
    vector<int> num;
    for (auto c:numbers) num.push_back(int(c-'0'));
    sort(num.begin(), num.end());

    do {
        for (int j=0; j<(int)num.size(); j++) {
            string tmp="";
            for (int i=0; i<((int)num.size()); i++) {
                if (i+j>=(int)num.size()) break;
                tmp+=to_string(num[i+j]);
                cout << tmp << '\n';
                if (isPrime(stoi(tmp))) {
                    ret.insert(stoi(tmp));
                }
            }
        }
    } while (next_permutation(num.begin(), num.end()));

    return (int)ret.size();
}