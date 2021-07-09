#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M;
    vector<int> nums; //수열 합이 M이 되는 경우의 수 구하기
    int tmp, ans=0;

    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>tmp;
        nums.push_back(tmp);
    }

    int start=0,end=0,sum=nums[0];
    while(start<N){
        if(sum<=M){
            if(sum==M) ans++;
            if(end==N-1){
                sum -= nums[start];
                start++;
            }
            else{
                end++;
                sum+=nums[end];
            }
        }
        else{
            sum -= nums[start];
            start++;
        }
    }

    cout<<ans;

    return 0;
}