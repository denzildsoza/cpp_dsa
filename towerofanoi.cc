#include<bits/stdc++.h>

using namespace std;

void tower_of_anoi(int n,char from,char to, char aux){
    if(n==0){
        return;
    }
    tower_of_anoi(n-1,from,aux,to);
    cout<<"Moving "<<n<<" rod "<<from<<" Moving to rod "<<to<<endl;
    tower_of_anoi(n-1,aux,to,from);
}

int main(){
    int n = 3;
    tower_of_anoi(n,'A','C','B');
    return 0;
}