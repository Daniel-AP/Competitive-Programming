#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string sn = to_string(n);

    int ans = INF;

    for(int i = 1; i*i <= n; i++) {

        string s = to_string(i*i);
        int k = 0;

        for(int j = 0; j < sn.length() && k < s.length(); j++) {
            if(sn[j] == s[k]) k++;
        }

        if(k != s.size()) continue;

        ans = min(ans, (int)sn.size()-(int)s.size());

    }

    cout << (ans == INF ? -1 : ans);
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}