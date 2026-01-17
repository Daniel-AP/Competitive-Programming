#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int t) {

    int n; cin >> n;
    string ans;

    while(n >= 2 || n < 0) {
        int r = (n%(-2)-2)%(-2);
        if(n > 0) n = -(n+1)/2;
        else n /= -2;
        if(r < 0) {
            n++;
            r += 2;
        }
        ans += char(r+'0');
    }

    reverse(all(ans));
    ans = char(n+'0')+ans;

    cout << "Case #" << t << ": " << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    for(int i = 1; i <= t; i++) solve(i);

    return 0;

}