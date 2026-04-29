#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k, d; cin >> n >> k >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> v(k);
    for(int i = 0; i < k; i++) cin >> v[i];

    int ans = 0;

    for(int i = 1; i <= min(2*n+1, d); i++) {

        vector<int> diff(n), b(n);
        int score = 0;

        for(int j = 0; j < i-1; j++) {
            diff[0]++;
            if(v[j%k] < n) diff[v[j%k]]--;
        }
        int cur = 0;
        for(int j = 0; j < n; j++) {
            cur += diff[j];
            b[j] = a[j]+cur;
        }
        int c = 0;
        for(int j = 0; j < n; j++) {
            if(b[j] == j+1) c++;
        }

        score += c;
        score += (d-i)/2;

        ans = max(ans, score);
        
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