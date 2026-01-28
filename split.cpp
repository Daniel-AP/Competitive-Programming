#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;
    map<int, set<int>> mp;

    for(int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(freq[a[i]]%k != 0) return void(cout << 0 << '\n');
    }

    int l = 0, ans = 0;

    for(int i = 0; i < n; i++) {

        mp[a[i]].insert(i);

        if(mp[a[i]].size() > freq[a[i]]/k) {
            l = max((*mp[a[i]].begin())+1, l);
            mp[a[i]].erase(mp[a[i]].begin());
        }

        ans += i-l+1;

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}