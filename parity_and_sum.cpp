#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        int odd = 0;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            odd += a[i]%2;
        }
    
        sort(a.begin(), a.end());

        int mx = -1, cnt = 0;
        
        for(int i = n-1; i >= 0; i--) {
            if(a[i]%2 == 1) {
                mx = a[i];
                break;
            }
        }

        if(mx == -1) {
            cout << 0 << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {
            if(a[i]%2 == 1) continue;
            if(a[i] > mx) {
                cnt++;
                break;
            }
            mx += a[i];
        }

        cout << n-odd+cnt << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}