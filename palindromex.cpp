#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<pair<int, int>> a(n, {-1, -1});
    vector<int> b(2*n);

    for(int i = 0; i < 2*n; i++) {
        int x; cin >> x;
        b[i] = x;
        if(a[x].first == -1) a[x].first = i;
        else a[x].second = i;
    }

    sort(all(a));

    int fi = 0;
    int cnt = 1, ans = 1;

    for(int i = 1; i < n; i++) {
        if(a[i].first == a[fi].first+cnt && a[i].second == a[fi].second-cnt) cnt++;
        else if(a[i-1].second-a[i-1].first <= 2) {
            set<int> s;
            for(int j = a[fi].first; j <= a[fi].second; j++) s.insert(b[j]);
            int mex = 0;
            while(s.find(mex) != s.end()) mex++;
            if(mex > ans) ans = mex;
            fi = i;
            cnt = 1;
        } else {
            fi = i;
            cnt = 1;
        }
    }

    if(a[n-1].second-a[n-1].first <= 2) {
        set<int> s;
        for(int j = a[fi].first; j <= a[fi].second; j++) s.insert(b[j]);
        int mex = 0;
        while(s.find(mex) != s.end()) mex++;
        if(mex > ans) ans = mex;
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