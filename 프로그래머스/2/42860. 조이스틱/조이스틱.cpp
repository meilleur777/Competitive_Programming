#include <bits/stdc++.h>
using namespace std;

//Bruteforce
int solution(string name) {
    const int inf=0x3f3f3f3f;

    int ret=inf;
    int n=name.size();
    map<pair<string, int>, int> cache;
    function<void(string, int, int)> bruteforce=[&](string s, int now, int cnt) {
        if (s==name) {
            ret=min(ret, cnt);
            return;
        }
        if (cache.find({s, now})!=cache.end()) {
            if (cache[{s, now}]>cnt) cache[{s, now}]=cnt;
            else return;
        }
        else cache[{s, now}]=cnt;

        bruteforce(s, (now-1+n)%n, cnt+1);
        bruteforce(s, (now+1+n)%n, cnt+1);
        if (s[now]!=name[now]) {
            cnt+=min((name[now]-s[now]+26)%26, (s[now]-name[now]+26)%26);
            s[now]=name[now];
            bruteforce(s, now, cnt);
            bruteforce(s, (now-1+n)%n, cnt+1);
            bruteforce(s, (now+1+n)%n, cnt+1);
        }
    };
    bruteforce(string(n, 'A'), 0, 0);

    return ret;
}

