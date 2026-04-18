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

    int n, m, k; cin >> n >> m >> k;

    Matrix<int> mat(m+1);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            mat.d[i][j] = 1;
        }
    }

    while(k--) {
        string s; cin >> s;
        char c1 = s[0], c2 = s[1];
        int n1, n2;
        if(c1 >= 'a' && c1 <= 'z') n1 = (c1-'a'+1);
        else n1 = (c1-'A'+27);
        if(c2 >= 'a' && c2 <= 'z') n2 = (c2-'a'+1);
        else n2 = (c2-'A'+27);
        mat.d[n1][n2] = 0;
    }

    int ans = 0;
    mat = mat^(n-1);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            ans += mat.d[i][j];
            ans %= MOD;
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