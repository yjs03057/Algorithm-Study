#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,ans=1;
vector<int> v; //비밀번호에 들어가는 수
int main(){
    int tmp;

    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>tmp;
        v.push_back(tmp);
    }

    string s="";
    for(int i=0; i<n; i++){
        s += "0";
        ans *= 10;
    }
    string end = "1"+s;
    while(s!=end){
        //cout<<s<<' ';
        for(int i=0; i<m; i++){
            char c = v[i]+'0';
            if(s.find(c)==string::npos){
                //없음
                ans--;
                break;
            }
        }
        int num = stoi(s);
        num++;
        s = to_string(num);
        if(s.size()<n){
            string tmp="";
            for(int i=0; i<n-s.size(); i++){
                tmp += "0";
            }
            s = tmp+s;
        }
    }
    cout<<ans;

    return 0;
}