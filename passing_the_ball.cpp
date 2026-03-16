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

    set<int> has;

    has.insert(1);
    int cur = 1;

    while(n--) {
        if(s[cur-1] == 'L') {
            cur--;
        } else {
            cur++;
        }
        has.insert(cur);
    }

    cout << has.size() << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}