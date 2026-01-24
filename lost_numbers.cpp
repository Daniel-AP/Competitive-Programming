#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int a[] = { 42, 23, 16, 15, 8, 4 };

int ask(int i, int j) {

    cout << "? " << i << ' ' << j << '\n';
    cout.flush();

    int ans; cin >> ans;

    return ans;

}

void solve() {

    int ans[] = { 0, 0, 0, 0, 0, 0 };

    int q1 = ask(1, 2);
    int q2 = ask(1, 3);
    int q3 = ask(1, 4);
    int q4 = ask(1, 5);

    for(int i = 0; i < 6; i++) {
        if(q1%a[i] == 0 && q2%a[i] == 0 && q3%a[i] == 0 && q4%a[i] == 0) {
            ans[0] = a[i];
            break;
        }
    }

    ans[1] = q1/ans[0];
    ans[2] = q2/ans[0];
    ans[3] = q3/ans[0];
    ans[4] = q4/ans[0];

    ans[5] = 4*8*15*16*23*42/(ans[0]*ans[1]*ans[2]*ans[3]*ans[4]);

    cout << "! ";
    for(int i = 0; i < 6; i++) cout << ans[i] << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}