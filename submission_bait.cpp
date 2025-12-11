#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        set<int> r(a.begin(), a.end());

        string ans = "NO";
        
        for(int i: r) {
            if(count(a.begin(), a.end(), i)%2 == 1) {
                ans = "YES";
            }
        }

        cout << ans << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}