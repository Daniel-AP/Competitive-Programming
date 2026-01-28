#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, x, k; cin >> n >> x >> k;
    string s; cin >> s;

    vector<int> acc(n);
    acc[0] = (s[0] == 'L' ? -1 : 1);

    for(int i = 1; i < n; i++) {
        acc[i] = acc[i-1]+(s[i] == 'L' ? -1 : 1);
    }

    int idx = find(acc.begin(), acc.end(), -x)-acc.begin();

    if(idx == n || idx+1 > k) return void(cout << 0 << '\n');

    int ans = 1;
    k -= idx+1;

    idx = find(acc.begin(), acc.end(), 0)-acc.begin();

    if(idx == n) return void(cout << ans << '\n');

    ans += k/(idx+1);

    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}