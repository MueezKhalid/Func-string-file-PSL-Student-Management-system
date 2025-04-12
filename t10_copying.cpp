#include<iostream>
using namespace std;

void copying(int array10[10] , int copying_array10[10]){

    for(int i=0 ; i<10 ; i++){
        copying_array10[i] = array10[i];
    }

    cout<<"PRINTING COPYIED ARRAY"<<endl;

    for(int i=0 ; i<10 ; i++){
        cout<<copying_array10[i]<<" ";
    }
}
int main(){

    int array10[10] , copying_array10[10];
    for(int i=0 ; i<10 ; i++){
        cout<<"ENETER "<<i+1<<" NUMBER: ";
        cin>>array10[i];
    }
    copying(array10 , copying_array10);

    return 0;
}