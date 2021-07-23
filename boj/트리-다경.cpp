#include <iostream>
#include <vector>
using namespace std;
int T,n;
vector<int> preorder; //현재 노드 -> 왼 -> 오
vector<int> inorder; //왼 -> 현재 노드 -> 오
vector<int> ans;// postorder : 왼 -> 오 -> 현재 노드

void divided(int start, int end, int root){


    for(int i=start; i<end; i++){
        if(preorder[root]==inorder[i]){
            divided(start,i,root+1);
            divided(i+1,end,root+1+i-start); //root+1+i-start 이거 알아내기가 제일 어려웠음.
            ans.push_back(preorder[root]);
        }
    }

}

int main(){
    int tmp;

    cin>>T;
    for(int i=0; i<T; i++){
        preorder.clear();
        inorder.clear();
        ans.clear();
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>tmp;
            preorder.push_back(tmp);
        }
        for(int j=0; j<n; j++){
            cin>>tmp;
            inorder.push_back(tmp);
        }
        divided(0,n,0);
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}