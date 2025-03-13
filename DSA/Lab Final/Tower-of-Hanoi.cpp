#include<bits/stdc++.h>
using namespace std;
int x = 1;
void towerofhanoi(int N,char source,char target,char aux){
    x++;
    if(N==0){
        return;
    }
    towerofhanoi(N-1,source, aux, target);
    cout<<"Move disk "<<N<<" from "<<source<< " to "<<target<<endl;
    towerofhanoi(N-1, aux, target, source);
}

int main(){
    int n;
    cin>>n;
    towerofhanoi(n,'A','C','B');
    cout<<"Total function call "<<x<<endl;
    return 0;
}
