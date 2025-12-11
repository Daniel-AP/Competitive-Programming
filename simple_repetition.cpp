#include <bits/stdc++.h>
using namespace std;

#define int long long

bool prime(int n) {

    if(n <= 3) return n > 1;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6) {
        if(n%i == 0 or n%(i+2) == 0) return false;
    }

    return true;

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int x, k; cin >> x >> k;

        if(x == 1 && k == 2) cout << "YES" << endl;
        else if(k == 1 && prime(x)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}