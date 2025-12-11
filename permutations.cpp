#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {

    int n; cin >> n;

    vector<int> a(n);

    int j = 0;
    
    for(int i = 2; i <= n-n%2; i+=2) {
        a[j] = i;
        j++;
    }

    for(int i = 1; i <= n-1+n%2; i+=2) {
        a[j] = i;
        j++;
    }

    bool can = true;

    for(int i = 0; i < n-1; i++) {
        if(abs(a[i]-a[i+1]) == 1) can = false;
    }

    if(can) {
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    } else {
        cout << "NO SOLUTION" << endl;
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}