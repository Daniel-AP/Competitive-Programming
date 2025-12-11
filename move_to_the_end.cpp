#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<int> a(n), mx(n), prefix(n+1);
    for(int i = 0; i < n; i++) cin >> a[i];

    mx[0] = a[0];
    
    for(int i = 1; i < n; i++) mx[i] = max(a[i], mx[i-1]);

    partial_sum(a.begin(), a.end(), prefix.begin()+1);

    for(int i = 1; i <= n; i++) {
        cout << max(prefix[n]-prefix[n-i], prefix[n]-prefix[n-i]-a[n-i]+mx[n-i]) << " ";
    }

    cout << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}