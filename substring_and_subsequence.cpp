#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

bool is_subsequence(string a, string b) {

    int n=a.length(), m=b.length(), j=0;

    for(int i = 0; i < n; i++) {
        if(j == m) break;
        if(a[i] == b[j]) j++;
    }

    return j == m;

}

void solve() {

    string a, b; cin >> a >> b;
    int n = a.length(), m = b.length();

    int mx = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 1; i+j-1 < m; j++) {
            if(is_subsequence(a, b.substr(i, j))) mx = max(mx, j);
        }
    }
    
    cout << n+(m-mx) << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}