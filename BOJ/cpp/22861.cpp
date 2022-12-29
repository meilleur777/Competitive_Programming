#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

struct _folder {
    unordered_map<string, _folder*> folders;
    unordered_set<string> files;
};
typedef _folder folder;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    folder* main=new folder;
    unordered_map<string, folder*> allfolder;
    allfolder["main"]=main;
    rep(i, n+m) {
        string p, f;
        int c;
        cin >> p >> f >> c;
        if (allfolder.find(f)==allfolder.end()) allfolder[f]=new folder;
        if (allfolder.find(p)==allfolder.end()) allfolder[p]=new folder;
        if (c) {
            allfolder[p]->folders[f]=allfolder[f];
        }
        else {
            allfolder[p]->files.insert(f);
        }
    }

    int k;
    cin >> k;
    unordered_set<string> dead;
    while (k--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int here=s.find('/');
        string src;
        if (here==-1) {
            src="main";
        }
        else {
            src=s.substr(0, here);
            reverse(src.begin(), src.end());
        }

        cin >> s;
        reverse(s.begin(), s.end());
        here=s.find('/');
        string des;
        if (here==-1) {
            des="main";
        }
        else {
            des=s.substr(0, here);
            reverse(des.begin(), des.end());
        }

        for (auto [a, b]:allfolder[src]->folders) {
            allfolder[des]->folders[a]=b;
        }
        for (auto a:allfolder[src]->files) {
            allfolder[des]->files.insert(a);
        }
        dead.insert(src);
    }


    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        int here=s.find('/');
        string now;
        if (here==-1) {
            now="main";
        }
        else {
            now=s.substr(0, here);
            reverse(now.begin(), now.end());
        }

        int cnt=0;
        unordered_set<string> st;
        function<void(folder*)> dfs=[&](folder* now) {
            cnt+=(int)now->files.size();
            for (auto i:now->files) {
                st.insert(i);
            }
            for (auto [a, b]:now->folders) {
                if (dead.find(a)!=dead.end()) continue;
                dfs(b);
            }
        };
        dfs(allfolder[now]);

        cout << (int)st.size() << ' ' << cnt << '\n';
    }

    return 0;
}
