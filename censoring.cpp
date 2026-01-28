#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

int f(string s, string t) {

    int n = s.length(), m = t.length();
    int j = 0, start = INF;

    for(int i = 0; i < n; i++) {
        if(s[i] == '#') continue;
        if(j == m) break;
        if(s[i] == t[j]) {
            start = min(start, i);
            j++;
        } else if(s[i] == t[0]) {
            start = i;
            j = 1;
        } else {
            start = INF;
            j = 0;
        }
    }

    if(j != m) start = INF;

    return start;

}

void solve() {

    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();

    int k = f(t, s);
    cout << k << endl;

    while(k != INF) {
        int cnt = 0;
        for(int i = k; cnt < m; i++) {
            if(s[i] == '#') continue;
            s[i] = '#';
            cnt++;
        }
        k = f(t, s);
    }

    for(int i = 0; i < n; i++) {
        if(s[i] != '#') cout << s[i];
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    // freopen("censor.in", "r", stdin);
    // freopen("censor.out", "w", stdout);

    while(t--) solve();

    return 0;

}