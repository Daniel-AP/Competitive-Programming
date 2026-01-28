#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int x = 0;
    string statement;

    cin >> n;

    while(n--) {

        cin >> statement;

        if(statement[1] == '+') { x++; }
        if(statement[1] == '-') { x--; }

    }

    cout << x;

}