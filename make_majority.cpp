#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        string a; cin >> a;

        int zero = (a[0]=='0'), one = 0;

        for(int i = 0; i < n-1; i++) {
            if(a[i] == '1' && a[i+1] == '0') zero++;
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == '1') one++;
        }

        if(zero >= one) cout << "NO" << endl;
        else cout << "YES" << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}