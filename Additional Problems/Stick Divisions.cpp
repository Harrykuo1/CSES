#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x, num, a, b, ans = 0;

int32_t main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    scanf("%lld %lld", &x, &n);
    for(int i=0;i<n;i++){
        scanf("%lld", &num);
        pq.push(num);
    }
    while(pq.size() > 1){
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    printf("%lld\n", ans);
}