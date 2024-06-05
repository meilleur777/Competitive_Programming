#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    map<string, int> mp({{"Franklin", 100}, 
                         {"Grant", 50}, 
                         {"Jackson", 20}, 
                         {"Hamilton", 10}, 
                         {"Lincoln", 5},
                         {"Washington", 1}});
    
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s, '\n');

        int ans=0;
        size_t ptr=0;
        while ((ptr=s.find(' '))!=s.npos) {
            string tmp=s.substr(0, ptr);
            ans+=mp[tmp];
            s.erase(0, ptr+1);
        }
        ans+=mp[s];

        cout << "$" << ans << '\n';
    }

    return 0;
}
