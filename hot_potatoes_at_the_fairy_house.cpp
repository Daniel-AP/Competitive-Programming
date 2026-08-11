#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    if(count(all(s), '1') == 2*n) return void(cout << n << ' ' << n << '\n');

    int score1 = 0, score0 = 0;

    int cur = 0;
    int i = 0;

    while(i < 2*n && s[i] == '1') cur++, i++;
    int start = cur;
    i++;
    cur = (i < 2*n && s[i] == '1');

    for(; i < 2*n; i++) {
        int j = i;
        if(s[i] != s[i-1]) {
            if(s[i] == '0') {
                if(j%2 == 0) score0 += cur/2+1, score1 += cur-(cur/2+1);
                else score1 += cur/2+1, score0 += cur-(cur/2+1);
                cur = 0;
            } else {
                cur = 1;
            }   
        } else if(s[i] == '1') cur++;
    }

    if(cur+start > 0) {
        int end = (start == 0 ? 2*n : start);
        if(end%2 == 0) score0 += (cur+start)/2+1, score1 += (cur+start)-((cur+start)/2+1);
        else score1 += (cur+start)/2+1, score0 += (cur+start)-((cur+start)/2+1);
    }

    cout << score1 << ' ' << score0 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}