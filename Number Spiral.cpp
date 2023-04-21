#include<bits/stdc++.h>
using namespace std;
#define int long long

int t, x, y;

int32_t main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &y, &x);
        if(y==1 && x==1){
            printf("1\n");
            continue;
        }
        if(y >= x){
            if(y % 2){
                int square = (y-1)*(y-1);
                printf("%lld\n", square + x);
            }
            else{
                int square = y * y;
                printf("%lld\n", square - x + 1);
            }
        }
        else{
            if(x % 2){
                int square = x * x;
                printf("%lld\n", square - y + 1);
            }
            else{
                int square = (x-1)*(x-1);
                printf("%lld\n", square + y);
            }
        }
    }
    
}