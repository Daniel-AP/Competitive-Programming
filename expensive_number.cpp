#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        string n; cin >> n;
        bool found = false;
        int ans = 0;

        for(int i = n.length()-1; i >= 0; i--) {
            if(n[i] != '0') found = true;
            if(!found) ans++;
            else if(n[i] != '0') ans++;
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