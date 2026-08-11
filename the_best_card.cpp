#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

bool isPrime(int n) {

    if(n <= 3) return n > 1;

    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6) {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }

    return true;

}

void solve() {

    int n; cin >> n;
    int g = 2;

    for(int i = 3; i <= n+1; i++) g = gcd(g, i);

    if(g == 2 || isPrime(n+1)) cout << "YES";
    else cout << "NO";

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