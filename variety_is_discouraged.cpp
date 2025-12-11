#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        map<int, int> freq;
        for(int i = 0; i < n; i++) freq[a[i]]++;

        int l = 1, mx1 = 0, k = 1, mx2 = 0;

        for(int i = 0; i < n; i++) {
            if(freq[a[i]] == 1) mx2++;
            else {
                if(mx2 > mx1) l = k;
                mx1 = max(mx1, mx2);
                mx2 = 0;
                k = i+2;
            }
        }

        if(mx2 > mx1) l = k;
        mx1 = max(mx1, mx2);

        if(mx1 > 0) cout << l << " " << l+mx1-1 << endl;
        else cout << 0 << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}