#include <iostream>
using namespace std;

void printing(int array1[5]){
    cout<<"ARRAY IS: ";
    for(int i=0 ; i<5 ; i++){
        cout<<array1[i]<<" ";
    }
}

int main(){

    int array1[5];
    for(int i=0 ; i<5 ; i++){
        cout<<"ENTER "<<i+1<<" NUMBER OS ELEMENT: ";
        cin>>array1[i];
    }

    //calling
    printing(array1);

    return 0;
}