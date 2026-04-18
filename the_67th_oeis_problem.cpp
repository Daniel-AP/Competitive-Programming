#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;
vector<int> primes{2};

void sieve(int n) {

    if(n <= 2) return;

    int m = n/2;
    vector<bool> s(m, true);

    for(int i = 3; i*i < n; i += 2) {
        if(s[i/2]) {
            for(int j = (i*i)/2; j < m; j += i) {
                s[j] = false;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        if(s[i]) primes.push_back(2*i+1);
    }

}

void solve() {

    int n; cin >> n;
    int prev = 1;

    cout << 1 << ' ';

    for(int i = 1; i < n; i++) {
        cout << prev*primes[i-1] << ' ';
        prev = primes[i-1];
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve(N);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}