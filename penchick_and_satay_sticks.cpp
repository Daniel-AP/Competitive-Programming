#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        vector<int> p(n);
        for(int i = 0; i < n; i++) cin >> p[i];

        string ans = "YES";

        for(int i = 0; i < n; i++) {
            if(abs(i+1-p[i]) != 1) ans = "NO";
            else if(p[i] < i+1 && p[i-1] != i+1) ans = "NO";
            else if(p[i] > i+1 && p[i+1] != i) ans = "NO";
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