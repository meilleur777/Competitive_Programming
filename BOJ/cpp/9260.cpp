#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int K;
    cin >> K;
    for (int tc=1; tc<=K; tc++) {
        int n, k, t;
        cin >> n >> k >> t;

        cin.ignore();
        set<string> words;
        while (n--) {
            string line;
            getline(cin, line);
            words.insert(line);
        }

        set<string> isIn;
        for (int i=0; i<k; i++) {
            string line;
            getline(cin, line);
            for (auto& c:line) {
                if (!islower(c)) {
                    c=' ';
                }
            }

            istringstream iss(line);
            string word;
            while (iss >> word) {
                if (words.find(word)!=words.end()) {
                    isIn.insert(word);
                }
            }
        }

        cout << "Data Set " << tc << ":\n";
        if ((int)isIn.size()<t) cout << "No ";
        cout << "Alarm\n\n";
    }
}
