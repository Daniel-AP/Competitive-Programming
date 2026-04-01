#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, m; cin >> n >> m;

    vector<int> mat((n+1)*(m+1)), px((n+1)*(m+1));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mat[i*(m+1)+j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            px[i*(m+1)+j] = mat[i*(m+1)+j]+px[(i-1)*(m+1)+j]+px[i*(m+1)+j-1]-px[(i-1)*(m+1)+j-1];
        }
    }

    int area = 0, ans = 0;
    int uli1, ulj1, lri1, lrj1, best1 = -INF;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int ii = i; ii <= n; ii++) {
                for(int jj = j; jj <= m; jj++) {
                    int cur = px[ii*(m+1)+jj]-px[ii*(m+1)+(j-1)]-px[(i-1)*(m+1)+jj]+px[(i-1)*(m+1)+(j-1)];
                    if(cur > best1) {
                        uli1 = i;
                        ulj1 = j;
                        lri1 = ii;
                        lrj1 = jj;
                        best1 = cur;
                    }
                }
            }
        }
    }

    area += (lri1-uli1+1)*(lrj1-ulj1+1);
    ans += best1;

    int uli2, ulj2, lri2, lrj2, best2 = -INF;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int ii = i; ii <= n; ii++) {
                for(int jj = j; jj <= m; jj++) {
                    if(!(lrj1 < j || jj < ulj1 || lri1 < i || ii < uli1)) continue;
                    int cur = px[ii*(m+1)+jj]-px[ii*(m+1)+(j-1)]-px[(i-1)*(m+1)+jj]+px[(i-1)*(m+1)+(j-1)];
                    if(cur > best2) {
                        uli2 = i;
                        ulj2 = j;
                        lri2 = ii;
                        lrj2 = jj;
                        best2 = cur;
                    }
                }
            }
        }
    }

    if(best2 >= 0) {
        area += (lri2-uli2+1)*(lrj2-ulj2+1);
        ans += best2;
    }

    int uli3, ulj3, lri3, lrj3, best3 = -INF;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int ii = i; ii <= n; ii++) {
                for(int jj = j; jj <= m; jj++) {
                    if(!(lrj1 < j || jj < ulj1 || lri1 < i || ii < uli1)) continue;
                    if(!(lrj2 < j || jj < ulj2 || lri2 < i || ii < uli2)) continue;
                    int cur = px[ii*(m+1)+jj]-px[ii*(m+1)+(j-1)]-px[(i-1)*(m+1)+jj]+px[(i-1)*(m+1)+(j-1)];
                    if(cur > best3) {
                        uli3 = i;
                        ulj3 = j;
                        lri3 = ii;
                        lrj3 = jj;
                        best3 = cur;
                    }
                }
            }
        }
    }

    if(best3 >= 0) {
        area += (lri3-uli3+1)*(lrj3-ulj3+1);
        ans += best3;
    }

    if(area < 3 && best2 < 0) {
        area += (lri2-uli2+1)*(lrj2-ulj2+1);
        ans += best2;
    }

    if(area < 3 && best3 < 0) {
        area += (lri3-uli3+1)*(lrj3-ulj3+1);
        ans += best3;
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