#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string l, r;
        cin >> l >> r;
        int n = l.size();

        // 1) find common‐prefix length cp
        int cp = 0;
        while(cp < n && l[cp] == r[cp]) 
            cp++;

        // 2) if l == r, x must equal them → f(l,x)=n and f(x,r)=n
        if(cp == n){
            cout << 2*n << "\n";
            continue;
        }

        // 3) at the first differing digit position k = cp,
        //    if r[k] - l[k] == 1 then any x must choose either l[k] or r[k],
        //    which gives exactly one extra match in f(l,x)+f(x,r);
        //    otherwise (gap ≥ 2) you can pick a middle digit, avoiding both.
        int extra = (r[cp] - l[cp] == 1 ? 1 : 0);

        // 4) each of the cp prefix digits contributes 1 to f(l,x)
        //    and 1 to f(x,r), i.e. 2 total per prefix position.
        int ans = 2*cp + extra;
        cout << ans << "\n";
    }
    return 0;
}
