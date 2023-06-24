#include<bits/stdc++.h>
using namespace std;

char arr[1000005];
int cnt[26];

int32_t main(){
    scanf("%s", arr);
    int len = strlen(arr);
    for(int i=0;i<len;i++){
        cnt[arr[i]-'A']++;
    }
    int odd = -1;
    for(int i=0;i<26;i++){
        if(cnt[i] % 2){
            if(odd == -1){
                odd = i;
            }
            else{
                printf("NO SOLUTION\n");
                exit(0);
            }
        }
    }
    string ans = "";
    for(int i=0;i<26;i++){
        if(i == odd) continue;
        for(int j=0;j<cnt[i]/2;j++){
            ans += ('A' + i);
        }
    }
    std::cout<<ans;
    if(odd != -1){
        for(int j=0;j<cnt[odd];j++){
            ans += ('A' + odd);
        }
    }
    reverse(ans.begin(), ans.end()); 
    std::cout<<ans;
}