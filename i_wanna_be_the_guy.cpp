#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int p;
    cin >> p;

    vector<int> lilx(p);
    for(int i = 0; i < p; i++) cin >> lilx[i];

    int q;
    cin >> q;

    vector<int> lily(q);
    for(int i = 0; i < q; i++) cin >> lily[i];

    unordered_set<int> pass;

    for(int l : lilx) pass.insert(l);
    for(int l : lily) pass.insert(l);

    cout << (pass.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;

    return 0;

}