#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> memo;
map<int, vector<int>> mp;

int best(int m) {

    if(memo.find(m) != memo.end()) return memo[m];

    memo[m] = 0;

    for(int i: mp[m]) {
        memo[m] = max(memo[m], i+best(m+i));
    }

    return memo[m];

}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    memo.clear();
    mp.clear();

    for(int i = 0; i < n; i++) {
        if(i+a[i] < n) continue;
        mp[i+a[i]].push_back(i);
    }

    cout << n+best(n) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}