#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, p; cin >> n >> p;

    vector<int> a(2*n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n; i < 2*n; i++) a[i] = a[i-n];

    vector<int> px(2*n+1);
    partial_sum(all(a), px.begin()+1);

    int start = 0, size = INF;

    for(int l = 1; l <= 2*n; l++) {
        for(int r = l; r <= 2*n; r++) {
            if(p <= px[r]-px[l-1] && size > r-l+1) size = r-l+1, start = (l%n == 0 ? n : l%n);
            else if(size > r-l+1+(p-(px[r]-px[l-1])+px[n]-1)/px[n]*n) size = r-l+1+(p-(px[r]-px[l-1])+px[n]-1)/px[n]*n, start = (l%n == 0 ? n : l%n);
        }
    }

    cout << start << ' ' << size << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}