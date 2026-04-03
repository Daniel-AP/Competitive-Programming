#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve() {

    int a, b; cin >> a >> b;
    int g = gcd(a, b);

    int ans = 1;

    while(spf[g]) {
        int sp = spf[g], e = 0;
        while(g%sp == 0) e++, g /= sp;
        ans *= (e+1);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve();

    while(t--) solve();

    return 0;

}