#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> perm(n);
        for(int i = 0; i < n; i++) cin >> perm[i];

        int ans = 0;

        for(int i = 0; i < n; i++) ans = gcd(perm[i]-i-1, ans);            

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}