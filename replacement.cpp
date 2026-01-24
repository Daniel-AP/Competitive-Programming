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
    string r; cin >> r;

    int cnt0 = count(all(s), '0');
    int cnt1 = count(all(s), '1');

    for(int i = 0; i < n-1; i++) {
        if(cnt0 == 0 || cnt1 == 0) return void(cout << "NO"<< '\n');
        if(r[i] == '0') {
            cnt1--;
        } else {
            cnt0--;
        }
    }

    cout << "YES" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}