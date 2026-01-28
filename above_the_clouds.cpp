#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    map<char, int> freq;

    for(int i = 0; i < n; i++) {
        freq[s[i]]++;
    }

    for(int i = 1; i < n-1; i++) {
        if(freq[s[i]] > 1) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}