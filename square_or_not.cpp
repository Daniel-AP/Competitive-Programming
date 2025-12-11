#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

bool square(int n) {
    int sq = sqrt(n);
    return sq*sq == n;
}

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    if(!square(n)) return void(cout << "No" << '\n');

    int sq = sqrt(n);

    vector<string> mat(sq, string(sq, ' '));
    for(int i = 1; i <= sq; i++) {
        for(int j = 1; j <= sq; j++) {
            mat[i-1][j-1] = s[(i-1)*sq+j-1];
        }
    }

    for(int i = 0; i < sq; i++) {
        for(int j = 0; j < sq; j++) {
            if(mat[i][j] == '0') {
                if(i == 0 || i == sq-1 || j == 0 || j == sq-1) return void(cout << "No" << '\n');
            } else {
                if(!(i == 0 || i == sq-1 || j == 0 || j == sq-1)) return void(cout << "No" << '\n');
            }
        }
    }

    cout << "Yes" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}