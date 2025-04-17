#include<iostream>
#include<fstream>
using namespace std;

void record(string filename){

    ofstream enter_data(filename , ios::app);
    if(!enter_data.is_open()){
        cout<<"ERROR!"<<endl;
    }

    string name , team_name , role;
    int total_runs , total_wickets;

    bool flag1=true , flag2=true , flag3=true , flag4=true , flag5 = true;
    
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
            enter_data<<name<<" ";
        }
    }while(flag1==false);

    do{
        if(flag2!=true){
            cout<<endl<<"YOU CAN NOT ENTER SPACES IN TEAM NAME"<<endl<<endl;
        }
        flag2=true;
        cout<<"PLEASE ENTER THE PLAYER TEAM NAME: ";
        getline(cin , team_name);
        for(int i = 0 ; team_name[i]!='\0' ; i++){
            if(team_name[i]==' '){
                flag2 = false;
                break;
            }
        }
        if(flag2==true){
            enter_data<<team_name<<" ";
        }
    }while(flag2==false);

    
    do{
        if(flag3!=true){
            cout<<endl<<"YOU CAN NOT ENTER SPACES IN ROLE"<<endl<<endl;
        }
        flag3=true;
        cout<<"PLEASE ENTER THE ROLE EITHER BATSMAN OR BOWLER: ";
        getline(cin , role);
        for(int i = 0 ; role[i]!='\0' ; i++){
            if(role[i]==' '){
                flag3 = false;
                break;
            }
        }
        if(flag3==true){
            enter_data<<role<<" ";
        }
    }while(flag3==false);

    do{
        if(flag4!=true){
            cout<<endl<<"RUNS CAN NOT BE NEGATIVE"<<endl<<endl;
        }
        flag4=true;
        cout<<"ENTER TOTAL RUNS: ";
        cin>>total_runs;
        if(total_runs<0){
            flag4=false;
        }
        if(flag4==true){
            enter_data<<total_runs<<" ";    
        }
    }while(flag4==false);

    do{
        if(flag5!=true){
            cout<<endl<<"WICKETS CAN NOT BE NEGATIVE"<<endl<<endl;
        }
        flag5=true;
        cout<<"ENTER TOTAL WICKETS: ";
        cin>>total_wickets;
        if(total_wickets<0){
            flag5=false;
        }
        if(flag5==true){
            enter_data<<total_wickets<<" ";    
        }
    }while(flag5==false);
    enter_data<<endl;
}

void display(string filename){
    ifstream disapling(filename);
    if(!disapling.is_open()){
        cout<<"ERROR"<<endl;
    }

    string name,team_name,role;
    int total_runs , total_wickets;

    cout<<"NAME           TEAM NAME           ROLE           TOTAL RUNS            TOTAL WICKETS"<<endl;
    while(disapling>> name >> team_name >> role >> total_runs >> total_wickets){
        cout<<name<<"                 "<<team_name<<"            "<<role<<"               "<<total_runs<<"           "<<total_wickets;
        cout<<endl;
    }
    disapling.close();
}

void search(string filename){
    ifstream search(filename);
    string search_by_name;
    cout<<"ENTER THE PLAYER NAME: ";
    cin>>search_by_name;

    bool flag = false;
    string name,team_name,role;
    int total_runs , total_wickets;
    while(search >> name >> team_name >> role >> total_runs >> total_wickets){
        if(search_by_name == name){
            cout<<"SEARCHED PLAYER DATA IS"<<endl;
            cout<<"NAME           TEAM NAME           ROLE           TOTAL RUNS           TOTAL WICKETS"<<endl;
            cout<<name<<"                 "<<team_name<<"            "<<role<<"               "<<total_runs<<"           "<<total_wickets<<endl;
            flag = true;
        }
    }
    if(flag==false){
        cout<<"STUDENT NOT FOUND"<<endl;
    }
    search.close();
}

void update_status(string filename , string temporary){
    ifstream search(filename);
    ofstream update(temporary,ios::app);
    string search_by_name;

    cout<<"ENTER PLAYER NAME: ";
    cin>>search_by_name;
    cin.ignore();

    string name,team_name,role;
    int total_runs , total_wickets;

    while(search >> name >> team_name >> role >> total_runs >> total_wickets){
        if(search_by_name == name){       
            bool flag2=true , flag3=true;
            do{
                if(flag2!=true){
                    cout<<endl<<"YOU CAN NOT ENTER SPACES IN TEAM NAME"<<endl<<endl;
                }
                flag2=true;
                cout<<"PLEASE ENTER THE TEAM NAME: ";
                getline(cin , team_name);
                for(int i = 0 ; team_name[i]!='\0' ; i++){
                    if(team_name[i]==' '){
                        flag2 = false;
                        break;
                    }
                }
            }while(flag2==false);
           
            do{
                if(flag3!=true){
                    cout<<endl<<"YOU CAN NOT ENTER SPACES IN ROLE"<<endl<<endl;
                }
                flag3=true;
                cout<<"PLEASE ENTER THE ROLE EITHER BATSMAN OR BOWLER: ";
                getline(cin , role);
                for(int i = 0 ; role[i]!='\0' ; i++){
                    if(role[i]==' '){
                        flag3 = false;
                        break;
                    }
                }
            }while(flag3==false);

            do{
                if(total_runs<0){
                    cout<<endl<<"TOTAL RUNS CGPA CAN NOT BE NEGATIVE"<<endl<<endl;
                }
                cout<<"UPDATE TOTAL_RUNS: ";
                cin>>total_runs;
                cin.ignore();
            }while(total_runs<0);
            
            do{
                if(total_wickets<0){
                    cout<<endl<<"TOTAL WICKETS CGPA CAN NOT BE NEGATIVE"<<endl<<endl;
                }
                cout<<"UPDATE TOTAL_WICKETS: ";
                cin>>total_wickets;
                cin.ignore();
            }while(total_wickets<0);
            update<<name<<" "<<team_name<<" "<<role<<" "<<total_runs<<" "<<total_wickets<<" "<<endl;
        }
        else{
            update<<name<<" "<<team_name<<" "<<role<<" "<<total_runs<<" "<<total_wickets<<" "<<endl;
        }
    }
    search.close();
    update.close();
}

void deleting(string filename , string temporary2){
    ifstream search(filename);
    ofstream deleteing(temporary2,ios::app);
    string search_by_name;

    cout<<"ENTER PLAYER NAME TO DELETE PLAYER DATA: ";
    cin>>search_by_name;
    cin.ignore();
    
    string name,team_name,role;
    int totla_runs , total_wickets;

    while(search >> name >> team_name >> role >> totla_runs >> total_wickets){
        if(search_by_name == name){       
            continue;
        }
        else{
            
            deleteing<<name<<" "<<team_name<<" "<<role<<" "<<totla_runs<<" "<<total_wickets<<" "<<endl;
        }
    }
    search.close();
    deleteing.close();
}
int main (){

    int choose;
    do{
        string filename ="psl.txt";
        string temporary ="psl_temp.txt";
        string temporary2 ="psl_temp2.txt";

        cout<<"*********************** MENU ***********************"<<endl;
        cout<<"1. ENTER PSL DATA"<<endl;
        cout<<"2. DISPLAY ALL PSL DATA"<<endl;
        cout<<"3. SEARCH PLAYER DATA BY NAME"<<endl;
        cout<<"4. UPDATE PLAYER STATUS"<<endl;
        cout<<"5. DELETE PLAYER STATUS"<<endl;
        cout<<"6. EXITE"<<endl;
        
        cout<<endl<<"CHOOSE FROM MENU: ";
        cin>>choose;
        cin.ignore();

        if(choose==1){
            record(filename);
        }
        else if(choose==2){
            display(filename);
        }
        else if (choose==3){
            search(filename);
        }
        else if(choose==4){
            update_status(filename , temporary);
            remove("psl.txt");
            rename("psl_temp.txt" , "psl.txt");
        }
        else if(choose==5){
            deleting(filename , temporary2);
            remove("psl.txt");
            rename("psl_temp2.txt" , "psl.txt");
        }
        else if (choose ==6){
            cout<<"PROGRAM EXITE!"<<endl;
            break;
        }
        else{
            cout<<"INVALID INPUT";
        }
    }while(choose!=6);

    return 0;
}