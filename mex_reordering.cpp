#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> cnt(n+1);
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    if(cnt[0] == 0 || cnt[a[0]] == n) return void(cout << "NO" << '\n');
    
    int mex = 0;
    while(cnt[mex]) mex++;

    if(mex > 1 || cnt[0] == 1) return void(cout << "YES" << '\n');

    cout << "NO" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}