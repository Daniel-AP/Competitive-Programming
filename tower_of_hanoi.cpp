#include <bits/stdc++.h>
using namespace std;

#define int long long

void hanoi(int n, int l, int r, int mid) {

    if (n == 0) return;
    hanoi(n-1, l, mid, r);
    cout << l << " " << r << endl;
    hanoi(n-1, mid, r, l);

}


void solve() {

    int n; cin >> n;

    cout << (1<<n)-1 << endl;
    hanoi(n, 1, 3, 2);

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}