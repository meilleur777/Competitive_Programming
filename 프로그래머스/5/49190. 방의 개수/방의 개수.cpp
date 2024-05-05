#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> moves) {
    vector<int> dy({-1, -1, 0, 1, 1, 1, 0, -1});
    vector<int> dx({0, 1, 1, 1, 0, -1, -1, -1});

    set<pair<int, int>> node;
    set<pair<pair<int, int>, pair<int, int>>> edges; 
    pair<int, int> now={0, 0};
    node.insert(now);
    for (auto move:moves) {
        //There can be cycle made with crossed diagonals
        for (int i=0; i<2; i++) { 
            pair<int, int> nxt={now.first+dy[move], now.second+dx[move]};
            node.insert(nxt);
            edges.insert({now, nxt});
            edges.insert({nxt, now});
            now=nxt;
        }
    }

    //# of simple cycle in connected graph using Euler's Theorem
    //# of edge - # of node + 1
    return (int)edges.size()/2-(int)node.size()+1;
}