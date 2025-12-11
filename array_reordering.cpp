#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end(), [&](int a, int b){ return a%2 < b%2; });

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(gcd(a[i], 2*a[j]) > 1) count++;
            }
        }

        cout << count << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}