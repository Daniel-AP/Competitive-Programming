#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> cnt(101);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }

    for(int i = 1; i <= 100; i++) {
        if(cnt[i] > 1) return void(cout << -1 << '\n');
    }

    for(int i = 100; i >= 1; i--) {
        for(int j = 0; j < cnt[i]; j++) cout << i << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}