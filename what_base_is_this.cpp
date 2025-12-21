#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int fromBase(string n, int b) {

    int ans = 0;

    for(char d: n) {
        
        int val = 0;

        if('0' <= d && d <= '9') val = d-'0';
        else val = d-'A'+10;

        ans *= b;
        ans += val;

        if(val >= b) return -1;

    }

    return ans;

}

void solve(string x, string y) {

    for(int i = 2; i <= 36; i++) {
        for(int j = 2; j <= 36; j++) {

            int xx = fromBase(x, i), yy = fromBase(y, j);

            if(xx == -1 || yy == -1) continue;
            if(xx != yy) continue;

            cout << x << " (base " << i << ") = " << y << " (base " << j << ")" << '\n';
            return;

        }
    }

    cout << x << " is not equal to " << y << " in any base 2..36" << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string x, y;

    while(cin >> x >> y) solve(x, y);

    return 0;

}