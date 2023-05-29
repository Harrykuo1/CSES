#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a, b, w;

struct Matrix{
    int val[105][105];
    Matrix(){
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                val[i][j] = LLONG_MAX;
            }
        }
    }
    Matrix operator * (Matrix in){
        Matrix out;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(val[i][k]!=LLONG_MAX && in.val[k][j]!=LLONG_MAX){
                        out.val[i][j] = min(out.val[i][j], val[i][k] + in.val[k][j]);
                    }
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
        for(int j=0;j<n;j++){
            if(i == j){
                unit.val[i][j] = 1;
            }
            else{
                unit.val[i][j] = 0;
            }
            basic.val[i][j] = LLONG_MAX;
        }
    }
}

signed main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    init();
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld", &a, &b, &w);
        basic.val[a-1][b-1] = min(basic.val[a-1][b-1], w);
    }
    Matrix ans = fastPow(basic, k);
    if(ans.val[0][n-1] == LLONG_MAX){
        printf("-1\n");
    }
    else{
        printf("%lld\n", ans.val[0][n-1]);
    }
}