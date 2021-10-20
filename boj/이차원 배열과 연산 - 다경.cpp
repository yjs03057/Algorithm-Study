#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
int r,c,k;
int ans=0;
int cnt[101];
vector<vector<int>> A;
void R(){
    int row=A.size(), column=A[0].size();
    int maxcol=0;
    priority_queue<pair<int,int>> pq; //<등장횟수, 수>

    for(int i=0; i<row; i++){
        memset(cnt, 0, sizeof(cnt));

        for(int j=0; j<column; j++){
            cnt[A[i][j]]++;
        }

        for(int j=1; j<101; j++){
            if(cnt[j]>0) pq.push({-cnt[j], -j});
        }

        A[i].clear();
        while (!pq.empty()){
            A[i].push_back({-pq.top().second});
            A[i].push_back({-pq.top().first});
            pq.pop();
        }
    }

    //크기 맞춰주기
    for(int i=0; i<row; i++){
        maxcol = max(maxcol,(int)A[i].size());
        if(maxcol>100){
            column = A[i].size()-100;
            while(column--){
                A[i].pop_back();
            }
            maxcol=100;
        }
    }
    for(int i=0; i<row; i++){
        if(maxcol==A[i].size()) continue;
        else column = maxcol-A[i].size();
        for(int j=0; j<column; j++){
            A[i].push_back(0);
        }
    }

    return;
}
void C(){
    int row=A.size(), column=A[0].size();
    priority_queue<pair<int,int>> pq; //<등장횟수, 수>

    for(int j=0; j<column; j++){
        memset(cnt, 0, sizeof(cnt));

        for(int i=0; i<row; i++){
            cnt[A[i][j]]++;
        }

        for(int i=1; i<101; i++){
            if(cnt[i]>0) pq.push({-cnt[i], -i});
        }

        int i=0;
        while(!pq.empty()){
            if(A.size()<=i && A.size()<100){
                if(i>100) i=100;
                vector<int> v;
                for(int k=0; k<column; k++) v.push_back(0);
                A.push_back(v);
            }
            A[i][j] = -pq.top().second;
            i++;

            if(A.size()<=i && A.size()<100){
                if(i>100) i=100;
                vector<int> v;
                for(int k=0; k<column; k++) v.push_back(0);
                A.push_back(v);
            }
            A[i][j] = -pq.top().first;
            i++;
            pq.pop();
        }
        if(i<A.size()){
            while(i<A.size()){
                A[i][j]=0;
                i++;
            }
        }
    }

    return;
}

int main(){
    // (r>=c) 행에 대해서 정렬(R) -> 행 크기 변화
    // (r<c) 열에 대해서 정렬(C) -> 열 크기 변화
    // 정렬 1) 등장 횟수 오름차순 2) 수 오름차순

    vector<int> v;
    int tmp, ans=0;

    cin>>r>>c>>k;
    for(int i=0; i<3; i++){
        v.clear();
        for(int j=0; j<3; j++){
            cin>>tmp;
            v.push_back(tmp);
        }
        A.push_back(v);
    }

    // 처음 주어진 3*3 보다 r,c 값이 더 클 경우
    while(A.size()<r || A[0].size()<c){
        if(A.size()>=A[0].size()) R();
        else C();
        ans++;
        if(ans>100){
            cout<<-1;
            return 0;
        }
    }
    while(A[r-1][c-1]!=k){
        if(A.size()>=A[0].size()) R();
        else C();

        ans++;
        if(ans>100){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;

    return 0;
}