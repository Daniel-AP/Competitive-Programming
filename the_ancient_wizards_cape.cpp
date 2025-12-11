#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

bool check(string s, vector<int> a, int n) {

    int cntL = 0, cntR = count(s.begin(), s.end(), 'R');

    for(int i = 0; i < n; i++) {
        if(cntL+cntR-(s[i]=='R')+1 != a[i]) return false;
        if(s[i] == 'L') cntL++;
        else cntR--;
    }

    return true;

}

void solve() {

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    string ans(n, '?');
    char prev = '?';

    for(int i = 1; i < n; i++) {

        if(a[i] == a[i-1]) {
            if(prev != '?') ans[i] = 'R'+'L'-prev;
        } else if(a[i] == a[i-1]-1) {
            if(ans[i-1] == 'L') return void(cout << 0 << '\n');
            ans[i-1] = 'R';
            ans[i] = 'R';
        } else if(a[i] == a[i-1]+1) {
            if(ans[i-1] == 'R') return void(cout << 0 << '\n');
            ans[i-1] = 'L';
            ans[i] = 'L';
        } else {
            return void(cout << 0 << '\n');
        }

        prev = ans[i];

    }

    string s1 = "R", s2 = "L";
    for(int i = 1; i < n; i++) s1 += ('R'+'L'-s1.back()), s2 += ('R'+'L'-s2.back());

    if(prev == '?') return void(cout << check(s1, a, n)+check(s2, a, n) << '\n');

    int i1 = 0;
    for(; i1 < n; i1++) if(ans[i1] != '?') break;
    
    prev = ans[i1];
    while(--i1 >= 0) ans[i1] = 'R'+'L'-prev, prev = ans[i1];

    cout << check(ans, a, n) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;

}