int nCr(int n, int r) {

    if(r == 0) return 1;
    if(r > n / 2) return nCr(n, n-r); 

    int res = 1; 

    for(int k = 1; k <= r; k++) {
        res *= n-k+1;
        res /= k;
    }

    return res;
}