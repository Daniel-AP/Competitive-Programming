#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int ones = count(s.begin(), s.end(), '1');
    
    if(ones%2 == 1) return void(cout << "NO" << '\n');

    if(ones == 2) {
        int idx = s.find('1');
        if(s[idx+1] == '1') return void(cout << "NO" << '\n');
    }

    cout << "YES" << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}