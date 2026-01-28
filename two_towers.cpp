#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

void solve() {

    int n, m; cin >> n >> m;
    string s, r; cin >> s >> r;

    int cnt1 = 0, cnt2 = 0;
    char c1, c2;

    for(int i = 1; i < n; i++) {
        if(s[i] == s[i-1]) {
            c1 = s[i];
            cnt1++;
        }
    }

    for(int i = 1; i < m; i++) {
        if(r[i] == r[i-1]) {
            c2 = r[i];
            cnt2++;
        }
    }

    if(cnt1+cnt2 == 0) {
        cout << "YES" << '\n';
        return;
    }

    if(cnt1+cnt2 == 1) {
        if(cnt1 > 0 && s[n-1] != r[m-1]) {
            cout << "YES" << '\n';
        } else if(cnt2 > 0 && r[m-1] != s[n-1]) {
            cout << "YES" << '\n';
        } else cout << "NO" << '\n';
    } else cout << "NO" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}