#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "\nTime elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

const int N = 12000000;
vector<int> spf(N+1);

vector<int> ans;

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

void pre() {

    for(int i = 2; i <= N; i++) {
        if(spf[i] != spf[i/spf[i]] && spf[i/spf[i]] != 0 && i/(spf[i]*spf[i/spf[i]]) == 1) ans.push_back(i);
    }

}

void solve() {

    int k; cin >> k;

    cout << ans[k-1] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    sieve();
    pre();

    while(t--) solve();

    return 0;

}