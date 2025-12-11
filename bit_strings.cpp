#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binPow(int base, int exp) {

    int ans = 1;

    base %= MOD;

    while(exp > 0) {

        if(exp%2 == 1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;

        exp /= 2;

    }

    return ans;

}

void solve() {

    int n; cin >> n;

    cout << binPow(2, n) << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}