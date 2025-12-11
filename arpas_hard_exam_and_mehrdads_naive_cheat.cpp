#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> d = { 8, 4, 2, 6 };
    cout << d[(n-1)%4] << endl;

    return 0;

}