#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, sum1=0, sum2=0;
    vector<int> vec1;
    vector<int> vec2;
    scanf("%lld", &n);
    for(int i=n;i>0;i--){
        if(sum1 <= sum2){
            sum1 += i;
            vec1.push_back(i);
        }
        else{
            sum2 += i;
            vec2.push_back(i);
        }
    }
    if(sum1 != sum2){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        printf("%lld\n", vec1.size());
        for(int i=vec1.size()-1;i>=0;i--){
            printf("%lld ", vec1[i]);
        }
        printf("\n%lld\n", vec2.size());
        for(int i=vec2.size()-1;i>=0;i--){
            printf("%lld ", vec2[i]);
        }
    }
}