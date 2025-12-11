#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;

    int s = 0;
    for(int i = 0; i < n; i++) s += a[i];

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        int ss = s-a[i];
        if(ss&1) continue;
        cnt[a[i]]--;
        if(cnt[ss/2]) ans.push_back(i+1);
        cnt[a[i]]++;
    }

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}