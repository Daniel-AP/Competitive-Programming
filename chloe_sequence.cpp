#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n, k; cin >> n >> k;

    for(int i = 0; i <= n; i++) {
        int q = (1LL<<i);
        if((k-q)%(1LL<<(i+1)) == 0) {
            cout << i+1 << "\n";
            return;
        }
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}