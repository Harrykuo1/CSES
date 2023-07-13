#include<bits/stdc++.h>
using namespace std;
#define int long long

int  n, x;
int arr[25];
int person[1<<21];
int weight[1<<21];

int32_t main(){
    memset(person, 0x3f, sizeof(person));
    memset(weight, 0x3f, sizeof(weight));
    scanf("%lld %lld", &n, &x);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    person[0] = 1;
    weight[0] = 0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if (((1 << j) & i) == 0) continue;
            int pre = i & ~(1<<j);
            if(weight[pre] + arr[j] <= x){
                if(person[pre] < person[i] || (person[pre] == person[i] && weight[pre] + arr[j] < weight[i])){
                    person[i] = person[pre];
                    weight[i] = weight[pre] + arr[j];
                }
            }
            else{
                if(person[pre] + 1 < person[i] || (person[pre] + 1 == person[i] && weight[pre] > arr[j])){
                    person[i] = person[pre] + 1;
                    weight[i] = arr[j];
                }
            }
        }
    }
    printf("%lld\n", person[(1<<n) - 1]);
}