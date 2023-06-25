#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, num, ans=0;

int32_t main(){
    map<int, int> mp;
    queue<int> vec;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld", &num);
        vec.push(num);
        if(mp.find(num) == mp.end() || !mp[num]){
            mp[num] = 1;
            ans = max(ans, (int)vec.size());
        }
        else{
            while(!vec.empty() && vec.front()!=num){
                mp[vec.front()] = 0;
                vec.pop();
            }
            vec.pop();
        }
    }
    printf("%lld\n", ans);
}