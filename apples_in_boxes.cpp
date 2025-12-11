#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	
    int n, k; cin >> n >> k;
    int s = 0;
    
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) s += a[i];
    
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());

    int cnt = count(a.begin(), a.end(), mx);
    
    if(mx-mn-1LL == k && cnt > 1) {
        cout << "Jerry" << endl;
    } else if(mx-mn-1LL > k) {
        cout << "Jerry" << endl;
    }
    else if(s%2 == 1) {
        cout << "Tom" << endl;
    } else {
        cout << "Jerry" << endl;
    }
 
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}