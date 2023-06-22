#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int inDegree[100005];

int32_t main(){
    scanf("%lld %lld", &n, &m);
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        inDegree[b]++;
        graph[a].push_back(b);
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for(auto i : graph[now]){
            inDegree[i]--;
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }

    if(ans.size() != n){
        printf("IMPOSSIBLE\n");
    }
    else{
        for(auto i : ans){
            printf("%lld ", i);
        }
    }
}