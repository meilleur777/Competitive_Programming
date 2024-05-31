#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    while (n>=1 && a[n-1]==b[n-1]) n--;

    int ptr=0;
    while (ptr+1<n && b[ptr]<=b[ptr+1]) {
        ptr++;
    }

    sort(a.begin(), a.begin()+ptr);

    if (a==b) {
        cout << 1;
        return 0;
    }

    int tgt=-1;
    for (int i=0; i<n-1; i++) {
        if (b[i]==b[i+1]) {
            tgt=i+1;
            break;
        }
    }
    if (tgt==-1) {
        sort(a.begin(), a.begin()+ptr+1);
        cout << (a==b);
        return 0;
    }

    int loc=ptr;
    int newItem=a[loc];
    while (tgt<=loc && 1<=loc && newItem<a[loc-1]) {
        a[loc]=a[loc-1];
        loc--;
    }
    cout << (a==b);

    return 0;
}
