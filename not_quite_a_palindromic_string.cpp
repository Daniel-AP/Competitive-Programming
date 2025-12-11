#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');

    int mn = max(max(cnt0, cnt1)-n/2, 0LL);
    int mx = cnt0/2+cnt1/2;
    
    if(k >= mn && k <= mx && k%2 == mn%2) cout << "YES" << endl;
    else cout << "NO" << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}