#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, a, b;
int arr[200005];
map<int, int> idx;

int count(){
    int l_bound = INT_MAX, ans = 0;
    for(int i=1;i<=n;i++){
        if(idx[i] < l_bound){
            ans++;
        }
        l_bound = idx[i];
    }
    return ans;
}

int32_t main(){
    scanf("%lld %lld", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%lld", &arr[i]);
        idx[arr[i]] = i;
    }
    arr[n+1] = n+1;
    idx[0] = 0;
    idx[n+1] = n+1;
    int ans = count();
    while(m--){
        scanf("%lld %lld", &a, &b);
        int A = arr[a];
        int B = arr[b];
        if(b < idx[A-1]) ans++;
        if(a < idx[A-1]) ans--;

        if(idx[A+1] <= b) ans++;
        if(idx[A+1] <= a) ans--;
        
        if(a < idx[B-1]) ans++;
        if(b < idx[B-1]) ans--;

        if(idx[B+1] <= a) ans++;
        if(idx[B+1] <= b) ans--;
        
        idx[A] = b;
        idx[B] = a;
        swap(arr[a], arr[b]);
        printf("%lld\n", ans);
    }
}
