#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int t; cin >> t;

    while(t--) {

        int n, w; cin >> n >> w;

        vector<int> a(n), ind(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int x, int y) {
            return a[x] < a[y];
        });

        sort(a.begin(), a.end());

        int i = lower_bound(a.begin(), a.end(), w+1)-a.begin()-1;
        
        int s = 0;
        vector<int> ans;

        for(int j = i; j >= 0; j--) {
            s += a[j];
            ans.push_back(ind[j]+1);
            if(s >= (w+1)/2) break;
        }


        if(s >= (w+1)/2) {
            cout << ans.size() << endl;
            for(int v: ans) cout << v << " ";
        } else {
            cout << -1;
        }

        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}