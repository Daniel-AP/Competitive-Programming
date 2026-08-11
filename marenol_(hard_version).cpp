#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string a, b; cin >> a >> b;

    array<int, 2> cnt{};

    for(int i = 0; i < n; i++) {
        cnt[i%2] += (a[i]=='1');
    }

    for(int i = 0; i < n; i++) {
        cnt[i%2] -= (b[i]=='1');
    }

    if(cnt[0] != 0 || cnt[1] != 0) return void(cout << -1 << '\n');

    vector<int> oneseven, onesodd;

    for(int i = 0; i < n; i++) {
        if(a[i] == '0') continue;
        if(i%2) onesodd.push_back(i);
        else oneseven.push_back(i);
    }

    int ans = 0;

    for(int i = n-1; i >= 0; i--)  {
        if(b[i] == '0') continue;
        if(i%2) {
            ans += abs(onesodd.back()-i)/2;
            onesodd.pop_back();
        } else {
            ans += abs(oneseven.back()-i)/2;
            oneseven.pop_back();
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