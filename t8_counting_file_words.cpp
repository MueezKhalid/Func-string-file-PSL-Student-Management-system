#include<iostream>
#include<fstream>
using namespace std;

int counting(char filename[100]){

    int count_words = 0;
    ifstream file(filename);
    char single_word[100];

    if(!file.is_open()){
        cout<<"ERROR!";
        return 1;
    }
    while(file>>single_word){
        count_words++;
    }

    return count_words;
}

int main (){

    char filename[100]="counting_file_words.txt";
    cout<<"TOTAL WORDS IN THE FILE IS: "<<counting(filename)<<endl;



    return 0;
}