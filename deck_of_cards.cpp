#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    int cnt0, cnt1, cnt2;

    cnt0 = count(s.begin(), s.end(), '0');
    cnt1 = count(s.begin(), s.end(), '1');
    cnt2 = count(s.begin(), s.end(), '2');

    string ans(n, '+');

    for(int i = 0; i < n; i++) {
        if(cnt0 >= i+1) ans[i] = '-';
        else if(n-cnt1+1 <= i+1) ans[i] = '-';
        else if(cnt2 == n-cnt1-cnt0) ans[i] = '-';
        else if(cnt0+cnt2 >= i+1 || n-cnt1-cnt2+1 <= i+1) ans[i] = '?';
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;

    while(t--) solve();

    return 0;

}