#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int n) {

    return (n*(n-1))/2;

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;

        string ans = "NO";
        int i = 0;

        for(; i <= n; i++) {
            if(s(i)+s(n-i) == k) {
                ans = "YES";
                break;
            }
        }

        cout << ans << endl;
        if(ans == "YES") {
            for(int j = 0; j < i; j++) cout << 1 << " ";
            for(int j = 0; j < n-i; j++) cout << -1 << " ";
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