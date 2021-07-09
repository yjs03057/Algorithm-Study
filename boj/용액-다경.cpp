#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N,tmp;
    int start=0, end=0, sum=0;
    vector<int> nums;
    int ans=2000000001;
    pair<int,int> two_pointers;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        nums.push_back(tmp);
    }

    int j=N-1;
    for(int i=0; i<N-1; i++){
        while(abs(nums[i]+nums[j]) > abs(nums[i]+nums[j-1])
           && i!=j && i!=j-1) j--;
        sum = nums[i]+nums[j];
        if(i==j) break;
        if(ans>abs(sum)){
            ans = abs(sum);
            two_pointers = {i,j};
        }
        //else break; -> 여기 삭제ㅜㅜ
    }

    cout<<nums[two_pointers.first]<<' '<<nums[two_pointers.second];

    return 0;
}