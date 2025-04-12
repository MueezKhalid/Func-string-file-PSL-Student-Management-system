#include<iostream>
using namespace std;

void reversing(int array7[5]){
    cout<<endl<<"REVERSED ARRAY IS"<<endl;
    for(int i=4 ; i>=0 ; i--){
        cout<<array7[i]<<" ";
    }
    
}

int main(){

    int array7[5];
    for(int i=0 ; i<5 ; i++){
        cout<<"ENTER "<<i+1<<" NUMBER: ";
        cin>>array7[i];
    }
    reversing(array7);
    return 0;
}