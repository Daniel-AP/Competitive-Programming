#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++)  cin >> a[i];

        sort(a.begin(), a.end());

        int cnt1 = count(a.begin(), a.end(), a[n-1]);
        int cnt2 = count(a.begin(), a.end(), a[0]);

        if(a[0] == a[n-1]) {
            cout << cnt1*(cnt2-1) << endl;
        } else {
            cout << cnt1*cnt2*2 << endl;
        }

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}