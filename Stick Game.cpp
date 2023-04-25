#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n, k, tmp;

signed main(){
    scanf("%lld %lld", &n, &k);
    int *dp = (int*)calloc(n, sizeof(int));
    vector<int> vec;
    for(int i=0;i<k;i++){
        scanf("%lld", &tmp);
        vec.push_back(tmp);
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i < vec[j]){
                continue;
            }
            if (dp[i-vec[j]] == 0){
                dp[i] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]){
            printf("W");
        }
        else{
            printf("L");
        }
    }
}