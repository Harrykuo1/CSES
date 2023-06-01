#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[1000005], t, n;

int32_t main(){
    for(int i=2;i<1000005;i++){
        if(dp[i] == 0){
            for(int j=i;j<1000005;j+=i){
                dp[j] = i;
            }
        }
    }
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        int last = -1, ans = 1;
        vector<int> vec;
        while(dp[n]){
            if(dp[n] != last){
                last = dp[n];
                vec.push_back(2);
            }
            else{
                vec[vec.size()-1]++;
            }
            n /= dp[n];
        }
        for(int i=0;i<vec.size();i++){
            ans *= vec[i];
        }
        printf("%lld\n", ans);
    }
}