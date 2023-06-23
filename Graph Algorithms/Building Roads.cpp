#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int dsu[100005];
void init(){
    for(int i=1;i<=n;i++){
        dsu[i] = i;
    }
}

int finds(int num){
    if(dsu[num] == num){
        return num;
    }
    return dsu[num] = finds(dsu[num]);
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    init();
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        dsu[finds(a)] = finds(b);
    }
    vector<int> vec;
    for(int i=1;i<=n;i++){
        if(dsu[i] == i){
            vec.push_back(i);
        }
    }
    printf("%lld\n", vec.size()-1);
    for(int i=0;i<vec.size()-1;i++){
        printf("%lld %lld\n", vec[i], vec[i+1]);
    }
}