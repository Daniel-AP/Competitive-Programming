#include <bits/stdc++.h>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> expressions(n);
    vector<vector<int>> results;

    for(int i = 0; i < n; i++) getline(cin, expressions[i]);

    for(string exp: expressions) {

        vector<int> coef(26);
        int sign = 1;

        for(int i = 0; i < exp.size(); i++) {
            if(exp[i] == ')' || exp[i] == '(' || exp[i] == ' ') continue;
            if(exp[i] == '-' && exp[i+1] >= 97 && exp[i+1] <= 122 && sign < 0) sign = 1;
            else if(exp[i] == '-') sign = -1;
            else if(exp[i] == '+') sign = 1;
            if(exp[i] >= 97 && exp[i] <= 122) {
                coef[exp[i]-'a'] += sign;
            }
        }

        results.push_back(coef);

    }

    int c = 1;
    sort(results.begin(), results.end());

    for(int i = 1; i < results.size(); i++) {
        if(results[i-1] != results[i]) c++;
    }

    cout << c << endl;

    return 0;

}