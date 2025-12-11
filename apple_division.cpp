#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int s = 0, ans = LLONG_MAX;
    for(int i = 0; i < n; i++) s += a[i];

    if(n == 1) {
        cout << a[0] << endl;
        return;
    }

    for(int i = 1; i <= n; i++) {

        vector<bool> select(n);
        fill(select.begin(), select.begin()+i, true);

        do {

            int t = 0;
            for(int i = 0; i < n; i++) if(select[i]) t += a[i];

            ans = min(ans, abs(s/2-t));
            
        } while(prev_permutation(select.begin(), select.end()));

    }

    cout << ans*2+s%2 << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}