#include<bits/stdc++.h>
using namespace std;
#define int long long

char input[1000005];
int arr[1000005*2];
int dp[1000005*2];
int len, ansLen=0, ansIdx=0, mid=0, mx=0;

void pre_process(){
    int idx = 0;
    arr[idx++] = '@';
    arr[idx++] = '#';
    for(int i=0;i<len;i++){
        arr[idx++] = input[i];
        arr[idx++] = '#';
    }
    arr[idx++] = '$';
    len = idx;
}

void manachar(){
    for(int i=0;i<len;i++){
        if(i < mx){
            dp[i] = min(mx-i, dp[mid*2-i]);
        }
        else{
            dp[i] = 1;
        }
        while(arr[i+dp[i]] == arr[i-dp[i]]){
            dp[i]++;
        }
        if(i+dp[i] > mx){
            mx = i+dp[i];
            mid = i;
        }
        if(dp[i] > ansLen){
            ansLen = dp[i];
            ansIdx = i;
        }
    }
} 

int32_t main(){
    scanf("%s", input);
    len = strlen(input);
    pre_process();
    manachar();
    for(int i=ansIdx-(ansLen-1); i<=ansIdx+(ansLen-1);i++){
        if(isalpha(arr[i])){
            printf("%c", arr[i]);
        }
    }
    printf("\n");
}