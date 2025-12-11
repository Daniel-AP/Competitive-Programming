#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1LL<<60)
#define START_TIMER auto __start = std::chrono::high_resolution_clock::now();
#define END_TIMER std::cout << "Time elapsed: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - __start).count() << " ms\n";

#define MOD 1000000007

void solve() {

    int n, a, b; cin >> n >> a >> b;

    int st1 = a, e1 = (n-1)/a*a;
    int s1 = ((e1-st1)/a+1)*(e1+st1)/2;

    int st2 = b, e2 = (n-1)/b*b;
    int s2 = ((e2-st2)/b+1)*(e2+st2)/2;

    int st3 = lcm(a, b), e3 = (n-1)/lcm(a, b)*lcm(a, b);
    int s3 = ((e3-st3)/lcm(a, b)+1)*(e3+st3)/2;

    cout << s1+s2-s3 << '\n';
    
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; t = 1;

    while(t--) solve();

    return 0;

}