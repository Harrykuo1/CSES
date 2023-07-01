#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, arr[105];

int32_t main(){
    set<int> s;
    s.insert(0);
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &arr[i]);
    }
    for(int i=0;i<n;i++){
        for(auto it = s.rbegin(); it != s.rend();it++){
            s.insert(arr[i] + *it);
        }
    }

    printf("%lld\n", s.size()-1);
    for(auto i : s){
        if(i == 0) continue;
        printf("%lld ", i);
    }
}