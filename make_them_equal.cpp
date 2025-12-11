#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;

    if(count(s.begin(), s.end(), c) == n) return void(cout << 0 << '\n');
    
    set<int> st;

    for(int i = 0; i < n; i++) {
        if(s[i] == c) continue;
        int x = i+1;
        for(int j = 1; j*j <= x; j++) {
            if(x%j != 0) continue;
            st.insert(j);
            st.insert(x/j);
        } 
    }

    for(int i = n; i >= 2; i--) {
        if(st.find(i) == st.end()) {
            return void(cout << 1 << '\n' << i << '\n');
        }
    }

    cout << 2 << '\n';
    cout << n << ' ' << n-1 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}