#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<int> dis;
vector<vector<int>> graph;
vector<int> pre;

int32_t main(){
    scanf("%lld %lld", &n, &m);
    dis.assign(n+1, INT_MAX);
    pre.assign(n+1, -1);
    graph.resize(n+1);

    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dis[1] = 1;
    pre[1] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 1});
    while(!pq.empty()){
        int disNow = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(disNow > dis[now]) continue;
        for(auto i : graph[now]){
            if(dis[i] <= disNow + 1){
                continue;
            }
            dis[i] = disNow + 1;
            pre[i] = now;
            pq.push({dis[i], i});
        }
    }

    if(dis[n] == INT_MAX){
        printf("IMPOSSIBLE\n");
    }
    else{
        vector<int> ans;
        int i = n;
        ans.push_back(n);
        while(pre[i] != i){
            i = pre[i];
            ans.push_back(i);
        }
        printf("%lld\n", ans.size());
        for(int i=ans.size()-1;i>=0;i--){
            printf("%lld ", ans[i]);
        }
    }
    

}