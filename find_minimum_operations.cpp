#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, k; cin >> n >> k;
        int count = 0;

        while(n) {
            int t = 1;
            if(k != 1) while(t*k <= n) t *= k;
            count += n/t;
            n -= t*(n/t);
        }

        cout << count << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}