#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<int> sega, segb;

    int cur = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == 1) cur++;
        else {
            if(cur) sega.push_back(cur);
            cur = 0;
        }
    }

    if(cur) sega.push_back(cur);

    cur = 0;

    for(int i = 0; i < m; i++) {
        if(b[i] == 1) cur++;
        else {
            if(cur) segb.push_back(cur);
            cur = 0;
        }
    }

    if(cur) segb.push_back(cur);

    sort(all(sega)); sort(all(segb));

    int sz1 = sega.size(), sz2 = segb.size();

    vector<int> pxa(sz1+1), pxb(sz2+1);

    partial_sum(all(sega), pxa.begin()+1);
    partial_sum(all(segb), pxb.begin()+1);

    int ans = 0;

    for(int i = 1; i*i <= k; i++) {

        int x = i, y = k/x;

        if(k%x != 0) continue;

        int j1 = lower_bound(all(sega), x)-sega.begin();
        int j2 = lower_bound(all(segb), y)-segb.begin();

        int cnta = (j1 == sz1 ? 0 : (pxa[sz1]-pxa[j1]));
        int cntb = (j2 == sz2 ? 0 : (pxb[sz2]-pxb[j2]));

        ans += max((cnta-(sz1-j1)*(x-1))*(cntb-(sz2-j2)*(y-1)), 0LL);

        if(x == y) continue;

        j1 = lower_bound(all(sega), y)-sega.begin();
        j2 = lower_bound(all(segb), x)-segb.begin();

        cnta = (j1 == sz1 ? 0 : (pxa[sz1]-pxa[j1]));
        cntb = (j2 == sz2 ? 0 : (pxb[sz2]-pxb[j2]));

        ans += max((cnta-(sz1-j1)*(y-1))*(cntb-(sz2-j2)*(x-1)), 0LL);

    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}