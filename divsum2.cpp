#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

const int N = 100000000;
const int M = 50000000;

vector<int> primes;
bitset<M> s;

void sieve() {

    s.set();

    for(int i = 3; i*i < N; i += 2) {
        if(s[i/2]) {
            for(int j = (i*i)/2; j < M; j += i) {
                s[j] = false;
            }
        }
    }

    for(int i = 1; i < M; i++) {
        if(s[i]) primes.push_back(2*i+1);
    }

}

void solve() {

    int n; cin >> n;
    int ans = 1, m = n;

    for(int p: primes) {
        if(p*p > n) break;
        if(n%p != 0) continue;
        int cur = p;
        while(n%p == 0) cur *= p, n /= p;
        ans *= (cur-1)/(p-1);
    }

    if(n > 1) ans *= n+1;

    cout << ans-m << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    // START_TIMER;

    primes.reserve(5761500);
    primes.push_back(2);
    sieve();

    while(t--) solve();

    // END_TIMER;

    return 0;

}