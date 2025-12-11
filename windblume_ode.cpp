#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPrime(int n) {

    if(n <= 3) return n > 1;
    if(n%2 == 0 || n%3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6) {
        if(n%i == 0 || n%(i+2) == 0) return false;
    }

    return true;

}

void solve() {

    int t; cin >> t;

    while(t--) {

        int n; cin >> n;

        vector<int> a(n);
        vector<int> ans;

        int odd = 0;
        int j = -1;
        int s = 0;

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i]%2 == 1) odd++;
        }

        odd = odd/2*2;

        for(int i = 0; i < n; i++) {
            if(a[i]%2 == 1 && !odd) j = i;
            if(a[i]%2 == 0) {
                ans.push_back(i);
                s += a[i];
            }
            if(a[i]%2 == 1 && odd) {
                ans.push_back(i);
                s += a[i];
                odd--;
            }
        }

        if(j != -1 && !isPrime(s+a[j])) ans.push_back(j);

        cout << ans.size() << endl;
        for(int b: ans) cout << b+1 << " ";
        cout << endl;

    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}