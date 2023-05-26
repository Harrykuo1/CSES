#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, num;
    scanf("%lld", &n);
    vector<int >vec;

    scanf("%lld", &num);
    vec.push_back(num);
    n--;

    while(n--){
        scanf("%lld", &num);
        if(num >= vec[vec.size()-1]){
            vec.push_back(num);
        }
        else{
            auto it = upper_bound(vec.begin(), vec.end(), num);
            *it = num;
        }
    }
    printf("%lld\n", vec.size());
}