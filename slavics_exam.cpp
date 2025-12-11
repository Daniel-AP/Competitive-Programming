#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    string s, t; cin >> s >> t;

    int i = 0, j = 0;

    while(i < s.length() && j < t.length()) {
        if(s[i] == t[j] || s[i] == '?') s[i] = t[j], j++;
        i++;
    }

    if(j != t.length()) return void(cout << "NO" << '\n');

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '?') s[i] = 'a';
    }

    cout << "YES" << '\n';
    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}