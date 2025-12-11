#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, a, b; cin >> n >> a >> b;

        if((a==0 && b!=0) || a+b > n || (b==0 && a!=0)) {
            cout << "NO" << endl;
            continue;
        }

        int mn = min(a, b);
        int m = a+b;

        cout << "YES" << endl;

        if(a < b && a <= m/2) {
            for(int i = m; i > m-a; i--) cout << i << " ";
            for(int i = 1; i <= m-a; i++) cout << i << " ";
            for(int i = m+1; i <= n; i++) cout << i << " ";
            cout << endl;
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
        } else {
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
            for(int i = m; i > m-b; i--) cout << i << " ";
            for(int i = 1; i <= m-b; i++) cout << i << " ";
            for(int i = m+1; i <= n; i++) cout << i << " ";
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