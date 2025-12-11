#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int t) {

    int n; cin >> n;
    int num = n*(n-1);

    cout << "Case " << t << ": ";

    if(num%4 == 0) cout << num/4;
    else if(num%2 == 0) cout << num/2 << '/' << 2;
    else cout << num << '/' << 4;

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1, tt = 0;
    cin >> t;

    while(tt++ < t) solve(tt);

    return 0;

}