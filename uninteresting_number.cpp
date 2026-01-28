#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    string n; cin >> n;

    int s = 0, ts = 0, tws = 0;

    for(int i = 0; i < n.length(); i++) {
        s += (n[i]-'0');
        if((n[i]-'0') == 2) tws++;
        if((n[i]-'0') == 3) ts++;
    }

    bool can = false;

    for(int i = (s+8)/9*9-s; i <= ts*6+tws*2; i += 9) {

        if(i%2 == 1) continue;

        int k = i;

        k -= min(k/6, ts)*6;
        k -= min(k/2, tws)*2;

        if(k == 0) can = true;

    }

    if(can) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}