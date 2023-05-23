#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int n, num;
    vector<int> arr;
    scanf("%lld", &n);
    scanf("%lld", &num);
    arr.push_back(num);

    for(int i=1;i<n;i++){
        scanf("%lld", &num);
        if(num > arr[arr.size()-1]){
            arr.push_back(num);
        }
        else{
            auto it = lower_bound(arr.begin(), arr.end(), num);
            *it = num;
        }
    }
    printf("%lld\n", arr.size());
}