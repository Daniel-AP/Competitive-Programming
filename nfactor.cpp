#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;
vector<int> spf(N+1);

array<vector<int>, 11> factor{};

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

void pre() {

    factor[0].push_back(1);

    for(int i = 2; i <= N; i++) {
        set<int> un;
        int x = i;
        while(spf[x]) un.insert(spf[x]), x /= spf[x];
        if(un.size() > 10) continue;
        factor[un.size()].push_back(i);
    }

}

void solve() {

    int a, b, n; cin >> a >> b >> n;

    int l = lower_bound(all(factor[n]), a)-factor[n].begin();
    int r = upper_bound(all(factor[n]), b)-factor[n].begin();

    cout << r-l << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve();
    pre();

    while(t--) solve();

    return 0;

}