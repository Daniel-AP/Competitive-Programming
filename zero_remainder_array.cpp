#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b;
    for(int i = 0; i < n; i++) {
        if(a[i]%k != 0) b.push_back(k-a[i]%k);
    }

    int m = b.size();

    if(!m) return void(cout << 0 << '\n');

    map<int, int> cnt;

    for(int i = 0; i < m; i++) {
        cnt[b[i]]++;
        b[i] += k*(cnt[b[i]]-1);
    }

    sort(all(b));

    cout << b[m-1]+1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}