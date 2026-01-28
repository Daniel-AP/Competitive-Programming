#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-__start).count() << " ms\n";

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> mult(vector<vector<int>> mat1, vector<vector<int>> mat2) {

    int n = mat1.size();
    int m = mat2[0].size();
    int k = mat1[0].size();

    vector<vector<int>> res(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int l = 0; l < k; l++) {
                res[i][j] += mat1[i][l]*mat2[l][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return res;

}

vector<vector<int>> binpow(vector<vector<int>> mat, int e) {

    // has to be square matrix

    int n = mat.size();

    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0; i < n; i++) res[i][i] = 1;

    while(e > 0) {
        if(e&1) {
            res = mult(res, mat);
        }
        mat = mult(mat, mat);
        e >>= 1;
    }

    return res;

}
//re gooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooorda
void solve() {

    mult(
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        },
        {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        }
    ); 
    
}

void sieve(int n) {

    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= n; j += i) is_prime[j] = false;
        }
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}