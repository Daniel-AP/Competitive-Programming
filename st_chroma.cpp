#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, x; cin >> n >> x;

        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);

        if(n == x) {
            for(int i: ans) cout << i << " ";
            cout << endl;
        } else {
            swap(ans[x], ans[n-1]);
            for(int i: ans) cout << i << " ";
            cout << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}