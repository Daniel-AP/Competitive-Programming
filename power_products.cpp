#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

const int N = 100000;
vector<int> spf(N+1);

int binpow(int a, int b) {

    int ans = 1;

    while(b) {
        if(b&1) ans *= a;
        a *= a;
        b >>= 1;
    }

    return ans;

}

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

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<string, int> mp;
    int ans = 0;

    for(int i = 0; i < n; i++) {

        int m = a[i];
        string p, o;

        while(m > 1) {

            int s = spf[m], cnt = 0;
            while(m%s == 0) cnt++, cnt %= k, m /= s;

            if(!cnt) continue;

            p += to_string(s)+"#"+to_string(cnt)+",";
            o += to_string(s)+"#"+to_string((k-cnt)%k)+",";

        }

        ans += mp[o];
        mp[p]++;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    sieve();

    while(t--) solve();

    return 0;

}