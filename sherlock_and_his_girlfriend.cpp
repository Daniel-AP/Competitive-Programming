#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

vector<bool> s;

void sieve(int n) {

    if(n <= 2) return;

    s.assign(n, true);

    for(int i = 2; i*i < n; i++) {
        if(s[i]) {
            for(int j = 2*i; j < n; j += i) {
                s[j] = false;
            }
        }
    }

}

void solve() {

    int n; cin >> n;

    if(n <= 2) {
        cout << 1 << '\n';
        for(int i = 0; i < n; i++) cout << 1 << ' ';
        cout << '\n';
        return;
    } 

    sieve(n+2);

    cout << 2 << '\n';
    for(int i = 2; i <= n+1; i++) {
        if(s[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}