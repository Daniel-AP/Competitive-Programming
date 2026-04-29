#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 100000001;
const int M = 50000000;

vector<int> primes{{0, 2}};
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

    for(int i = 1; i <= primes.size(); i += 100) cout << primes[i] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    sieve();

    while(t--) solve();

    return 0;

}