#include <iostream>
#include <cstring>
using namespace std;
int k;
char sign[9];
string ans="";
bool visited[10];
int solveMax(int cur, int cnt, string s){
    if(cnt==k){
        s+=cur+'0';
        ans = s;
        return 1;
    }

    //부등호 비교
    int ret;
    if(sign[cnt]=='<'){
        for(int i=9; i>=0; i--){
            if(cur<i && !visited[i]){
                visited[i] = true;
                s+=cur+'0';
                ret = solveMax(i,cnt+1,s);
                if(ret) return 1;
                s = s.erase(s.length()-1);
                visited[i] = false;
            }
        }
    }
    else{ // >
        for(int i=9; i>=0; i--){
            if(cur>i && !visited[i]){
                visited[i] = true;
                s+=cur+'0';
                ret = solveMax(i,cnt+1,s);
                if(ret) return 1;
                s = s.erase(s.length()-1);
                visited[i] = false;
            }
        }
    }

    return 0;
}
int solveMin(int cur, int cnt, string s){
    if(cnt==k){
        s+=cur+'0';
        ans = s;
        return 1;
    }

    //부등호 비교
    int ret;
    if(sign[cnt]=='<'){
        for(int i=0; i<=9; i++){
            if(cur<i && !visited[i]){
                visited[i] = true;
                s+=cur+'0';
                ret = solveMin(i,cnt+1,s);
                if(ret) return 1;
                s = s.erase(s.length()-1);
                visited[i] = false;
            }
        }
    }
    else{ // >
        for(int i=0; i<=9; i++){
            if(cur>i && !visited[i]){
                visited[i] = true;
                s+=cur+'0';
                ret = solveMin(i,cnt+1,s);
                if(ret) return 1;
                s = s.erase(s.length()-1);
                visited[i] = false;
            }
        }
    }
    return 0;
}
int main(){
    int ret;
    char c;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>c;
        sign[i] = c;
    }

    //최대값
    memset(visited, false, sizeof(visited));
    for(int i=9; i>=0; i--){
        visited[i] = true;
        ret = solveMax(i,0,"");
        visited[i] = false;
        if(ret) break;
    }
    cout<<ans<<endl;
    ans="";
    //최소값
    memset(visited, false, sizeof(visited));
    for(int i=0; i<=9; i++){
        visited[i] = true;
        ret = solveMin(i,0,"");
        visited[i] = false;
        if(ret) break;
    }
    cout<<ans<<endl;

    return 0;
}