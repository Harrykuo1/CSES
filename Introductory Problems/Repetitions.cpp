#include<bits/stdc++.h>
using namespace std;
#define int long long

char input[1000005] = {0};

int32_t main(){
    scanf("%s", &input[1]);
    int ans = 1, cnt = 1;
    int len = strlen(&input[1]);
    for(int i=1;i<=len;i++){
        if(input[i] == input[i-1]){
            cnt++;
            ans = max(ans, cnt);
        }
        else{
            cnt = 1;
        }
    }
    printf("%lld\n", ans);
}