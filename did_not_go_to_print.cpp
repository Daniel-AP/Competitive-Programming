#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

void solve() {

    int n; cin >> n;
    string s; cin >> s;

    deque<int> dq;
    vector<int> no;
    
    for(int i = 0; i < n; i++) {
        char c = s[i];
        if(c == '3') continue;
        if(c == '1') dq.push_front(i+1);
        if(c == '2') {
            if(!dq.empty()) {
                dq.pop_front();
                no.push_back(i+1);
            }
        }
    }

    cout << dq.size()+no.size() << '\n';
    for(int x: dq) no.push_back(x);
    sort(all(no));
    for(int x: no) cout << x << ' ';
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