#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

using pp = pair<int, int>;

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n), x(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> x[i];

    auto comp = [&](pp p1, pp p2) {
        if(p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second;
    };

    multiset<pp, decltype(comp)> ms(comp);

    for(int i = 0; i < n; i++) ms.insert({ abs(x[i]), a[i] });

    int s = 0;

    while(!ms.empty()) {
        int kk = k;
        while(!ms.empty()) {
            auto [pos, life] = *ms.begin(); ms.erase(ms.begin());
            if(pos-s <= 0) return void(cout << "NO" << '\n');
            int t = min(kk, life);
            life -= t;
            kk -= t;
            if(life) ms.insert({ pos, life });
            if(kk == 0) break;
        }
        s++;
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