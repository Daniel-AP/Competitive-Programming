#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;
        
        vector<string> adj_matrix(n);
        vector<int> perm(n);

        for(int i = 0; i < n; i++) {
            cin >> adj_matrix[i];
            perm[i] = i;
        }
        
        sort(perm.begin(), perm.end(), [&](int a, int b) {
            if(adj_matrix[a][b] == '1') return b > a;
            else return a > b;
        });

        for(int p: perm) cout << p+1 << " ";
        cout << endl;

    }

    return 0;

}