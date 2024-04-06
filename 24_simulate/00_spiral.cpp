vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n,0));
    if (n == 1) {
        res[0][0] = 1;
        return res;
    }
    int l = 0, r = n - 1, t = 0, d = n - 1;
    int num = 1;
    while(true) {
        for (int i = l; i <= r; i++) {
            res[t][i] = num;
            num++;
        }
        t++;
        if (t > d) break;
        for (int i = t; i <= d; i++) {
            res[i][r] = num;
            num++;
        }
        r--;
        if (r < l) break;
        for (int j = r; j >= l; j--) {
            res[d][j] = num;
            num++;
        }
        d--;
        if (d < t) break;
        for (int j = d; j >= t; j--) {
            res[j][l] = num;
            num++;
        }
        l++;
        if (l > r) break;
    }
    return res;
}