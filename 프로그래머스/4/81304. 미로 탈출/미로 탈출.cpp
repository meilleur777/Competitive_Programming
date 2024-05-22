#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;

//BFS optimized with Bitmasking
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    start--, end--;

    int t=(int)traps.size();
    vector<vector<vector<pair<int, int>>>> edge(2, vector<vector<pair<int, int>>>(n));
    for (auto& v:roads) {
        v[0]--, v[1]--;
        edge[0][v[0]].push_back({v[1], v[2]});
        edge[1][v[1]].push_back({v[0], v[2]});
    }

    map<int, int> trapsMp;
    for (int i=0; i<t; i++) {
        trapsMp[traps[i]-1]=i;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>((1<<t), inf));
    q.push({start, 0});
    dist[start][0]=0;
    while (!q.empty()) {
        auto [now, state]=q.front();
        q.pop();

        for (int i=0; i<2; i++) {
            for (auto [nxt, cost]:edge[i][now]) {
                int tag=0;
                if (trapsMp.find(now)!=trapsMp.end()) tag+=(!!(state&(1<<trapsMp[now])));
                if (trapsMp.find(nxt)!=trapsMp.end()) tag+=(!!(state&(1<<trapsMp[nxt])));
                tag%=2;
                if (tag!=i) continue;

                int newState=state;
                if (trapsMp.find(nxt)!=trapsMp.end()) {
                    if (newState&(1<<trapsMp[nxt])) {
                        newState=(newState&(~(1<<trapsMp[nxt])));
                    }
                    else {
                        newState=(newState|(1<<trapsMp[nxt]));
                    }
                }
                if (dist[nxt][newState]>dist[now][state]+cost) {
                    dist[nxt][newState]=dist[now][state]+cost;
                    q.push({nxt, newState});
                }
            }
        }
    }

    int ret=inf;
    for (int i=0; i<(1<<t); i++) {
        ret=min(ret, dist[end][i]);
    }
    return ret;
}