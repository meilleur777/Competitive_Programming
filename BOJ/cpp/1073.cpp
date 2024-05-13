#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    //1. Devide graph by connected components.
    //2. Check each graph is Eulerian graph. Because there must be Eulerian Cycle.
    //3. If graph is Eulerian, edges can be partitioned 
    //   into disjoint sets of graph which induces simple cycle.
    //4. If we determine indegree and outdegree for each traverse.
    //   사이클 콜렉션 induced with that particular situation can be determined.
    //5. Number of cases of traverse can be computed using number degrees of each node.

    int n;
    cin >> n;
    vector<int> degree(10, 0);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        degree[a/10]++;
        degree[a%10]++;
    }

    long long ans=1;
    //Devide degrees by groups of 2
    vector<int> val({1, 0, 1, 0, 3, 0, 15, 0, 105, 0, 945});
    for (int i=0; i<10; i++) ans*=val[degree[i]];
    cout << ans;

    return 0;
}
