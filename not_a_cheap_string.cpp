#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    string s; cin >> s;
    int p; cin >> p;
    int n = s.length();
    
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&](int i, int j) { return s[i] > s[j]; });

    int cur = 0;

    for(int i = 0; i < n; i++) {
        cur += (s[i]-'a'+1);
    }

    int i = 0;

    while(cur > p) {
        cur -= (s[ind[i]]-'a'+1);
        s[ind[i]] = '#';
        i++;
    }

    for(int i = 0; i < n; i++) {
        if(s[i] != '#') cout << s[i];
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