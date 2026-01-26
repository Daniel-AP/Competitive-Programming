#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, d; cin >> n >> d;

    vector<long double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    long double l = 0, r = 100, mid;
    pair<int, int> ans;

    for(int i = 0; i < 100; i++) {

        mid = l+(r-l)/2;

        vector<long double> px(n+1);
        for(int j = 1; j <= n; j++) px[j] = px[j-1]+(a[j-1]-mid);

        int lb = 0;
        pair<int, int> best{-1, -1};

        for(int j = d; j <= n; j++) {
            if(px[lb] > px[j-d]) lb = j-d;
            if((best.first == -1 && best.second == -1) || px[j]-px[lb] > px[best.second]-px[best.first]) best = {lb, j};
        }

        if(best.first != -1 && best.second != -1 && px[best.second]-px[best.first] >= -1e-9) {
            ans = best;
            l = mid;
        } else {
            r = mid;
        }

    }

    cout << ans.first+1 << ' ' << ans.second << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}