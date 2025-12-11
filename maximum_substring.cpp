#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 119*(1LL<<23)+1

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int cnt1 = 0, cnt0 = 0;
    int mx1 = 0, mx0 = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt1++;
            mx1 = max(mx1, cnt1);
            mx0 = max(mx0, cnt0);
            cnt0 = 0;
        } else {
            cnt0++;
            mx1 = max(mx1, cnt1);
            mx0 = max(mx0, cnt0);
            cnt1 = 0;
        }
    }

    int x = count(s.begin(), s.end(), '0');
    int y = count(s.begin(), s.end(), '1');

    cout << max({ mx1*mx1, mx0*mx0, x*y }) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}