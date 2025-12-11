#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp1;
    int c = 0;

    for(int i = 0; i < n; i++) {
        if(mp1.find(a[i]) == mp1.end()) mp1[a[i]] = c++;
        b[i] = mp1[a[i]];
    }

    int m; cin >> m;

    for(int i = 0; i < m; i++) {

        string s; cin >> s;
        string ans = "YES";

        map<int, int> mp2;
        int k = 0;

        if(s.length() != n) {
            cout << "NO" << '\n';
            continue;
        }

        for(int j = 0; j < s.length(); j++) {
            if(mp2.find(s[j]) == mp2.end()) mp2[s[j]] = k++;
            if(mp2[s[j]] != b[j]) ans = "NO";
        }

        cout << ans << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}