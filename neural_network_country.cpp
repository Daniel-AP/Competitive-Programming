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

    int n, l, m; cin >> n >> l >> m;

    vector<int> a(n), b(n), c(n);
    vector<int> c1(m), c2(m), c3(m);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        c1[a[i]%m]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        c2[b[i]%m]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c3[(b[i]+c[i])%m]++;
    }

    Matrix<int> mat(m);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            mat.d[i][j] = c2[(i-j+m)%m];
        }
    }

    vector<int> neu(m);
    neu[0] = 1;

    mat = mat^(l-2);
    c2 = mat*neu;

    int ans = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if((i+j+k)%m != 0) continue;
                ans += c1[i]*c2[j]%MOD*c3[k]%MOD;
                ans %= MOD;
            }
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