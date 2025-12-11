#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);

        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}