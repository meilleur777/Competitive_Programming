#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

typedef pair<pair<intp, intp>, int> ttt;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];

        int one;
        for (int i=0; i<n; i++) {
            if (a[i]==1) {
                one=i;
            }
        }
        int leftptr=one;
        int leftup=0;
        while (leftptr>0 && a[leftptr-1]>a[leftptr]) {
            leftptr--;
            leftup++;
        }
        int lefttop=leftptr;
        int leftdown=0;
        while (leftptr>0 && a[leftptr-1]<a[leftptr]) {
            leftptr--;
            leftdown++;
        }

        int rightptr=one;
        int rightup=0;
        while (rightptr>0 && a[rightptr-1]>a[rightptr]) {
            rightptr--;
            rightup++;
        }
        int righttop=rightptr;
        int rightdown=0;
        while (rightptr>0 && a[rightptr-1]<a[rightptr]) {
            rightptr--;
            rightdown++;
        }

        map<ttt, bool> mp;
        function<bool(int, int, int, int, int)> sol=[&](int leftdown, int left, int right, int rightdown, int other) {
            if (left==right) return true;
            
            ttt tmp={{{leftdown%4, leftup%4}, {rightup%4, rightdown%4}}, other%4};
            if (mp.find(tmp)!=mp.end()) {
                return mp[tmp];
            }
            bool ret=false;
            if (!sol(0, leftup-1, rightup, rightdown, other) || )
        }
    }

    return 0;
}
