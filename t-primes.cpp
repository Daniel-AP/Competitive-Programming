#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000005;
const int M = 500002;

vector<int> primes{4};
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
        if(s[i]) primes.push_back((2*i+1)*(2*i+1));
    }

}

void solve() {

    int n; cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    for(int i = 0; i < n; i++) {
        if(binary_search(all(primes), x[i])) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t = 1;

    while(t--) solve();

    return 0;

}