#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

int sss(string ss, int n, char c) {

    vector<int> as(n), bs(n);
    int ans = 0;

    as[0] = (ss[0] == 'a');
    bs[0] = (ss[0] == 'b');

    for(int i = 1; i < n; i++) {
        as[i] = as[i-1]+(ss[i] == 'a');
        bs[i] = bs[i-1]+(ss[i] == 'b');
    }

    for(int i = 0; i < n; i++) {
        if(ss[i] != c) continue;
        if(c == 'b') {
            ans += min(as[i], as[n-1]-as[i]);
        } else {
            ans += min(bs[i], bs[n-1]-bs[i]);
        }
    }

    return ans;

}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int la = s.find('a'), ra = s.rfind('a');
    int lb = s.find('b'), rb = s.rfind('b');

    if(la != string::npos && lb != string::npos) {

        string s1 = s.substr(la, ra-la+1);
        string s2 = s.substr(lb, rb-lb+1);

        cout << min(sss(s1, s1.length(), 'b'), sss(s2, s2.length(), 'a')) << '\n';

    } else {

        cout << 0 << '\n';

    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}