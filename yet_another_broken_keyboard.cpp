#include <bits/stdc++.h>
using namespace std;

#define int long long

int c(int n) {
    return (n*(n+1))/2;
}

void solve() {

    int n, k; cin >> n >> k;
    string s; cin >> s;

    unordered_set<char> a;
    for(int i = 0; i < k; i++) {
        char x; cin >> x;
        a.insert(x);
    }

    int cnt = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        if(a.count(s[i]) == 0) {
            ans += c(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }

    ans += c(cnt);

    cout << ans << endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}