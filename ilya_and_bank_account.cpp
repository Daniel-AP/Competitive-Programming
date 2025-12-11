#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    if(n > 0) cout << n << endl;
    else {

        n *= -1;
        int pre = (n/10)%10;
        int last = n%10;

        if(pre > last) cout << -(n/100*10+last);
        else cout << -n/10 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}