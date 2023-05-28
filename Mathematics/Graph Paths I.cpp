#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int n, m, k, a, b;

struct Matrix{
    int val[105][105];
    Matrix(){
        memset(val, 0, sizeof(val));
    }
    Matrix operator * (Matrix in){
        Matrix out;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    out.val[i][j] += (val[i][k] * in.val[k][j]) % mod;
                    out.val[i][j] %= mod;
                }
            }
        }
        return out;
    }
}basic, unit;

Matrix fastPow(Matrix n, int pow){
    if(pow == 0){
        return unit;
    }
    else if(pow == 1){
        return n;
    }
    else if(pow % 2 == 0){
        return fastPow(n*n, pow/2);
    }
    else{
        return fastPow(n*n, pow/2) * n;
    }
}

void init(){
    for(int i=0;i<n;i++){
        unit.val[i][i] = 1;
    }
}

signed main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    init();
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        basic.val[a-1][b-1]++;
    }
    Matrix ans = fastPow(basic, k);
    printf("%lld\n", ans.val[0][n-1]);
}