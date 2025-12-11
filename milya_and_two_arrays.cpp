#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        unordered_set<int> a, b;

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a.insert(x);
        }
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            b.insert(x);
        }

        if(a.size()*b.size() >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}