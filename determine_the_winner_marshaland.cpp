#include <bits/stdc++.h>
using namespace std;

#define int int
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000005;

vector<int> primes;
vector<int> ans(N);

void sieve(int n) {

    if(n <= 2) return;

    primes.reserve(50000);

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

    int k; cin >> k;

    vector<int> ans;

    for(int& p: primes) {
        if((k+2)%p == 0) ans.push_back(p);
    }

    if(ans.empty()) cout << -1 << '\n';
    else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " \n"[i==ans.size()-1];
        }
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve(N);

    while(t--) solve();

    return 0;

}