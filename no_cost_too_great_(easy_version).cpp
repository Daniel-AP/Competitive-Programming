#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

const int N = 200005;

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

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    map<int, bool> p;

    for(int i = 0; i < n; i++) {

        set<int> s;
        int x = a[i];

        while(spf[x]) {
            s.insert(spf[x]);
            x /= spf[x];
        }

        for(int pd: s) {
            if(p.find(pd) != p.end()) return void(cout << 0 << '\n');
            p[pd] = 1;
        }

    }

    for(int i = 0; i < n; i++) {

        set<int> s;
        int x = a[i]+1;

        while(spf[x]) {
            s.insert(spf[x]);
            x /= spf[x];
        }

        for(int pd: s) {
            if(p.find(pd) != p.end()) return void(cout << 1 << '\n');
        }

    }

    cout << 2 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}