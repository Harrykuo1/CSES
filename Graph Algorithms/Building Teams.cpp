#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
vector<vector<int>> graph;
int group[100005];

void dfs(int id, int groupID){
    group[id] = groupID;
    for(auto i : graph[id]){
        if(group[i] == groupID){
            printf("IMPOSSIBLE\n");
            exit(0);
        }
        if(group[i] == 0){
            if(groupID == 1){
                dfs(i, 2);
            }
            else{
                dfs(i, 1);
            }
        }

    }
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(group[i] == 0){
            dfs(i, 1);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ", group[i]);
    }
}