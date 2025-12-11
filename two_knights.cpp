#include <bits/stdc++.h>
using namespace std;

#define int long long

int nCr(int n, int r) {

    if(r == 0) return 1;
    if(r > n) return 0;
    if(r > n/2) return nCr(n, n-r);

    int ans = 1;

    for(int i = 1; i <= r; i++) {
        ans *= n-i+1;
        ans /= i;
    }

    return ans;

}

void solve() {

    int n; cin >> n;
    int f = 0, inc = 0;

    for(int i = 1; i <= n; i++) {
        if(i >= 3) inc++;
        f += inc;
        cout << nCr(i*i, 2) - 8*f << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}