#include<iostream>
#include<fstream>
using namespace std;

void text_to_file(char array4[100] , char filename[100]){

    ofstream file(filename);
    cout<<"ENTER A STRING: ";
    cin.getline(array4,100);
    file<<array4;
    
}

int main (){
    char array4[100];
    char filename[100] = "save_text";

    text_to_file(array4 , filename);

    return 0;
}