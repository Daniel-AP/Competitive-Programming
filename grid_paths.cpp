#include <bits/stdc++.h>
using namespace std;

#define int long long

map<char, int> ops = {
    {'D', 1},
    {'U', -1},
    {'L', -1},
    {'R', 1}
};

bool visited[7][7];
string p;

int path(int start, int row, int col) {

    if(row < 0 || row > 6 || col < 0 || col > 6) return 0;
    
    bool L = (col-1 < 0) || visited[row][col-1];
    bool R = (col+1 > 6) || visited[row][col+1];
    bool U = (row-1 < 0) || visited[row-1][col];
    bool D = (row+1 > 6) || visited[row+1][col];

    if((L && R && !U && !D) || (U && D && !L && !R))
        return 0;

    if(row == 6 && col == 0) {
        if(start == 48) return 1;
        return 0;
    }

    if(start == 48) return 0;

    int ans = 0;
    visited[row][col] = true;

    if(p[start] != '?') {

        int next_row = row, next_col = col;
        if(p[start] == 'D' || p[start] == 'U') next_row += ops[p[start]];
        else next_col += ops[p[start]];

        if(next_row >= 0 && next_row <= 6 && next_col >= 0 && next_col <= 6 && !visited[next_row][next_col]) 
            ans += path(start+1, next_row, next_col);

    } else {

        if(row+1 <= 6 && !visited[row+1][col]) ans += path(start+1, row+1, col);
        if(row-1 >= 0 && !visited[row-1][col]) ans += path(start+1, row-1, col);
        if(col-1 >= 0 && !visited[row][col-1]) ans += path(start+1, row, col-1);
        if(col+1 <= 6 && !visited[row][col+1]) ans += path(start+1, row, col+1);

    }
    
    visited[row][col] = false;

    return ans;
}

void solve() {

    cin >> p;
    memset(visited, 0, sizeof(visited));
    
    cout << path(0, 0, 0) << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    auto start = chrono::system_clock::now();

    solve();

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

    cout << elapsed_seconds.count() << endl;

    return 0;
}
