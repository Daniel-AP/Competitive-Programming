#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve(int n) {

    bitset<64> bs(n);
    string s = bs.to_string();

    s.erase(0, s.find('1'));

    cout << "The parity of " << s << " is " << bs.count() << " (mod 2)." << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        solve(n);
    }

    return 0;

}