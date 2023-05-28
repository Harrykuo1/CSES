#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

struct Matrix{
    int val[2][2];
    Matrix(){
        memset(val, 0, sizeof(val));
    }
    Matrix operator * (Matrix input){
        Matrix output;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    output.val[i][j] += (val[i][k] * input.val[k][j]) % mod;
                    output.val[i][j] %= mod;
                }
            }
        }
        return output;
    }
}unit, basic;

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
    for(int i=0;i<2;i++){
        unit.val[i][i] = 1;
    }
    basic.val[0][1] = basic.val[1][0] = basic.val[1][1] = 1;
}


signed main(){
    init();

    int n;
    scanf("%lld", &n);
    if(n == 0){
        printf("0\n");
    }
    else{
        Matrix ans = fastPow(basic, n);
        printf("%lld\n", ans.val[1][0]);
    }
}