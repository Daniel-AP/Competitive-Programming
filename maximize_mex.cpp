#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, x; cin >> n >> x;

        map<int, int> con, freq;

        for(int i = 0; i < n; i++) {
            int k; cin >> k;
            freq[k]++;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            
            con[i%x] += freq[i];

            if(con[i%x] > 0) con[i%x]--;
            else break;

            ans = i+1;

        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}