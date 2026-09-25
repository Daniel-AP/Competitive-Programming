#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> diff(n);
    vector<bool> can(n, 1);

    for(int i = 0; i < n; i++) {
        if(b[i] == -1 || b[i] == 0) continue;
        diff[max(i-b[i]+1, 0LL)]++;
        if(i+b[i] < n) diff[i+b[i]]--;
    }

    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += diff[i];
        can[i] = (cur==0);
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == 0 && !can[i]) return void(cout << -1 << '\n');
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == -1 || b[i] == 0) continue;
        bool canl = (i-b[i] >= 0 && can[i-b[i]]);
        bool canr = (i+b[i] < n && can[i+b[i]]);
        if(!canl && !canr) return void(cout << -1 << '\n');
        if(canl) b[i-b[i]] = 0;
        if(canr) b[i+b[i]] = 0;
    }

    if(count(all(b), 0) == 0) {
        for(int i = 0; i < n; i++) {
            if(can[i]) {
                b[i] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] == 0) cout << 1;
        else cout << 0;
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}