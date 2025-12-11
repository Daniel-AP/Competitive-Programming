#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {
    vector<vector<bool>> configs = {
        {1,	0,	0,	0,	1,	1,	1,	0,	1,	1},
        {1,	0,	1,	0,	0,	0,	1,	0,	1,	0},
        {1,	0,	1,	1,	0,	1,	1,	1,	1,	1},
        {0,	0,	1,	1,	1,	1,	1,	0,	1,	1},
        {1,	0,	1,	1,	0,	1,	1,	0,	1,	1},
        {1,	1,	1,	1,	1,	0,	0,	1,	1,	1},
        {1,	1,	0,	1,	1,	1,	1,	1,	1,	1}
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        set<int> s = {0,1,2,3,4,5,6,7,8,9};
        string ss;
        cin >> ss;

        for (int j = 0; j < 7; j++) {
            if (ss[j] == 'G') {
                for (int k = 0; k < 10; k++)
                    if (!configs[j][k]) s.erase(k);
            } else if (ss[j] == 'g') {
                for (int k = 0; k < 10; k++)
                    if (configs[j][k]) s.erase(k);
            }
        }

        if (s.size() == 0) cout << " q raro ";
        else if (s.size() == 1) cout << *s.begin();
        else cout << "*"; 
    }
    cout << "\n";
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;

    while(t--) solve();

    return 0;

}