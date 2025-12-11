#include <bits/stdc++.h>
using namespace std;

#define int long long

double fact(double n) {

    double m = 1;

    while(n) {
        m *= n;
        n--;
    }

    return m;

}

double comb(double n, double r) {
    return fact(n)/(fact(r)*fact(n-r));
}

void solve() {

    string s1, s2; cin >> s1 >> s2;
    
    int c1(0), c2(0);
    int count = 0;

    for(int i = 0; i < s1.length(); i++) {

        if(s2[i] == '?') count++;

        if(s1[i] == '+') c1++;
        else c1--;

        if(s2[i] == '+') c2++;
        else if(s2[i] == '-') c2--;

    }
    
    cout << fixed << setprecision(12);

    if(abs(c1-c2) > count || (count-abs(c1-c2))%2 != 0) {
        cout << 0.0L << endl;
    } else {
        cout << comb(count, (count+(c1-c2))/2)/pow(2, count) << endl;   
    }

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;

}