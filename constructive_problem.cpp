#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int mex = 0;
    while(cnt[mex] != 0) mex++;

    if(mex == n) return void(cout << "NO" << '\n');
    if(cnt[mex+1] == 0) return void(cout << "YES" << '\n');

    int l = 0, r = n-1;

    while(a[l] != mex+1) l++;
    while(a[r] != mex+1) r--;

    for(int i = l; i <= r; i++) {
        cnt[a[i]]--;
        if(cnt[a[i]] == 0 && a[i] < mex) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}