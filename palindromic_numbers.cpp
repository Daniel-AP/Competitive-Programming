#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n; cin >> n;
    string m, ans; cin >> m;
    
    if(m[0] == '9') {
        bool carry = false;
        for(int i = n-1; i >= 0; i--) {
            int k = m[i]-'0';
            if(carry) {
                carry = false;
                if(k == 9) {
                    k = 0;
                    carry = true;
                } else {
                    k++;
                }
            }
            if(k < 2) {
                ans += (1-k+'0');
            } else {
                carry = true;
                ans += (11-k+'0');
            }
        }
        for(int i = n-1; i >= 0; i--) cout << ans[i];
    } else {
        for(int i = 0; i < n; i++) {
            cout << 9-(m[i]-'0');
        }
    }
    
    cout << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}