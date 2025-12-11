#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int n = s.length();
    if (n == 0) return;
    int k = n / 6;

    vector<vector<int>> ans(k);
    vector<queue<int>> waiting(6);

    for (int i = 0; i < k; ++i) {
        waiting[0].push(i);
    }

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        int idx = i + 1;
        int sub_id;

        if (c == '1') {
            if (!waiting[0].empty()) {
                sub_id = waiting[0].front(); waiting[0].pop();
                ans[sub_id].push_back(idx);
                waiting[1].push(sub_id);
            } else if (!waiting[1].empty()) {
                sub_id = waiting[1].front(); waiting[1].pop();
                ans[sub_id].push_back(idx);
                waiting[2].push(sub_id);
            } else {
                sub_id = waiting[4].front(); waiting[4].pop();
                ans[sub_id].push_back(idx);
                waiting[5].push(sub_id);
            }
        } else if (c == '2') {
            if (!waiting[2].empty()) {
                sub_id = waiting[2].front(); waiting[2].pop();
                ans[sub_id].push_back(idx);
                waiting[3].push(sub_id);
            } else {
                sub_id = waiting[5].front(); waiting[5].pop();
                ans[sub_id].push_back(idx);
            }
        } else { // c == '0'
            sub_id = waiting[3].front(); waiting[3].pop();
            ans[sub_id].push_back(idx);
            waiting[4].push(sub_id);
        }
    }

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout << ans[i][j] << (j == 5 ? "\n" : " ");
        }
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}
