#include <bits/stdc++.h>
using namespace std;

vector<int> dy({0, 0, 1, -1});
vector<int> dx({1, -1, 0, 0});

int solution(vector<vector<string>> board, int h, int w) {
    int n=board.size(), m=board.front().size();
    
    int ret=0;
    for (int d=0; d<4; d++) {
        int ny=h+dy[d];
        int nx=w+dx[d];
        if (ny>=n || ny<0 || nx>=m || nx<0) continue;
        if (board[ny][nx]==board[h][w]) ret++;
    }
    return ret;
}