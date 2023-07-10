#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, ans = 1, roomID;

struct Custom{
    int st, ed, id;
    bool operator < (const Custom &R)const{
        return st < R.st;
    }
};
Custom arr[200005];
int room[200005];

int32_t main(){
    scanf("%lld", &n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld", &arr[i].st, &arr[i].ed);
        arr[i].id = i;
    }
    sort(arr, arr+n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({-1, 1});
    for(int i=0;i<n;i++){
        if(pq.top().first < arr[i].st){
            roomID = pq.top().second;
            pq.pop();
        }
        else{
            roomID = ++ans;
        }
        room[arr[i].id] = roomID;
        pq.push({arr[i].ed, roomID});
    }
    printf("%lld\n", ans);
    for(int i=0;i<n;i++){
        printf("%lld ", room[i]);
    }
}