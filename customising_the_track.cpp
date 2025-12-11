#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int s = 0;

        vector<int> a(n), prefix(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }

        for(int i = 0 ;i < n; i++) {
            if(i < s%n) a[i] = s/n+1;
            else a[i] = s/n;
        }

        partial_sum(a.begin(), a.end(), prefix.begin());

        int ans = 0;
        for(int i = 0; i < n; i++) {

            int m = prefix[n-1]-prefix[i];
            ans += abs(a[i]*(n-i-1)-m);

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