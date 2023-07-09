#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, tmp;

int32_t main(){
    scanf("%lld", &n);
    queue<int> q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(!q.empty()){
        tmp = q.front(); q.pop();
        q.push(tmp);
        tmp = q.front(); q.pop();
        printf("%lld ", tmp);
    }
}