#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        if (N == x) ans++;
    }

    cout << ans;
}
