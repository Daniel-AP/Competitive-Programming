#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

map<int, int> primeFactors(int n) {

    map<int, int> factors;

    while(n%2 == 0) {
        factors[2]++;
        n /= 2;
    }

    while(n%3 == 0) {
        factors[3]++;
        n /= 3;
    }

    for(int i = 5; i*i <= n; i += 6) {
        while(n%i == 0) {
            factors[i]++;
            n /= i;
        }
        while(n%(i+2) == 0) {
            factors[i+2]++;
            n /= (i+2);
        }
    }

    if(n != 1) factors[n]++;

    return factors;

}

int binpow(int a, int b) {

    int ans = 1;

    while(b) {
        if(b%2) ans *= a;
        a *= a;
        b /= 2;
    }

    return ans;

}

void solve() {

    int n; cin >> n;
    map<int, int> factors = primeFactors(n);

    int ans = 1;

    for(auto& [p, cnt]: factors) {
        ans *= binpow(p, (cnt+n-1)/n);
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}