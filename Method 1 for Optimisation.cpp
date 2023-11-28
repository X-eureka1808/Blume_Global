//Warehouse3
//Method 1

#include <iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main() {
    //distance matrix
    int cities=5;
    int distance[6][6] = {
        {1000,200,210,220,230,240},
        {200,1000,15,25,35,5},
        {210,15,1000,35,45,50},
        {220,25,35,1000,10,15},
        {230,35,45,10,1000,16},
        {240,5,50,15,16,1000}
    };
    int distance2[6][5];
    for(int i=0;i<6;i++){
        for(int j=0;j<5;j++){
        distance2[i][j]=distance[i][j+1];
    }
    cout<<endl;
}


for (int i = 0; i < 6; ++i) {
       sort(begin(distance2[i]), end(distance2[i]));
    } 

    
    int row=0,index=0,quantity_wt=0,quantity_v=0,dst=0;
    int q_wt[cities]={22972,25985,31799,23611,22392};
    int q_v[cities]={1679,1494,2065,1555,1459};
    int route[10]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int Q_wt=61200,Q_v=2389,r=0,i=0,d=0;
    for(int p=0;p<cities;p++){
        for(int j=1;j<cities+1;j++){
            if(distance[row][j]==distance2[row][d]) 
                { if(j==index) continue; 
                    index=j;
                for(int m=0;m<10;m++){
                    if(route[m]==index){
                        p--;d++;break;
                    }if(m==9) d=0;
                } if(d!=0) break;
                
                quantity_wt=quantity_wt+q_wt[index-1];
                quantity_v=quantity_v+q_v[index-1];
                if(quantity_wt>Q_wt || quantity_v>Q_v ) 
                {quantity_wt=0;quantity_v=0;
                row=0;
                route[i]=-1;
                i++;j=0;d++;
                continue;
                }
                break;
                }
        } 
        if(d==0){
        route[i]=index;
        row=index;i++;}
    }int count =1;
    cout<<"Route 1(Starts and ends at 0)=> ";
    for(int r=0;r<10;r++){
        if(route[r]==-1) {
            count++;
            cout<<endl<<"Route "<<count<<"(Starts and ends at 0)=> ";
        }
        else cout<<route[r]+20<<"  ";
        }cout<<endl;cout<<endl;cout<<endl;
        
        dst=dst+distance[0][route[0]];
        
    for(int r=1;r<10;r++){
        if(route[r]!=-1 && route[r-1]!=-1)
            {dst=dst+distance[route[r-1]][route[r]];}
            
        else if(route[r]==-1)
            {dst=dst+distance[0][route[r-1]];}
            
        else   
            {dst=dst+distance[0][route[r]];}
    }
    cout<<"distance travelled is "<<dst<<endl;
        
        
    return 0;
}
