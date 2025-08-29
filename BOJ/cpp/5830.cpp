#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int row, col;
    Point(int r=0, int c=0): row(r), col(c) {}
    bool operator<(const Point& other) const {
        if (row!=other.row) return row<other.row;
        return col<other.col;
    }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    
    map<string, Point> feet;
    feet["FL"]=Point(0, 0);
    feet["FR"]=Point(0, 1);
    feet["RL"]=Point(1, 0);
    feet["RR"]=Point(1, 1);
    
    int direction=0;
    
    vector<vector<Point>> direction_vectors={
        {Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1)},
        {Point(1, 0), Point(0, -1), Point(-1, 0), Point(0, 1)},
        {Point(0, -1), Point(-1, 0), Point(0, 1), Point(1, 0)},
        {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)}
    };
    
    set<Point> all_positions;
    for (auto& p:feet) {
        all_positions.insert(p.second);
    }
    
    auto check_collision=[&]() {
        set<Point> st;
        for (auto& p:feet) {
            if (st.find(p.second)!=st.end()) {
                return true;
            }
            st.insert(p.second);
        }

        return false;
    };
    
    auto rotate=[&](const string& pivot) {
        Point pivotPos=feet[pivot];
        
        for (auto& foot:feet) {
            if (foot.first!=pivot) {
                int rel_row=foot.second.row-pivotPos.row;
                int rel_col=foot.second.col-pivotPos.col;
                
                int new_rel_row=rel_col;
                int new_rel_col=-rel_row;
                
                foot.second=Point(pivotPos.row+new_rel_row, pivotPos.col+new_rel_col);
            }
        }
        
        direction=(direction+1)%4;
    };
    
    vector<string> orders(n);
    for (int i=0; i<n; i++) {
        cin >> orders[i];
    }

    for (const string& order:orders) {
        if (order[2]=='P') {
            string pivot=order.substr(0, 2);
            rotate(pivot);
        } 
        else {
            string toMove=order.substr(0, 2);
            char dir=order[2];
            
            int d;
            if (dir=='F') d=0;
            else if (dir=='B') d=1;
            else if (dir=='L') d=2;
            else d=3;
            
            Point movement=direction_vectors[d][direction];
            
            Point old_pos=feet[toMove];
            Point new_pos(old_pos.row+movement.row, old_pos.col+movement.col);
            feet[toMove]=new_pos;
        }
        
        if (check_collision()) {
            cout << -1 << endl;
            return 0;
        }
        
        for (auto& p: feet) {
            all_positions.insert(p.second);
        }
    }
    
    int min_row=all_positions.begin()->row;
    int max_row=min_row;
    int min_col=all_positions.begin()->col;
    int max_col=min_col;
    
    for (const Point& pos:all_positions) {
        min_row=min(min_row, pos.row);
        max_row=max(max_row, pos.row);
        min_col=min(min_col, pos.col);
        max_col=max(max_col, pos.col);
    }
    
    int ans=(max_row-min_row+1)*(max_col-min_col+1);
    cout << ans << endl;

    return 0;
}
