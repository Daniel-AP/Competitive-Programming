#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;
    double vb, vs; cin >> vb >> vs;
    
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    int xu, yu; cin >> xu >> yu;
    int ans, d;
    double mn = 1e9;

    for(int i = 1; i < n; i++) {
        double d1 = x[i];
        double d2 = sqrt((x[i]-xu)*(x[i]-xu)+(0-yu)*(0-yu));
        double t = d1/vb+d2/vs;
        if(t < mn) {
            ans = i+1;
            mn = t;
            d = d2;
        } else if(t == mn && d2 < d) {
            ans = i+1;
            mn = t;
            d = d2;
        }
    }

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}