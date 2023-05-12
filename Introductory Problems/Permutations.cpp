#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

int32_t main(){
    scanf("%lld", &n);
    if(n==2 || n==3){
        printf("NO SOLUTION");
        return 0;
    }
    for(int i=n+(n%2)-1;i>=1;i-=2){
        printf("%lld ", i);
    }
    for(int i=n-(n%2);i>=2;i-=2){
        printf("%lld ", i);
    }
    
}