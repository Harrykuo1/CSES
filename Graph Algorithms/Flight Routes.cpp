#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a, b, w;

int32_t main(){
    scanf("%lld %lld %lld", &n, &m, &k);
    vector<pair<int, int>> graph[n+1];
    vector<int> ans[n+1];
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld", &a, &b, &w);
        graph[a].push_back({w, b});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if(ans[now.second].size() > k) continue;
        ans[now.second].push_back(now.first);
        for(auto it : graph[now.second]){
            int nxtW = now.first + it.first;
            int nxtNode = it.second;
            pq.push({nxtW, nxtNode});
        }
    }
    for(int i=0;i<k;i++){
        printf("%lld ", ans[n][i]);
    }
    printf("\n");
}