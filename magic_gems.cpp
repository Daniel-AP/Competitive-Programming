#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

#define MOD 1000000007
// #define MOD 998244353

template <class T>
struct Matrix {
    typedef Matrix M;
    int N;
    vector<vector<T>> d;

    Matrix(int n) : N(n), d(N, vector<T>(N)) {}

    M operator*(const M &m) const {
        M a(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    a.d[i][j] += d[i][k] * m.d[k][j];
                    a.d[i][j] %= MOD;
                }
            }
        }
        return a;
    }

    vector<T> operator*(const vector<T> &vec) const {
        vector<T> ret(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ret[i] += d[i][j] * vec[j];
                ret[i] %= MOD;
            }
        }
        return ret;
    }

    M operator^(int p) const {
        assert(p >= 0);
        M a(N), b(*this);
        for (int i = 0; i < N; i++) {
            a.d[i][i] = 1;
        }
        while (p) {
            if (p & 1) {
                a = a * b;
            }
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

void solve() {

    int n, m; cin >> n >> m;

    if(m > n) return void(cout << 1 << '\n');

    Matrix<int> mat(m);
    mat.d[0][0] = mat.d[0][m-1] = 1;

    for(int i = 1; i < m; i++) {
        mat.d[i][i-1] = 1;
    }

    vector<int> ans(m, 1);

    mat = mat^(n-m+1);
    ans = mat*ans;

    cout << ans[0] << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--) solve();

    return 0;

}