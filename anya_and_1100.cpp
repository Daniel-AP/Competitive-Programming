#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    string s; cin >> s;
    int q; cin >> q;
    int n = s.length();

    set<int> has;

    for(int i = 0; i+3 < n; i++) {
        if(s.substr(i, 4) == "1100") has.insert(i);
    }

    while(q--) {

        int i; cin >> i;
        char v; cin >> v;

        s[--i] = v;

        int good = false, pos = -1;

        if(i+3 < n && s.substr(i, 4) == "1100") good = true, pos = i;
        if(i+2 < n && i-1 >= 0 && s.substr(i-1, 4) == "1100") good = true, pos = i-1;
        if(i+1 < n && i-2 >= 0 && s.substr(i-2, 4) == "1100") good = true, pos = i-2;
        if(i < n && i-3 >= 0 && s.substr(i-3, 4) == "1100") good = true, pos = i-3;

        has.erase(i);
        has.erase(i-1);
        has.erase(i-2);
        has.erase(i-3);

        if(good) has.insert(pos);

        cout << (has.empty() ? "NO" : "YES") << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}