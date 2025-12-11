#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int on = 0;
        int off = 0;

        for(int i = 0; i < 2*n; i++) {
            bool k; cin >> k;
            if(k) on++;
            else off++;
        }

        cout << on%2 << " " << min(on, off) << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}