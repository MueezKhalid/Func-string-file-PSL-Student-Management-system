#include<iostream>
using namespace std;

void palindrome(char array9[100] , char reversed_array9[100]){

    bool flag=true;
    int last_index;
    for(last_index=0 ; array9[last_index] != '\0' ; last_index++);
    last_index-=1;
    
    for(int i=0 ; array9[i]!='\0' ; i++ , last_index--){

        reversed_array9[last_index] = array9[i];

    }
    for(int i=0 ; array9[i]!='\0' ; i++){

        if(array9[i] != reversed_array9[i]){
            flag=false;
            break;
        }

    }
    if(flag==true){
        cout<<"ENTERED STRING IS PALINDROME"<<endl;
    }
    else{
        cout<<"ENTERED STRING IS NPT A PALINDROME"<<endl;
    }
}

int main (){

    char array9[100];
    char reversed_array9[100];
    cout<<"ENTER A STRING: ";
    cin.getline(array9,100);

    palindrome(array9 , reversed_array9);

    return 0;
}