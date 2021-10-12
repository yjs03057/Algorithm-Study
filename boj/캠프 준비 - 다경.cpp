#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,L,R,X;
int ans=0;
vector<int> v;
void combination(int idx, int sum, int low, int high){
    //조건에 맞을 경우
    if(sum>=L && sum<=R && high-low>=X) ans++;
    //else
    if(idx==N) return;
    if(sum>R) return;


    for(int i=idx; i<N; i++){
        combination(i+1,sum+v[i],low,v[i]);
    }
    return;
}

int main(){
    int tmp;

    cin>>N>>L>>R>>X;
    for(int i=0; i<N; i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    //10 10 10 20 20

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            combination(j+1,v[i]+v[j],v[i],v[j]);
        }
    }

    cout<<ans;

    return 0;
}