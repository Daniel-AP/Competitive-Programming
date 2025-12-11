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
    int n = s.length();

    for(int i = 0; i < n; i++) {
        string ss = s.substr(0, i+1);
        set<char> st(ss.begin(), ss.end());
        string fs = string(st.begin(), st.end());
        if(ss+fs == s) return void(cout << i+1); 
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}