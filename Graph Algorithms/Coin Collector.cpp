#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int coin[100005];
vector<vector<int>> graph;
vector<vector<int>> reverse_graph;
vector<vector<int>> scc_graph;
vector<int> order;
bool visited[100005];
int group[100005];
int sccCoin[100005];
int inDegree[100005];
int dp[100005];

void init(){
    graph.resize(n+1);
    reverse_graph.resize(n+1);
    scc_graph.resize(n+1);
}

void dfs1(int id){
    visited[id] = true;
    for(auto i : graph[id]){
        if(!visited[i]){
            dfs1(i);
        }
    }
    order.push_back(id);
}

void dfs2(int id, int groupID){
    visited[id] = true;
    group[id] = groupID;
    sccCoin[groupID] += coin[id];
    for(auto i : reverse_graph[id]){
        if(!visited[i]){
            dfs2(i, groupID);
        }
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    init();
    for(int i=1;i<=n;i++){
        scanf("%lld" ,&coin[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    reverse(order.begin(), order.end());

    int scc = 0;
    for(auto i : order){
        if(!visited[i]){
            dfs2(i, ++scc);
        }
    }

    for(int i=1;i<=n;i++){
        for(auto j : graph[i]){
            int groupI = group[i];
            int groupJ = group[j];
            if(groupI != groupJ){
                inDegree[groupJ]++;
                scc_graph[groupI].push_back(groupJ);
            }
        }
    }

    queue<int> q;
    for(int i=1;i<=scc;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    int ans = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        dp[now] += sccCoin[now];
        ans = max(ans, dp[now]);
        for(auto i : scc_graph[now]){
            dp[i] = max(dp[i], dp[now]);
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }
    printf("%lld\n", ans);
}
