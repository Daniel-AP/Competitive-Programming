#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, q; cin >> n >> q;

        vector<int> x(n), k(q);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < q; i++) cin >> k[i];

        map<int, int> mp;

        for(int i = 0; i < n; i++) {

            int freq = i*(n-i)+(n-i-1);

            mp[freq]++;
            if(i+1 < n) mp[(i+1)*(n-i-1)] += x[i+1]-x[i];

        }

        for(int i = 0; i < q; i++) {
            cout << mp[k[i]] << " ";
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