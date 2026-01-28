#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n; cin >> n;
    double d, h; cin >> d >> h;

    vector<double> y(n);
    for(double i = 0; i < n; i++) cin >> y[i];

    double ans = 0.0;

    for(int i = 0; i < n-1; i++) {

        ans += d*h/2.0;

        if(y[i]+h > y[i+1]) {

            double diff1 = y[i]+h-y[i+1];
            double diff2 = y[i+1]-y[i];
            double b = d*(h-diff2)/(diff1+diff2);

            ans -= b*diff1/2.0;

        }
    }

    ans += d*h/2.0;

    cout << fixed << setprecision(7) << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}