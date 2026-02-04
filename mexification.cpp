#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int mex1 = 0;
    vector<int> cnt(n+1);

    for(int i = 0; i < n; i++) cnt[a[i]]++;

    while(cnt[mex1]) mex1++;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        if(cnt[a[i]] == 1) b[i] = min(a[i], mex1);
        else b[i] = mex1;
    }

    int s1 = 0;
    for(int i = 0; i < n; i++) s1 += b[i];

    for(int i = 0; i <= n; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[b[i]]++;

    int mex2 = 0;
    while(cnt[mex2]) mex2++;

    vector<int> c(n);
    for(int i = 0; i < n; i++) {
        if(cnt[b[i]] == 1) c[i] = min(b[i], mex2);
        else c[i] = mex2; 
    }

    int s2 = 0;
    for(int i = 0; i < n; i++) s2 += c[i];

    for(int i = 0; i <= n; i++) cnt[i] = 0;
    for(int i = 0; i < n; i++) cnt[c[i]]++;

    int mex3 = 0;
    while(cnt[mex3]) mex3++;

    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        if(cnt[c[i]] == 1) d[i] = min(c[i], mex3);
        else d[i] = mex3;
    }

    int s3 = 0;
    for(int i = 0; i < n; i++) s3 += d[i];
    
    if(k == 1) cout << s1 << '\n';
    else if(k%2 == 0) cout << s2 << '\n';
    else cout << s3 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}