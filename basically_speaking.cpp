#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

int fromBase(string n, int b) {

    int ans = 0;

    for(char d: n) {
        
        int val = 0;

        if('0' <= d && d <= '9') val = d-'0';
        else val = d-'A'+10;

        ans *= b;
        ans += val;

        if(val >= b) return -1;

    }

    return ans;

}

string toBase(int n, int b) {

    if(b == 1) return string(n, '1');
    if(n == 0) return "0";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;

    while(n) {
        ans += digits[n%b];
        n /= b;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}

void solve(string n, int b1, int b2) {

    int nb10 = fromBase(n, b1);
    string ans = toBase(nb10, b2);

    if(ans.length() > 7) {
        cout << "  ERROR" << '\n';
        return;
    }

    cout << string(7-ans.length(), ' ') << ans << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string n;
    int b1, b2;

    while(cin >> n >> b1 >> b2) solve(n, b1, b2);

    return 0;

}