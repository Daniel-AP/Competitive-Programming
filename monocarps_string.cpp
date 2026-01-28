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
    string s; cin >> s;

    map<int, int> mp;
    mp[0] = 0;

    int sm = 0;
    int k = count(s.begin(), s.end(), 'a')-count(s.begin(), s.end(), 'b');
    int ans = n;

    if(k == 0) return void(cout << 0 << '\n');

    for(int i = 0; i < n; i++) {

        if(s[i] == 'a') sm++;
        else sm--;

        if(mp.find(sm-k) != mp.end()) ans = min(ans, i-mp[sm-k]+1);

        mp[sm] = i+1;

    }

    cout << (ans == n ? -1 : ans) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}