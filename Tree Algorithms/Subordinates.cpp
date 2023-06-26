#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num;
vector<vector<int>> graph;
vector<int> ans;

void dfs(int now){
    int sum = 0;
    for(int i : graph[now]){
        dfs(i);
        sum += ans[i];
    }
    ans[now] = sum + graph[now].size();
}

int32_t main(){
    scanf("%lld", &n);
    graph.resize(n+1);
    ans.resize(n+1);
    for(int i=2;i<=n;i++){
        scanf("%lld", &num);
        graph[num].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        printf("%lld ", ans[i]);
    }
}