#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int check(vector<bool>& a, vector<bool>& b, int n) {

    int cntA = 0, cntB = 0;
    int lastA = -1, lastB = -1;

    for(int i = 0; i < n; i++) {
        if(a[i] != b[i] && i%2 == 0) {
            cntA++;
            lastA = i;
        }
        if(a[i] != b[i] && i%2) {
            cntB++;
            lastB = i;
        }
    }

    if(cntA%2 == cntB%2) {
        if(count(a.begin(), a.end(), 1)%2 != count(b.begin(), b.end(), 1)%2) {
            int aa = (count(a.begin(), a.end(), 1)+cntB-cntA)&1;
            int bb = (count(b.begin(), b.end(), 1)+cntA-cntB)&1;
            if(aa&1) return 1;
            else if(bb&1) return 0;
            else return -1;
        } else {
            return -1;
        }
    } else {
        if(lastA > lastB) return 1;
        else if(lastB > lastA) return 0;
        else return -1;
    }

}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<bool>> matA(32, vector<bool>(n));
    vector<vector<bool>> matB(32, vector<bool>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            matA[j][i] = (a[i]&(1<<j))>0;
            matB[j][i] = (b[i]&(1<<j))>0;
        }
    }

    // for(int x: matA[0]) cout << x << ' ';
    // cout << '\n';

    for(int i = 31; i >= 0; i--) {
        int can = check(matA[i], matB[i], n);
        // cout << "i: " << i << ' ' << can << '\n';
        if(can == 1) return void(cout << "Ajisai" << '\n');
        if(can == 0) return void(cout << "Mai" << '\n');
    }

    cout << "Tie" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}