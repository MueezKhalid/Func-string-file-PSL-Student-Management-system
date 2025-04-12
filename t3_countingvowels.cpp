#include<iostream>
using namespace std;

int vowels(char array3[100]){
    int counted_vowels = 0;
    for(int i=0 ; array3[i]!='\0' ; i++){
        
        if(array3[i]=='a' || array3[i]=='e' || array3[i]=='i' || array3[i]=='o' || array3[i]=='u' || array3[i]=='A' || array3[i]=='E' || array3[i]=='I' || array3[i]=='O' || array3[i]=='U'){
            counted_vowels++;   
        }
    }
    return counted_vowels;
}

int main (){

    char array3[100];
    int counted_vowels;

    cout<<"ENTER A STRING: ";
    cin.getline(array3,100);

    counted_vowels = vowels(array3);
    cout<<"THE SUM OF ALL ARRAY ELEMENT IS: "<<counted_vowels;

    return 0;
}