#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, q, num;

int32_t main(){
    scanf("%lld %lld", &n, &q);
    multiset<int> s;
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        s.insert(num);
    }
    while(q--){
        scanf("%lld", &num);
        auto it = s.upper_bound(num);
        if(it == s.begin()){
            printf("-1\n");
        }
        else{
            it--;
            printf("%lld\n", *it);
            s.erase(it);
        }
    }
}