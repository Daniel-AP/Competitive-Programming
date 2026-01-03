#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(string n) {

    int k = n.length();
    int cur = 1, ans = 0;

    for(int i = k-1; i >= 0; i--) {
        ans += (n[i]-'0')*cur;
        cur *= 2;
        cur++;
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string n;

    while(true) {
        cin >> n;
        if(n == "0") break;
        solve(n);
    }

    return 0;

}