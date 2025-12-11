#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int count = 0;
    int i;

    for(i = 1; i*i < x; i++) {
        if(x%i == 0 && i <= n && x/i <= n) {
            count += 2;
        }
    }

    if(i*i == x && i <= n) count++;

    cout << count << endl;

    return 0;

}