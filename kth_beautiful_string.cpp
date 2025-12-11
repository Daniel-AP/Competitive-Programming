#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    
    int t; cin >> t;
    
    while(t--) {
        
        int n, k; cin >> n >> k;
        int a, b;
    
        for(int i = 1; i < n; i++) {
            if((i*(i+1))/2 >= k) {
                a = n-i-1;
                b = k-((i-1)*i)/2;
                break;
            }
        }
            
        string ans;
        for(int i = 0; i < n; i++) {
            if(i != a && i != b) {
                ans += 'a';
            } else {
                ans += 'b';
            }
        }
    
        cout << ans << endl;
            
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}