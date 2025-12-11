#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n; cin >> n;

    if(n == 6) {
        cout << "1 1 2 3 1 2" << "\n";
    } else if(n == 7) {
        cout << "1 1 2 3 1 2 2" << "\n";
    } else if(n == 8) {
        cout << "1 1 2 3 1 2 4 2" << "\n";
    } else if(n < 24) {
        cout << "7 3 3 7 5 3 7 7 3 ";
        for(int i = 0; i < n-9; i++) cout << 8+i << " ";
        cout << "\n";
    } else {
        cout << "15 8 8 8 15 5 8 1 15 5 8 15 15 15 8 ";
        for(int i = 0; i < n-15; i++) cout << 16+i << " ";
        cout << "\n";
    }
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}