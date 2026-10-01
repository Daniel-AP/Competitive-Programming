#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans1 = INF, ans2 = INF;
    int mx = *max_element(all(h));

    int even = 0, odd = 0;

    for(int i = 0; i < n; i++) {
        if(h[i]%2) odd++;
        else even++;
    }

    int tot1 = 0;
    for(int i = 0; i < n; i++) tot1 += mx-h[i];

    int diff1 = (mx%2 ? even : odd);
    
    ans1 = 2*diff1-1;
    tot1 -= min(diff1, tot1);
    tot1 -= min(2*(diff1-1), tot1);

    ans1 += tot1/3*2;
    ans1 += (tot1%3 != 0);

    int tot2 = 0;
    for(int i = 0; i < n; i++) tot2 += (mx+1)-h[i];

    int diff2 = (mx%2 ? odd : even);

    ans2 = 2*diff2-1;
    tot2 -= min(diff2, tot2);
    tot2 -= min(2*(diff2-1), tot2);

    ans2 += tot2/3*2;
    ans2 += (tot2%3 != 0);

    cout << min(ans1, ans2) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}