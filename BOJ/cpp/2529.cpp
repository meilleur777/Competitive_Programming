#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k;
    cin >> k;
    string s="";
    for (int i=0; i<k; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }

    string num="";
    for (int i=0; i<10; i++) {
        num.push_back(char(i+'0'));
    }

    long long mx=-1;
    long long mn=LLONG_MAX;
    do {
        bool flag=true;

        for (int i=0; i<k; i++) {
            int a=(num[i]-'0');
            int b=(num[i+1]-'0');

            if (s[i]=='>') {
                if (a<b) {
                    flag=false;
                    break;
                }
            }
            else {
                if (a>b) {
                    flag=false;
                    break;
                }
            }
        }

        if (!flag) continue;

        string tmp=num.substr(0, k+1);
        long long ttt=stoll(tmp);
        mx=max(mx, ttt);
        mn=min(mn, ttt);
    } while (next_permutation(num.begin(), num.end()));

    string mxStr=to_string(mx);
    string mnStr=to_string(mn);

    if (mxStr.size()!=k+1) cout << "0"+mxStr << '\n';
    else cout << mxStr << '\n';
    if (mnStr.size()!=k+1) cout << "0"+mnStr << '\n';
    else cout << mnStr << '\n';

    return 0;
}
