#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, k; cin >> n >> k;

    vector<int> s(n), t(n);

    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];

    map<int, int> f1, f2;
    for(int i = 0; i < n; i++) f1[t[i]%k]++;

    for(int i = 0; i < n; i++) {
        if(f1.find(s[i]%k) != f1.end() && f1.find(k-s[i]%k) != f1.end()) {
            if(f1[s[i]%k]-f2[s[i]%k] > f1[k-s[i]%k]-f2[k-s[i]%k]) {
                f2[s[i]%k]++;
            } else {
                f2[k-s[i]%k]++;
            }
        } else if(f1.find(s[i]%k) != f1.end()) {
            f2[s[i]%k]++;
        } else if(f1.find(k-s[i]%k) != f1.end()) {
            f2[k-s[i]%k]++;
        }
    }

    for(auto [k, v]: f1) {
        if(v != f2[k]) return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}