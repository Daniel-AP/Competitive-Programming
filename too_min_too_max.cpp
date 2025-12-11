#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        vector<int> v = { a[0], a[n-1], a[1], a[n-2] };

        int ans = 0;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 4; k++) {
                    for(int l = 0; l < 4; l++) {
                        if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
                        ans = max(abs(v[i]-v[j])+abs(v[j]-v[k])+abs(v[k]-v[l])+abs(v[l]-v[i]), ans);
                    }
                }
            }
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