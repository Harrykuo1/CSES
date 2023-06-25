#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<int> graph[100005];
int visited[100005];
int pre[100005];
vector<int> ans;

void dfs(int id){
    visited[id] = 1;
    for(int i : graph[id]){
        if(visited[i] == 0){
            pre[i] = id;
            dfs(i);
        }
        else if(visited[i] == 1){
            ans.push_back(id);
            int now = id;
            while(now != i){
                now = pre[now];
                ans.push_back(now);
            }
            ans.push_back(id);
            printf("%lld\n", ans.size());
            for(int i=ans.size()-1;i>=0;i--){
                printf("%lld ", ans[i]);
            }
            printf("\n");
            exit(0);
        }
    }
    visited[id] = 2;
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            pre[i] = i;
            dfs(i);
        }
    }
    printf("IMPOSSIBLE\n");
}