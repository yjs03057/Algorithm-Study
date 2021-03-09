#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> cranes;
vector<int> boxes;
bool compare(int i, int j){
    return j<i;
}
int main(){
    int tmp;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        cranes.push_back(tmp);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>tmp;
        boxes.push_back(tmp);
    }

    sort(cranes.begin(), cranes.end(),compare);
    sort(boxes.begin(), boxes.end(),compare);

    // 각 크레인에 1분에 박스 하나씩 실을 수 있음.
    // 크레인 최대 무게 < 박스 무게 -> -1 (실을 수 없음)
    int ans=0;
    if(cranes[0] < boxes[0]){
        ans = -1;
    }
    else{
        while(boxes.size()>0){
            ans++;
            for(int i=0; i<cranes.size(); i++){
                for(int j=0; j<boxes.size(); j++){
                    if(cranes[i] >= boxes[j]){
                        boxes.erase(boxes.begin()+j);
                        break;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}