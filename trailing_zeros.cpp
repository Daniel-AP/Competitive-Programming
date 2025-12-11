#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    int two_s = 0, five_s = 0;

    int k = 2, q = 5;

    while(k <= n) {
        two_s += n/k;
        k *= 2;
    }

    while(q <= n) {
        five_s += n/q;
        q *= 5;
    }

    cout << min(two_s, five_s) << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}