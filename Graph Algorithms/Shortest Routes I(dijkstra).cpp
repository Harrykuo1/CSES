#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b, w;
int dis[100005];

int32_t main(){
    memset(dis, 0x3F, sizeof(dis));

    scanf("%lld %lld", &n, &m);
    vector<pair<int, int>> edges[n+5];
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld", &a, &b, &w);
        edges[a].push_back({w, b});
    }

    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto head = pq.top();
        pq.pop();
        if(head.first > dis[head.second]){
            continue;
        }
        for(auto i:edges[head.second]){
            if(dis[i.second] > head.first + i.first){
                dis[i.second] = head.first + i.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ", dis[i]);
    }
    printf("\n");
}