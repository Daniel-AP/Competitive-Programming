#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        if(n%2 == 0) cout << -1 << endl;
        else {
            vector<int> a(n);
            for(int i = 1; i < n; i += 2) a[i] = i/2+1;
            for(int i = 0; i < n; i += 2) a[i] = n-(i/2);
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}