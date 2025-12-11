#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;
    for(int i = 0; i < n; i++) freq[a[i]]++;

    for(int i = 1; i <= n; i++) {
        if(freq[i] > 2) {
            freq[i+1] += freq[i]-2;
            freq[i] = 2;
        }
        if(freq[i]%2 == 1) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}