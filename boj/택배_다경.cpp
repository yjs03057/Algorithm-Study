//8980
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N,C,M; //마을의 수, 트럭 용량, 보내는 박스 정보 개수
vector<pair<pair<int,int>,int>> boxes; //<<목적지,출발지> 박스 개수>
int truck[2001];
int truckValue=0;
int ans=0;
int main(){
    int s,e,box;
    int capacity=0;

    cin>>N>>C>>M;
    for(int i=0; i<M; i++){
        cin>>s>>e>>box;
        boxes.push_back({{e,s},box});
    }
    sort(boxes.begin(), boxes.end()); //목적지 순으로 정렬
    memset(truck,0,sizeof(truck));

    for(int i=0; i<boxes.size(); i++){
        e = boxes[i].first.first;
        s = boxes[i].first.second;
        box = boxes[i].second;
        truckValue=0;

        //시작 ~ 도착마을-1까지
        for(int j=s; j<=e-1; j++){
            truckValue = max(truckValue, truck[j]); //트럭이 싣고 있는 최대값
        }

        capacity = min(box, C-truckValue); //싣을수 있는 만큼 싣기 위해
        ans += capacity;

        //시작 ~ 도착마을-1까지
        for(int j=s; j<=e-1; j++){
            truck[j] += capacity;
        }
    }

    cout<<ans<<"\n";

    return 0;
}