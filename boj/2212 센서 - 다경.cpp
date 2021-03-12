#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
long long ans=0;
vector<int> v;
vector<int> diff;

int main(){
    int tmp;

    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    //1,3,6,6,7,9 -> K개 구간으로 나눠야 함
    //차: 2,3,1,2 ->k-1개 제거 후 합
    for(int i=0; i<n-1; i++){
        if(v[i+1]-v[i]<1) continue;
        diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.begin(), diff.end());
    //1,2,2,3
    int diffsize = diff.size();
    //그냥 diff.size() 사용하면 런타임 에러 (diff.size()->size_t형을 반환하므로)
    //꼭 int 형으로 변환해주어야 함.
    for(int i=0; i<diffsize-(k-1); i++){
        ans += diff[i];
    }

    cout<<ans<<endl;

    return 0;
}