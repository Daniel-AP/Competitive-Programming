#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

const int N = 2000000;

vector<int> spf(N+1);

void sieve() {

    for(int i = 1; i <= N; i++) spf[i] = i;
    for(int i = 2; i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

}

int binpow(int a, int b) {

    int ans = 1;

    while(b > 0) {
        if(b&1) ans *= a;
        a *= a;
        b >>= 1;
    }

    return ans;
    
}

void solve() {

    map<int, vector<int>> p;

    int n; cin >> n;
   
    for(int i = 0; i < n; i++) {
        
        int x; cin >> x;

        while(x > 1) {

            int d = spf[x], cnt = 0;

            while(x%d == 0) x /= d, cnt++;

            p[d].push_back(cnt);

        }

    }

    for(int i = 1; i <= N; i++) {
        sort(p[i].begin(), p[i].end());
    }

    int ans = 1;

    for(int i = 2; i <= N; i++) {

        int diff = n-p[i].size();

        if(diff >= 2) continue;
        
        if(diff == 1) ans *= binpow(i, p[i][0]);
        if(diff == 0) ans *= binpow(i, p[i][1]);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sieve();

    int t; t = 1;

    while(t--) solve();

    return 0;

}