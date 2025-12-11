#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    cout << n << " ";

    while(n != 1) {

        if(n%2 == 0) n /= 2;
        else n = n*3+1;

        cout << n << " ";

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}