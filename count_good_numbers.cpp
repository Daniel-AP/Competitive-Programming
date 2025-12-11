#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

int div(int l, int r, int d) {
    return r/d-(l-1)/d;
}

void solve() {

    int l, r; cin >> l >> r;

    cout << (r-l+1)-(div(l, r, 2)+div(l, r, 3)+div(l, r, 5)+div(l, r, 7)-(div(l, r, 6)+div(l, r, 10)+div(l, r, 14)+div(l, r, 15)+div(l, r, 21)+div(l, r, 35))+(div(l, r, 30)+div(l, r, 42)+div(l, r, 70)+div(l, r, 105))-div(l, r, 210)) << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while(t--) solve();

    return 0;

}