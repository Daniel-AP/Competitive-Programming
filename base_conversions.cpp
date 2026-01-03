int fromBase(string n, int b) {

    int ans = 0;

    for(char d: n) {
        
        int val = 0;

        if('0' <= d && d <= '9') val = d-'0';
        else val = d-'A'+10;

        ans *= b;
        ans += val;

        if(val >= b) return -1;

    }

    return ans;

}

string toBase(int n, int b) {

    if(b == 1) return string(n, '1');
    if(n == 0) return "0";

    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ans;

    while(n) {
        ans += digits[n%b];
        n /= b;
    }

    reverse(ans.begin(), ans.end());

    return ans;

}