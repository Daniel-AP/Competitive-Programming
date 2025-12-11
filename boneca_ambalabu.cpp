#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

int bit_width(int x) {
    if(x == 0) return 0;
    int ans = log2(x);
    return ans+1;
}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int mx_bit_width = 0;

        for(int i = 0; i < n; i++) {
            mx_bit_width = max(mx_bit_width, bit_width(a[i]));
        }

        vector<int> rep(mx_bit_width);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < mx_bit_width; j++) {
                rep[j] += (a[i]>>j)&1;
            }
        }

        int mx_s = 0;

        for(int i = 0; i < n; i++) {
            int s = 0;
            for(int j = 0; j < mx_bit_width; j++) {
                if((a[i]>>j)&1) s += (1<<j)*(n-rep[j]);
                else s += (1<<j)*(rep[j]);
            }
            mx_s = max(mx_s, s);
        }

        cout << mx_s << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}