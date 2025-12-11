#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
 
    while(t--) {
 
        long long n, f, a, b;
        long long prev(0), used(0);
        cin >> n >> f >> a >> b;
 
        for(long long i = 0; i < n; i++) {
 
            long long m;
            cin >> m;
 
            used += min((m-prev)*a, b);
            prev = m;
 
        }
 
        if(used < f) cout << "YES" << endl;
        else cout << "NO" << endl;
 
    }
 
    return 0;
 
}