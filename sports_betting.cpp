#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;

    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] >= 4) return void(cout << "YES" << '\n');
    }

    a.clear();
    for(auto [k, v]: cnt) a.push_back(k);
    
    int i = 0;

    while(i < a.size()) {
        if(cnt[a[i]] >= 2) {
            i++;
            for(; i < n; i++) {
                if(a[i]-1 != a[i-1]) break;
                if(cnt[a[i]] >= 2) return void(cout << "YES" << '\n');
            }
        } else {
            i++;
        }
    }

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