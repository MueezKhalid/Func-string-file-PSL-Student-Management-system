#include<iostream>
using namespace std;

int sum(int array2[5]){
    int array_element_sum = 0;
    for(int i=0 ; i<5 ; i++){
        array_element_sum+=array2[i];
    }
    return array_element_sum;
}

int main (){

    int array2[5] , array_sum;
    for(int i=0 ; i<5 ; i++){
        cout<<"ENTER "<<i+1<<" NUMBER OS ELEMENT: ";
        cin>>array2[i];
    }

    array_sum = sum(array2);
    cout<<"THE SUM OF ALL ARRAY ELEMENT IS: "<<array_sum;

    return 0;
}