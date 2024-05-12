#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long double a, b;
    cin >> a >> b;
    long double res=a/(b*b);
    if (res>25) cout << "Overweight";
    else if (res>=18.5) cout << "Normal weight";
    else cout << "Underweight";

    return 0;
}
