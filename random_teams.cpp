#include <bits/stdc++.h>
using namespace std;

#define int long long

int s(int n) {
    return (n*(n-1))/2;
}

void solve() {

    int n, m; cin >> n >> m;

    int mn = (m-n%m)*s(n/m)+(n%m)*s(n/m+1);
    int mx = s(n-m+1);

    cout << mn << " " << mx << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}