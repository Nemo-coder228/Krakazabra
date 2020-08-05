#include <bits/stdc++.h>
using namespace std;
const int n=3;
int k=0, o , p;
int a[n][n];

int winner(){
    int t , m=0;
    for(int i=0; i<n; i++){
        t=0;
        for(int j=0; j<n-1; j++){
            if (a[i][j]==a[i][j+1] && a[i][j]!=0)
                t++;
        }
        if(t==n-1){
            if (a[i][n-1]==1){
                cout<<endl;
                cout<<"win first";
                m=1;
                return m;
            }
            else{
                cout<<endl;
                cout<<"win second";
                m=1;
                return m;
            }
        }
    }
    for(int i=0; i<n; i++){
        t=0;
        for(int j=0; j<n-1; j++){
            if (a[j][i]==a[j+1][i] && a[j][i]!=0)
                t++;
        }
        if(t==n-1){
            if (a[n-1][i]==1){
                cout<<endl;
                cout<<"win first";
                m=1;
                return m;
            }
            else{
                cout<<endl;
                cout<<"win second";
                m=1;
                return m;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        t=0;
        if(a[i][i]==a[i+1][i+1] && a[i][i]!=0)
            t++;
        if(t==n-1){
            if (a[n-1][i]==1){
                cout<<endl;
                cout<<"win first";
                m=1;
                return m;
            }
            else{
                cout<<endl;
                cout<<"win second";
                m=1;
                return m;
            }
        }
    }
    for(int i=0; i<n-1; i++){
        t=0;
        if(a[n-i-1][i]==a[n-i-2][i+1] && a[n-i-1][i]!=0)
            t++;
        if(t==n-1){
            if (a[n-1][i]==1){
                cout<<endl;
                cout<<"win first";
                m=1;
                return m;
            }
            else{
                cout<<endl;
                cout<<"win second";
                m=1;
                return m;
            }
        }
    }
    if(k==n*n){
        cout<<endl;
        cout<<"We have a draw";
        m=1;
        return m;
    }
    return m;
}

void ttt(){
    int y , x;
    while (k<=n*n){
        k++;
        if(o==0 && p==0){
            if(k%2==1){
                cout<<"first move"<<':';
                cin>>x>>y;
            }
            else{
                cout<<"second move"<<':';
                cin>>x>>y;
            }
        }
        else{
            if(o==1 && p==1){
                if(k%2==1){
                    x=rand()%n+1;
                    y=rand()%n+1;
                }
                else{
                    x=rand()%n+1;
                    y=rand()%n+1;
                }
            }
            else{
                if(k%2==1){
                    cout<<"first move"<<':';
                    cin>>x>>y;
                }
                else{
                    x=rand()%n+1;
                    y=rand()%n+1;
                }
            }
    }
        if (k%2==1){
            if (a[x-1][y-1]!=0){
                cout<<"the place is occupied"<<" , "<<"enter again"<<endl;
                k--;
                ttt();
                return;
            }
            a[x-1][y-1]=1;
        }
        else{
             if (a[x-1][y-1]!=0){
                cout<<"the place is occupied"<<" , "<<"enter again"<<endl;
                k--;
                ttt();
                return;
            }
            a[x-1][y-1]=2;
        }
        system ("cls");
        for(int i=0;  i<n; i++){
            for(int j=0;  j<n; j++){
                if(a[i][j]==1)
                    if(j==2)
                        cout<<' '<<'X';
                    else
                        cout<<' '<<'X'<<' '<<'|';
                if(a[i][j]==2)
                    if(j==2)
                        cout<<' '<<'0';
                    else
                        cout<<' '<<'0'<<' '<<'|';
                if(a[i][j]==0)
                    if(j==2)
                        cout<<' '<<'*';
                    else
                        cout<<' '<<'*'<<' '<<'|';
            }
            if(i!=2){
                cout<<endl;
                cout<<"---+---+---"<<endl;
            }
        }
        if (winner()==1)
            return;
    }
    return;
}

int main(){
    srand (time(NULL));
    cin>>o>>p;
    ttt();
    return 0;
}
