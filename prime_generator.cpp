#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

vector<int> sieve(int n) {

    if(n <= 1) return {};

    int m = n/2;
    vector<bool> s(m, true);
    vector<int> primes{2};

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

    return primes;

}

void solve() {

    int m, n; cin >> m >> n;
    int r = sqrt(n)+1;

    vector<int> primes = sieve(r+1);
    vector<bool> s(n-m+1, true);

    for(int p: primes) {
        for(int j = max((m+p-1)/p*p, 2*p); j <= n; j += p) {
            s[j-m] = false;
        }
    }

    for(int i = 0; i < n-m+1; i++) {
        if(s[i] && i+m > 1) cout << i+m << '\n';
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
        cout << '\n';
    }

    return 0;

}