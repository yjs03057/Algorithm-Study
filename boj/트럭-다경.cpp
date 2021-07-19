#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main(){
    int n,w,L; //다리를 건너는 트럭의 수, 다리의 길이, 다리 최대 하중
    vector<int> trucks;
    int tmp, ans=0;
    int cur=0,weight=0,cnt=0;
    int bridge[1000];
    memset(bridge,-1,sizeof(bridge));

    cin>>n>>w>>L;
    for(int i=0; i<n; i++){
        cin>>tmp; //트럭 무게
        trucks.push_back(tmp);
    }

    while(cnt<n){
        //트럭들 이동
        for(int i=w-1; i>=0; i--){
            bridge[i+1] = bridge[i];
        }
        bridge[0] = -1;
        if(bridge[w]!=-1){ //도착한 트럭
            weight-=trucks[bridge[w]];
            cnt++;
        }
        //새로운 트럭이 다리로
        if(trucks[cur]+weight<=L && cur<n){
            bridge[0] = cur;
            weight += trucks[cur];
            cur++;
        }
        ans++;
    }

    cout<<ans;

    return 0;
}