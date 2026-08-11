#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

pair<int, int> factors(int n) {

    int ans = 0;
    int diff = 0;

    if(n%2 == 0) diff++;
    while(n%2 == 0) {
        ans++;
        n /= 2;
    }
    
    if(n%3 == 0) diff++;
    while(n%3 == 0) {
        ans++;
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        if(n%i == 0) diff++;
        while(n%i == 0) {
            ans++;
            n /= i;
        }
        if(n%(i+2) == 0) diff++;
        while(n%(i+2) == 0) {
            ans++;
            n /= (i+2);
        }
    }

    if(n != 1) ans++, diff++;

    return {ans, diff};

}

void solve() {

    int n; cin >> n;
    auto [cnt, diff] = factors(n);

    cout << cnt+diff-1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}