#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    string s; cin >> s;
    int n = s.length();

    for(int i = 1; i < n; i++) {
        
        int val = s[i]-'0';

        for(int j = 0; j < val; j++) {

            if(i-j-1 < 0) break;
            if(s[i-j]-1 <= s[i-j-1]) break;

            swap(s[i-j], s[i-j-1]);

            s[i-j-1]--;

        }

    }

    cout << s << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}