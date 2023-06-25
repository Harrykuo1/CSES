#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
int arr[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n);
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum + 1 < arr[i]){
            printf("%lld\n", sum + 1);
            exit(0);
        }
        sum += arr[i];
    }
    printf("%lld\n", sum + 1);
}