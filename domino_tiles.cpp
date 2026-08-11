#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    int ans = 1, cnt0 = 0, cnt1 = 0;
    
    for(int i = 0; i < n; i += 2) {
        if(s[i] == '?') {
            cnt0++;
            continue;
        }
        if(i+2 < n && s[i] == s[i+2]) return void(cout << 0 << '\n');
    }

    for(int i = 1; i < n; i += 2) {
        if(s[i] == '?') {
            cnt1++;
            continue;
        }
        if(i+2 < n && s[i] == s[i+2]) return void(cout << 0 << '\n');
    }

    if(cnt0 == (n+1)/2) {
        ans *= 2;
    } else {
        int j = -1;
        for(int i = 0; i < n; i += 2) {
            if(s[i] == '?') continue;
            if(j == -1) {
                j = i;
                continue;
            }
            int d = i-j;
            if(d%4 == 0) {
                if(s[j] != s[i]) return void(cout << 0 << '\n');
            } else if(d%2 == 0) {
                if(s[j] == s[i]) return void(cout << 0 << '\n');
            }
        }
    }

    if(cnt1 == n/2) {
        ans *= 2;
    } else {
        int j = -1;
        for(int i = 1; i < n; i += 2) {
            if(s[i] == '?') continue;
            if(j == -1) {
                j = i;
                continue;
            }
            int d = i-j;
            if(d%4 == 0) {
                if(s[j] != s[i]) return void(cout << 0 << '\n');
            } else if(d%2 == 0) {
                if(s[j] == s[i]) return void(cout << 0 << '\n');
            }
        }
    }
    
    cout << ans << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}