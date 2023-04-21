#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, ans = 0;
int arr[2000005] = {0};
int house[2000005] = {0};

int32_t main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld", &house[i]);
    }
    sort(arr, arr + n);
    sort(house, house + m);
    int houseIdx = 0;
    for(int i=0;i<n && houseIdx<m;i++){
        if(house[houseIdx] < arr[i]-k){
            houseIdx++;
            i--;
        }
        else if(arr[i]+k < house[houseIdx]){
        }
        else{
            houseIdx++;
            ans++;
        }
    }
    printf("%lld\n", ans);
}