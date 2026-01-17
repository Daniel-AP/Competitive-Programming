#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(n) begin(n), end(n)
#define INF (1LL<<60)

// #define MOD 1000000007
// #define MOD 998244353

set<int> h{0};
vector<int> humble;

void dfs(int n) {

    if(h.size() == 5843) return;

    h.insert(n);

    if(h.find(n*2) == h.end() && n*2 <= 2000000000) dfs(n*2);
    if(h.find(n*3) == h.end() && n*3 <= 2000000000) dfs(n*3);
    if(h.find(n*5) == h.end() && n*5 <= 2000000000) dfs(n*5);
    if(h.find(n*7) == h.end() && n*7 <= 2000000000) dfs(n*7);

}

void pre() {

    dfs(1);
    for(int x: h) humble.push_back(x);

}

void solve(int n) {

    if(n%100 >= 11 && n%100 <= 19 || n%10 > 3 || n%10 == 0) {
        cout << "The " << n << "th humble number is " << humble[n] << ".";
    } else {
        if(n%10 == 1) {
            cout << "The " << n << "st humble number is " << humble[n] << ".";
        } else if(n%10 == 2) {
            cout << "The " << n << "nd humble number is " << humble[n] << ".";
        } else if(n%10 == 3) {
            cout << "The " << n << "rd humble number is " << humble[n] << ".";
        }
    }

    cout << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pre();

    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        solve(n);
    }

    return 0;

}