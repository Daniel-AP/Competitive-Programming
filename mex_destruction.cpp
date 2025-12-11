#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int cnt = count(a.begin(), a.end(), 0);
        int start = 0, end = 0;

        int i = 0;
        while(i < n && a[i++] == 0) start++;

        i = n-1;
        while(i >= 0 && a[i--] == 0) end++;

        if(cnt == n) {
            cout << 0 << endl;
        } else if(cnt == start+end) {
            cout << 1 << endl;
        } else cout << 2 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}