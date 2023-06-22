#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;

signed main(){
    scanf("%lld %lld", &n ,&m);

    vector<vector<int>> edges;
    edges.resize(n+1);
    int *outDegree = (int*)calloc(n+1, sizeof(int));

    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        outDegree[a]++;
        edges[b].push_back(a);
    }

    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(outDegree[i] == 0){
            pq.push(i);
        }
    }
    vector<int> ans;
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        ans.push_back(now);
        for(auto i : edges[now]){
            outDegree[i]--;
            if(outDegree[i] == 0){
                pq.push(i);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans){
        printf("%lld ", i);
    }
}