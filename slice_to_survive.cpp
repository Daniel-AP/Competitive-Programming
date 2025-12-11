using namespace std;
#include <bits/stdc++.h>

#define int unsigned long long
#define INF (1LL<<60)

void solve() {

    int n, m, a, b; cin >> n >> m >> a >> b;
    
    int k = ceill(log2l(min(b, m-b+1)))+ceill(log2l(n))+1;
    int q = ceill(log2l(min(a, n-a+1)))+ceill(log2l(m))+1;

    cout << min(k, q) << "\n";
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

} 
