#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

vector<int> primes;

void sieve(int n) {

    if(n <= 2) return;

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) primes.push_back(i);
    }

}

void solve() {

    int n; cin >> n;
    int ans = 0;

    for(int p: primes) {
        if(p > n) break;
        ans += n/p;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve(10000000);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}