#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int inDegree[100005];
int dp[100005];
int pre[100005];

void init(){
    for(int i=0;i<=n;i++){
        pre[i] = INT_MIN;
        dp[i] = INT_MIN;
    }
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    init();
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        scanf("%lld %lld", &a, &b);
        graph[a].push_back(b);
        inDegree[b]++;
    }   

    queue<int> q;
    dp[1] = 0;
    for(int i=1;i<=n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto i : graph[now]){
            inDegree[i]--;
            if(dp[i] < dp[now] + 1){
                dp[i] = dp[now] + 1;
                pre[i] = now;
            }
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
    }
    if(dp[n] <= -1){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    ans.push_back(n);
    while(ans.back() != 1){
        ans.push_back(pre[ans.back()]);
    }

    printf("%lld\n", ans.size());
    for(int i=ans.size()-1;i>=0;i--){
        printf("%lld ", ans[i]);
    }
    printf("\n");
}
