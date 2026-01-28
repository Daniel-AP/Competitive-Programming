#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> c1 >> c2 >> c3;

    cout << ((a1+a2+b1)%2 ? 0 : 1) << ((a1+a2+a3+b2)%2 ? 0 : 1) << ((a2+a3+b3)%2 ? 0 : 1) << endl;
    cout << ((a1+b1+b2+c1)%2 ? 0 : 1) << ((a2+b1+b2+b3+c2)%2 ? 0 : 1) << ((a3+b2+b3+c3)%2 ? 0 : 1) << endl;
    cout << ((b1+c1+c2)%2 ? 0 : 1) << ((b2+c1+c2+c3)%2 ? 0 : 1) << ((b3+c2+c3)%2 ? 0 : 1) << endl;

    return 0;
}
