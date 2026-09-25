#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int cur = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) cur = i+1;
    }

    for(int i = 0; i+1 < n; i++) {
        if(a[i] == a[i+1]) cur = max(cur, i+1);
        if(b[i] == b[i+1]) cur = max(cur, i+1);
    }

    vector<array<int, 2>> inA(n+1, { -1, -1 }), inB(n+1, { -1, -1 });
    inA[a[n-1]][(n-1)%2] = n-1;
    inB[b[n-1]][(n-1)%2] = n-1;

    for(int i = n-2; i >= cur; i--) {
        if(inB[a[i]][i%2] != -1 || inB[a[i]][1-i%2]-i > 1 || inA[a[i]][1-i%2] != -1 || inA[a[i]][i%2] != -1) {
            cur = i+1;
            break;
        }
        inA[a[i]][i%2] = max(inA[a[i]][i%2], i);
        inB[b[i]][i%2] = max(inB[b[i]][i%2], i);
    }

    for(int i = 1; i <= n; i++) {
        inA[i][0] = -1;
        inA[i][1] = -1;
        inB[i][0] = -1;
        inB[i][1] = -1;
    }

    inA[a[n-1]][(n-1)%2] = n-1;
    inB[b[n-1]][(n-1)%2] = n-1;

    for(int i = n-2; i >= cur; i--) {
        if(inA[b[i]][i%2] != -1 || inA[b[i]][1-i%2]-i > 1 || inB[b[i]][1-i%2] != -1 || inB[b[i]][i%2] != -1) {
            cur = i+1;
            break;
        }
        inA[a[i]][i%2] = max(inA[a[i]][i%2], i);
        inB[b[i]][i%2] = max(inB[b[i]][i%2], i);
    }

    cout << cur << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}