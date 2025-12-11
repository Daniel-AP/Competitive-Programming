#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;
vector<int> spf(N+1);

void sieve() {

    for(int i = 2; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

void solve() {

    int n; cin >> n;
    map<int, int> mp;

    for(int i = 0; i < n; i++) {
        
        int x; cin >> x;

        while(spf[x]) {
            mp[spf[x]]++;
            mp[spf[x]] %= n;
            x /= spf[x];
        }
        
    }

    for(auto [k, v]: mp) {
        if(v != 0) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}