#include <bits/stdc++.h>
using namespace std;

#define int long long

int comb(int n, int r) {
    
    if(n < r) return 0;
    if(r == 0 || n == r) return 1;

    r = min(r, n-r);

    int ans = 1;
    for(int i = 0; i < r; i++) {
        ans *= n-i;
        ans /= i+1;
    }

    return ans;

}

void solve() {

    int q; cin >> q;

    while(q--) {

        string s, t; cin >> s >> t;
        int cnt = count(s.begin(), s.end(), 'a');
        
        if(t == "a") {
            cout << 1 << endl;
        } else if(t.find('a') != t.npos) {
            cout << -1 << endl;
        } else {
            int ans = 0;
            for(int i = 0; i <= cnt; i++) {
                ans += comb(cnt, i);
            }
            cout << ans << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}