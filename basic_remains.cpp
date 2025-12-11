#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int b) {

    string p, m; cin >> p >> m;

    int mm = 0;
    for(char ch: m) mm = mm*b+(ch-'0');

    int ans = 0;
    for(char ch: p) ans = (ans*b+(ch-'0'))%mm;

    string sans;

    while(ans) {
        sans += (ans%b+'0');
        ans /= b;
    }

    if(sans.empty()) sans = "0";

    reverse(sans.begin(), sans.end());

    cout << sans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(true) {
        int b; cin >> b;
        if(b == 0) break;
        solve(b);
    }

    return 0;

}