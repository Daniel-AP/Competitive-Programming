#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k, q; cin >> n >> k >> q;

        vector<int> temp(n);
        for(int i = 0; i < n; i++) cin >> temp[i];

        int cnt = 0, ways = 0;

        for(int i = 0; i < n; i++) {
            if(temp[i] <= q) cnt++;
            else {
                if(cnt >= k) ways += ((cnt-k+1)*(cnt-k+2))/2;
                cnt = 0;
            }
        }

        if(cnt >= k) ways += ((cnt-k+1)*(cnt-k+2))/2;

        cout << ways << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}