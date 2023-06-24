#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int dsu[100005];

void init(){
    for(int i=0;i<=n;i++){
        dsu[i] = -1;
    }
}
int finds(int num){
    if(dsu[num] < 0){
        return num;
    }
    return dsu[num] = finds(dsu[num]);
}
bool isSame(int a, int b){
    return finds(a) == finds(b);
}
void unions(int a, int b){
    a = finds(a);
    b = finds(b);
    if(dsu[a] > dsu[b]){
        swap(a, b);
    }
    dsu[a] += dsu[b];
    dsu[b] = a;
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    init();
    int biggest = 1;
    while(m--){
        scanf("%lld %lld", &a, &b);
        if(!isSame(a, b)){
            n--;
            unions(a, b);
            biggest = max(biggest, -dsu[finds(a)]);
        }
        printf("%lld %lld\n", n, biggest);
    }
}