#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int di[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dj[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

void solve() {

    vector<string> mat(3);
    for(int i = 0; i < 3; i++) cin >> mat[i];

    string ans = "ZZZ";

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 8; k++) {
                int i2 = i+di[k], j2 = j+dj[k];
                if(i2 < 0 || i2 >= 3 || j2 < 0 || j2 >= 3) continue;
                for(int l = 0; l < 8; l++) {
                    int i3 = i2+di[l], j3 = j2+dj[l];
                    if(i3 < 0 || i3 >= 3 || j3 < 0 || j3 >= 3 || (i3 == i && j3 == j)) continue;
                    string s; s += mat[i][j]; s += mat[i2][j2]; s += mat[i3][j3];
                    ans = min(ans, s);
                }
            }
        }
    }

    cout << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}