#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";
 
#define MOD 1000000007

const int N = 1000000;
vector<int> spf(N+1);

int binpow(int b, int e) {

    int res = 1;

    while(e > 0) {
        if(e&1) res = (res*b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }

    return res;

}

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
 
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
 
    vector<bool> visited(n);
    vector<int> cycles;
    queue<int> q;
 
    for(int i = 0; i < n; i++) {
 
        if(visited[i]) continue;
        q.push(i);
 
        int cnt = 0;
 
        while(!q.empty()) {
            int k = q.front(); q.pop();
            cnt++;
            visited[k] = 1;
            if(!visited[p[k]-1]) q.push(p[k]-1); 
        }
 
        cycles.push_back(cnt);
 
    }
 
    map<int, int> primes;

    for(int x: cycles) {
        while(spf[x]) {
            int cnt = 0, s = spf[x];
            while(x%s == 0) cnt++, x /= s;

            primes[s] = max(primes[s], cnt);

        }
    }

    int ans = 1;

    for(auto [k, v]: primes) {
        ans = (ans*binpow(k, v))%MOD;
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