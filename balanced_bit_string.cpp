#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> diff(n);

    for(int i = 0; i < n; i++) {
        if(s[i] != '1') continue;
        diff[max(i, k-1)]++;
        if(i+k < n) diff[i+k]--;
    }

    vector<int> bad(k, INF);

    for(int i = 0; i < n; i++) {
        if(bad[(i+1)%k] != INF) continue;
        if(s[i] != '?') bad[(i+1)%k] = i;
    }

    for(int i = k; i < n; i++) {
        if(diff[i] == 1) {
            if(bad[(i+1)%k] >= i) {
                bad[(i+1)%k] = -1;
                diff[k-1]++;
                diff[i] = 0;
            } else return void(cout << "NO" << '\n');
        } else if(diff[i] == -1) {
            if(s[i] == '?') {
                diff[i]++;
                if(i+k < n) diff[i+k]--;
            } else return void(cout << "NO" << '\n');
        }
    }

    
    int cur = 0;
    for(int i = 0; i < k; i++) cur += diff[i];
    
    for(int i = 0; i < k; i++) {
        if(bad[(i+1)%k] == INF && cur < k/2) cur++;
    }

    bool can = (cur==k/2);

    for(int i = k; i < n; i++) can &= (diff[i]==0);

    cout << (can ? "YES" : "NO") << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}