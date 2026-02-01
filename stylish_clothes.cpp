#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

array<vector<int>, 4> clothes;

bool can(int l, int r, int& i1, int& i2, int& i3, int& i4, int& size) {

    int j1 = lower_bound(all(clothes[0]), l)-clothes[0].begin();
    int j2 = lower_bound(all(clothes[1]), l)-clothes[1].begin();
    int j3 = lower_bound(all(clothes[2]), l)-clothes[2].begin();
    int j4 = lower_bound(all(clothes[3]), l)-clothes[3].begin();

    if(j1 >= clothes[0].size() || j2 >= clothes[1].size() || j3 >= clothes[2].size() || j4 >= clothes[3].size()) return false;

    if(max({ clothes[0][j1], clothes[1][j2], clothes[2][j3], clothes[3][j4] }) <= r) {
        if(r-l+1 < size) i1 = j1, i2 = j2, i3 = j3, i4 = j4, size = r-l+1;
        return true;
    } else return false;

}

void solve() {

    for(int i = 0; i < 4; i++) {
        int n; cin >> n;
        clothes[i].assign(n, 0);
        for(int j = 0; j < n; j++) cin >> clothes[i][j];
    }

    for(int i = 0; i < 4; i++) sort(all(clothes[i]));

    int l = 1, i1 = -1, i2 = -1, i3 = -1, i4 = -1, size = INF;

    for(int r = 1; r <= 1e5; r++) {
        while(can(l, r, i1, i2, i3, i4, size)) l++;
    }

    cout << clothes[0][i1] << ' ' << clothes[1][i2] << ' ' << clothes[2][i3] << ' ' << clothes[3][i4] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}