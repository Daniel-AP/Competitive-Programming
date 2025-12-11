#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

void solve() {

    string s, k; cin >> s >> k;

    int cnt = 0;

    for(int i = 0; i < min(s.length(), k.length()); i++) {
        if(s[i] != k[i]) break;
        cnt++;
    }

    cout << s.length()+k.length()-cnt+(cnt>0) << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}