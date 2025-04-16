#include<iostream>
#include<fstream>
using namespace std;

void input_data(string filename){

    ofstream file(filename , ios::app);
    ifstream repeatition(filename);

    if(!file.is_open() || !repeatition.is_open()){
        cout<<"ERROR!"<<endl;
    }

    string name,rollnumber,department;
    float cgpa;
    bool flag1=true , flag2=true , flag3=true , flag4=true , repeat = false;
    
    do{
        if(flag1!=true){
            cout<<endl<<"YOU CAN NOT ENTER SPACES IN NAME"<<endl<<endl;
        }
        flag1=true;
        cout<<"PLEASE ENTER THE NAME: ";
        getline(cin , name);
        for(int i = 0 ; name[i]!='\0' ; i++){
            if(name[i]==' '){
                flag1 = false;
                break;
            }
        }
        if(flag1==true){
            file<<name<<" ";
        }
    }while(flag1==false);

    do{
        if(flag2!=true || repeat!=false){
            cout<<endl<<"YOU CAN NOT ENTER SPACES OR REPEATED ROLLNUMBER"<<endl<<endl;
        }
        repeat = false;
        flag2=true;
        cout<<"PLEASE ENTER ROLLNUMBER: ";
        getline(cin , rollnumber);
        for(int i = 0 ; rollnumber[i]!='\0' ; i++){
            if(rollnumber[i]==' '){
                flag2 = false;
            }
        }
        
        repeatition.clear();
        repeatition.seekg(0,ios::beg);

        string check_rollnumber;
        while(repeatition >> name >> check_rollnumber >> department >> cgpa){
            if(check_rollnumber==rollnumber){
                repeat = true;
            }
        }
        if(flag2==true && repeat == false){
            file<<rollnumber<<" ";
        }
    }while(flag2==false || repeat==true);

    do{
        if(flag3!=true){
            cout<<endl<<"YOU CAN NOT ENTER SPACES IN DEPARTMENT"<<endl<<endl;
        }
        flag3=true;
        cout<<"PLEASE ENTER THE DEPARTMENT: ";
        getline(cin , department);
        for(int i = 0 ; department[i]!='\0' ; i++){
            if(department[i]==' '){
                flag3 = false;
            }
        }
        if(flag3==true){
            file<<department<<" ";
        }
    }while(flag3==false);

    do{
        if(flag4!=true){
            cout<<endl<<"CGPA CAN NOT BE NEGATIVE OR GREATER THAN 4"<<endl<<endl;
        }
        flag4=true;
        cout<<"ENTER CGPA: ";
        cin>>cgpa;
        if(cgpa<0 || cgpa>4){
            flag4=false;
        }
        if(flag4==true){
            file<<cgpa<<" "<<endl;    
        }
    }while(flag4==false);
    file.close();
    repeatition.close();
}

void display_data(string filename){
    ifstream read(filename);
    if(!read.is_open()){
        cout<<"ERROR"<<endl;
    }

    string name,rollnumber,department;
    float cgpa;
    cout<<"STUDENT NAME           ROLLNUMBER           DEPARTMENT           CGPA"<<endl;
    while(read >> name >> rollnumber >> department >> cgpa){
        cout<<name<<"                 "<<rollnumber<<"            "<<department<<"               "<<cgpa<<"           ";
        cout<<endl;
    }
    read.close();
}

void searching(string filename){
    
    ifstream search(filename);
    string search_rollnumber;
    cout<<"ENTER THE ROLLNUMBER: ";
    cin>>search_rollnumber;

    bool flag = false;
    string name,rollnumber,department;
    float cgpa;
    while(search >> name >> rollnumber >> department >> cgpa){
        if(search_rollnumber == rollnumber){
            cout<<"SEARCHED STUDENT DATA IS"<<endl;
            cout<<"STUDENT NAME           ROLLNUMBER           DEPARTMENT           CGPA"<<endl;
            cout<<name<<"                 "<<rollnumber<<"            "<<department<<"               "<<cgpa<<"           "<<endl;
            flag = true;
        }
    }
    if(flag==false){
        cout<<"STUDENT NOT FOUND"<<endl;
    }
    search.close();
}

void update_gpa(string filename , string temporary){
    
    ifstream search(filename);
    ofstream update(temporary,ios::app);
    string search_by_rollnumber;

    cout<<"ENTER ROLLNUMBER TO UPDATE CGPA: ";
    cin>>search_by_rollnumber;

    string name,rollnumber,department;
    float cgpa;

    while(search >> name >> rollnumber >> department >> cgpa){
        if(search_by_rollnumber == rollnumber){       
            do{
                if(cgpa>4 || cgpa<0){
                    cout<<endl<<"STUDENT CGPA CAN NOT BE NEGATIVE OR GREATER THAN 4"<<endl<<endl;
                }
                cout<<"UPDATE CGPA: ";
                cin>>cgpa;
            }while(cgpa>4 || cgpa<0);
            
            update<<name<<" "<<rollnumber<<" "<<department<<" "<<cgpa<<" "<<endl;
        }
        else{
            
            update<<name<<" "<<rollnumber<<" "<<department<<" "<<cgpa<<" "<<endl;
        }
    }
    search.close();
    update.close();
    
} 

void delete_record(string filename , string temporary2){
    
    ifstream search(filename);
    ofstream deleteing(temporary2,ios::app);
    string search_by_rollnumber;

    cout<<"ENTER ROLLNUMBER TO DELETE STUDENT DATA: ";
    cin>>search_by_rollnumber;

    string name,rollnumber,department;
    float cgpa;

    while(search >> name >> rollnumber >> department >> cgpa){
        if(search_by_rollnumber == rollnumber){       
            continue;
        }
        else{
            
            deleteing<<name<<" "<<rollnumber<<" "<<department<<" "<<cgpa<<" "<<endl;
        }
    }
    search.close();
    deleteing.close();
    
}
int main (){
    
    int choose;
    do{

        cout<<endl<<"**************************MENU**************************"<<endl<<endl;
        cout<<"1. INPUT DATA"<<endl;
        cout<<"2. DISPLAYING DATA"<<endl;
        cout<<"3. SEARCHING STUDENT RECORD"<<endl;
        cout<<"4. UPDATE CGPA"<<endl;
        cout<<"5. DELETING RECORD"<<endl;
        cout<<"6. EXITE"<<endl;

        cout<<endl<<"CHOOSE FROM MENU: ";
        cin>>choose;
        cin.ignore();

        string filename= "student.txt";
        string temporary="temp.txt";
        string temporary2="temp2.txt";

        if(choose==1){
            input_data(filename);
        }
        else if(choose==2){
            display_data(filename);
        }
        else if(choose==3){
            searching(filename);
        }
        else if(choose==4){
            update_gpa(filename , temporary);
            remove("student.txt");
            rename("temp.txt" , "student.txt");
        }
        else if(choose==5){
            delete_record(filename , temporary2);
            remove("student.txt");
            rename("temp2.txt" , "student.txt");
        }
        else if(choose==6){
            cout<<"PROGRAM HAS BEEN EXITE"<<endl;
            break;
        }
        else{
            cout<<"INVALID INPUT"<<endl;
        }
    }while(choose!=6);    
    return 0;
}