#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;

vector<bool> can(N+1);

void pre() {

    for(int k = 2; k <= N; k++) {
        int cur = k*k+k+1, cnt = k*k;
        if(cur > N) continue;
        can[cur] = 1;
        while(cnt*k+cur <= N) {
            cur += cnt*k, cnt *= k;
            can[cur] = 1;
        }
    }

}

void solve() {

    int n; cin >> n;
    
    if(can[n]) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}