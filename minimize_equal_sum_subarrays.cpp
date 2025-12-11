#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];

        cout << p[n-1] << " ";
        for(int i = 0; i < n-1; i++) cout << p[i] << " ";

        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}