#include<iostream>
using namespace std;

int maximum_number(int array6[5]){
    int max_num = -9999;
    for(int i=0 ; i<5 ; i++){
        if(max_num<array6[i]){
            max_num=array6[i];
        }
    }
    return max_num;
}

int main(){

    int array6[5];
    for(int i=0 ; i<5 ; i++){
        cout<<"ENTER "<<i+1<<" NUMBER: ";
        cin>>array6[i];
    }
    cout<<"MAXIMUM NUMBER IS: "<<maximum_number(array6)<<endl;
    return 0;
}