#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int even = 0, odd = 0, s = 0;

    for(int i = 0; i < n; i++) {
        if(a[i]%2 == 0) even++;
        else odd++;
        s += a[i];
    }

    int mx = *max_element(a.begin(), a.end());

    if(even == 0 || odd == 0) {
        cout << mx << "\n";
        return;
    }

    cout << s-odd+1 << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}