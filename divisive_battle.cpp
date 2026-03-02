#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

const int N = 1000000;
vector<int> spf(N+1);

void sieve() {

    for(int i = 2; i <= N; i++) spf[i] = i;

    for(int i = 2; i*i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    if(is_sorted(all(a))) return void(cout << "Bob" << '\n');

    for(int i = 0; i < n; i++) {
        int x = a[i], mx = 1;
        if(x == 1) continue;
        while(spf[x]) mx = max(mx, spf[x]), x /= spf[x];
        if(mx > spf[a[i]]) return void(cout << "Alice" << '\n');
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) continue;
        a[i] = spf[a[i]];
    }

    if(is_sorted(all(a))) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}