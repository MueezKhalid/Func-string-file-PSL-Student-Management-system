#include<iostream>
#include<fstream>
using namespace std;

void print_charac(char array5[100]){

    cout<<"SPLITIING STRING IN TO A SINGLE CHARACTER"<<endl;
    for(int i=0 ; array5[i]!='\0' ; i++){
        if(array5[i]!=' '){
            cout<<array5[i]<<endl;
        }
    }
    
}

int main (){

    char array5[100];
    cout<<"ENTER A STRING: ";
    cin.getline(array5 , 100);

    print_charac(array5);

    return 0;
}