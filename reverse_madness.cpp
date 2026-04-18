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

    vector<int> l(k), r(k);

    for(int i = 0; i < k; i++) cin >> l[i];
    for(int i = 0; i < k; i++) cin >> r[i];

    vector<int> diff(n);

    int q; cin >> q;

    while(q--) {
        int x; cin >> x;
        int i = upper_bound(all(l), x)-l.begin()-1;
        if(i < 0 || l[i] > x || r[i] < x) continue;
        diff[min(x, l[i]+r[i]-x)-1]++;
        if(max(x, l[i]+r[i]-x) < n) diff[max(x, l[i]+r[i]-x)]--;
    }

    vector<int> px(n+1);
    partial_sum(all(diff), px.begin()+1);

    for(int i = 0; i < k; i++) {
        for(int j = l[i]; j <= (l[i]+r[i])/2; j++) {
            if(px[j]%2 == 0) continue;
            swap(s[j-1], s[l[i]+r[i]-j-1]);
        }
    }

    cout << s << '\n';

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}