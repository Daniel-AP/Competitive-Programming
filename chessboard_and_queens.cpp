#include <bits/stdc++.h>
using namespace std;

#define int long long

bool collision(pair<int, int> queen, pair<int, int> sub) {

    return queen.first == sub.first || queen.second == sub.second || queen.second+abs(queen.first-sub.first) == sub.second || queen.second-abs(queen.first-sub.first) == sub.second;

}

int dfs(vector<pair<int, int>> queens, int row, vector<string>& board) {

    for(int i = 0; i < queens.size(); i++) {
        for(int j = 0; j < queens.size(); j++) {
            if(i == j) continue;
            if(collision(queens[i], queens[j])) return 0;
        }
    }

    if(row == 8) return 1;
    int ans = 0;

    for(int i = 0; i < 8; i++) {
        if(board[row][i] == '*') continue;
        queens.push_back({ row, i });
        ans += dfs(queens, row+1, board);
        queens.pop_back();
    }

    return ans;

}

void solve() {

    vector<string> a(8), b;
    for(int i = 0; i < 8; i++) cin >> a[i];

    cout << dfs({}, 0, a) << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}