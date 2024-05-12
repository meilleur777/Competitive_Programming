#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<string, string> mp={{"CU", "see you"},
                            {":-)", "I’m happy"},
                            {":-(", "I’m unhappy"},
                            {";-)", "wink"},
                            {":-P", "stick out my tongue"},
                            {"(~.~)", "sleepy"},
                            {"TA", "totally awesome"},
                            {"CCC", "Canadian Computing Competition"},
                            {"CUZ", "because"},
                            {"TY", "thank-you"},
                            {"YW", "you’re welcome"},
                            {"TTYL", "talk to you later"}};
    string s;
    while (getline(cin, s, '\n')) {
        if (mp.find(s)==mp.end()) cout << s << '\n';
        else cout << mp[s] << '\n';
    }

    return 0;
}
