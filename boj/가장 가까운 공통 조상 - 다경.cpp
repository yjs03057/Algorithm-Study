#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int T,N;
map<int,int> child_parent; //<자식, 부모>
int node1, node2, ans;
vector<int> parent1; //node1의 부모들
void findParent(int n){ //node1의 부모들 찾기
    int cur=n;

    parent1.push_back(cur);
    while(1){
        if(child_parent[cur]==0) break;
        cur = child_parent[cur];
        parent1.push_back(cur);
    }
    return;
}
void findCommonParent(){ //공통 부모 찾기

    vector<int>::iterator it;
    while(1){
        it = find(parent1.begin(), parent1.end(),node2);
        if(it!=parent1.end()){
            ans=node2;
            return;
        }
        else node2 = child_parent[node2];
    }

}
int main(){
    int A,B;

    cin>>T;
    while(T--){
        child_parent.clear();
        parent1.clear();
        cin>>N;
        for(int i=0; i<N-1; i++){
            cin>>A>>B;
            child_parent[B]=A;
        }
        cin>>node1>>node2;
        findParent(node1);
        findCommonParent();
        cout<<ans<<'\n';
    }

    return 0;
}