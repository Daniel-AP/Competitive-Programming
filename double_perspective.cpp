#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> ab(n);
    for(int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;

    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if(ab[i].first >= ab[j].first && ab[i].second <= ab[j].second) cnt[i]++;
        }
    }

    cout << count(cnt.begin(), cnt.end(), 0) << '\n';

    for(int i = 0; i < n; i++) {
        if(cnt[i] == 0) cout << i+1 << ' ';
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}