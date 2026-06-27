#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

   int n; cin >> n;

   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];

   vector<vector<int>> d(4, vector<int>());

    for(int i = 0; i < n; i++) {
        if(a[i]%6 == 0) d[3].push_back(a[i]);
        else if(a[i]%3 == 0) d[2].push_back(a[i]);
        else if(a[i]%2 == 0) d[1].push_back(a[i]);
        else d[0].push_back(a[i]);
    }

    array<int, 4> p{{0, 1, 2, 3}};
    int mn = INF;
    vector<int> best;

    do {
        int cur = 0;
        vector<int> b;
        b.reserve(n);
        for(int i: p) {
            for(int x: d[i]) b.push_back(x);
        }
        int first2 = -1, last2 = -1, first3 = -1, last3 = -1;
        for(int i = 0; i < n; i++) {
            if(b[i]%6 == 0) {
                cur += i+1;
                if(first2 == -1) first2 = i;
                if(first3 == -1) first3 = i;
                last2 = i, last3 = i;
            }
            else if(b[i]%3 == 0) {
                if(first3 == -1) first3 = i;
                last3 = i;
                if(last2 != -1) cur += last2+1;
            } else if(b[i]%2 == 0) {
                if(first2 == -1) first2 = i;
                last2 = i;
                if(last3 != -1) cur += last3+1;
            } else {
                if(last2 != -1 && last3 != -1) cur += min(last2, last3)+1;
            }
        }
        if(cur < mn) mn = cur, best = b;
    } while(next_permutation(all(p)));

    for(int x: best) cout << x << ' ';
    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}