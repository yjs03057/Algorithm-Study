#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N;
vector<long long> arr;
int main(){
    int start,end;
    int s,m,e;
    long long ans=9876543219876543210, sum=0, tmp=0;

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<N-2; i++){ // i 고정
        start = i+1, end= N-1;
        while(start<end){
            sum = arr[i]+arr[start]+arr[end];
            if(abs(ans)>abs(sum)){
                ans = sum;
                s=i, m=start, e=end;
            }
            if(sum<0 && start+1<end) start++;
            else{
                if(end-1==start) break;
                end--;
            }
        }

        if(ans==0) break;

    }

    cout<<arr[s]<<' '<<arr[m]<<' '<<arr[e];

    return 0;
}