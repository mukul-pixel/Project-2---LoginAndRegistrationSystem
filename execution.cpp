#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;

void mainmenu();

bool isloggedin(string username,string password){
    string user,pass;
     ifstream read(username+".txt");
       getline(read,user);
       getline(read,pass);

       if(user==username && pass==password){
        return true;
       }else{
        return false;
       }
}
void login(){
       string username,password,user,pass;

       cout<<"Enter Your Username: ";cin>>username;
       cout<<"Enter your Password: ";cin>>password;

       bool status=isloggedin(username,password);
       

       if(status){
        cout<<"Successfully Logged In  : ) "<<endl;
       }else{
        cout<<"Invalid Username or Password. Please Retry !!"<<endl;
       }
}

void writetofile(string username,string password){

    ofstream file;
    file.open(username+".txt");
    file<<username<<endl<<password;
    file.close();

}

void registerme(){
    string username,password,password2;
    cout<<"Select a Username: ";cin>>username;
    cout<<"Enter a Password: ";cin>>password;
    cout<<"Please Re-Enter Your Password: ";cin>>password2;
    writetofile(username,password);

    if(password==password2){
          cout<<"You have been registered successfully!"<<endl; 
          system("PAUSE");
          mainmenu(); 
    }else{
        cout<<"Invalid Password, Please try again !"<<endl;
        mainmenu();
    }

   
   
}

void Exit(){
    exit(0);
}
void mainmenu(){
    cout<<"WELCOME!, What would you like to choose? \n 1.Register \n 2.Login \n 3.Exit\n";
    int choice;cin>>choice;

    switch(choice){
        case 1 : 
        registerme();
        break;

        case 2 :
        login();
        break;

        case 3 :
        Exit();
        break;
    }
}
int main(){ 
mainmenu(); 
}
