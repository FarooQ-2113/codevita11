#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m；
    cin>>n>>m；
    // Telegram - @PLACEMENTLELO
    vector<vector<int>> cust;
    for(int i=0; i<n; i++){
        int q,p;
        cin>>q>>p;
        cust.push_back({p,q});
    }
    // Telegram - @PLACEMENTLELO
    vector<vector<int>> rice;
    for(int i=0; i<m; i++){
        int q,p;
        cin>>q>>p;
        rice.push_back({p,q});
    }
    // Telegram - @PLACEMENTLELO
    sort(cust.begin(), cust.end());
    sort(rice.begin(), rice.end());
    // Telegram - @PLACEMENTLELO
    vector<int> placementlelo(m,0);
    // Telegram - @PLACEMENTLELO
    int ans = 0;
    // Telegram - @PLACEMENTLELO
    for(int i=0; i<n; i++){
        int quan = -1;
        int index = -1;
        for(int j=0; j<m; j++){
            if(!placementlelo[j]){
                // Telegram - @PLACEMENTLELO
                if(rice[j][0] > cust[i][0]) break;
                
                if(rice[j][1] > cust[i][1]){
                    if(quan == -1){
                        quan = rice[j][1];
                        index = j;
                    }
                    else{
                        if(quan > rice[j][1]){
                            index = j;
                            quan = rice[j][1];
                        }
                    }
                }
            }
        }
        // Telegram - @PLACEMENTLELO
        if(index != -1){
            placementlelo[index] = 1;
            ans++;
        }
    }
    // Telegram - @PLACEMENTLELO
    cout<<ans;
}
    
