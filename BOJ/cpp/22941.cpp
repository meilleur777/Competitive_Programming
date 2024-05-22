#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    function<void()> gg=[]() {
        cout << "gg";
        exit(0);
    };
    function<void()> vic=[]() {
        cout << "Victory!";
        exit(0);
    };

    long long hw, aw, hv, av, p, s;
    cin >> hw >> aw >> hv >> av >> p >> s;

    long long attack=(hv-p-1)/aw;
    if (hw-attack*av<=0) gg();
    hv-=attack*aw;
    hw-=attack*av;

    hv-=aw;
    if (hv<=0) vic();
    hw-=av;
    if (hw<=0) gg();
    hv+=s;

    attack=min((hw-1)/av, (hv-1)/aw);
    hv-=aw*attack;
    hw-=av*attack;

    hv-=aw;
    if (hv<=0) vic();
    hw-=av;
    if (hw<=0) gg();

    return 0;
}
