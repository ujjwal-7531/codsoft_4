// //Task 4
// //TO-DO LIST
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//1. Add Task
void addTask(vector<vector<string>>&table){
    string task;
    cin.ignore();
    cout<<"Enter Task: ";
    getline(cin,task);
    table.push_back({task,"pending"});
}
//2. Remove Task.
void removeTask(vector<vector<string>>&table){
    if(table.size()==1){
        cout<<"No task to remove."<<endl;
        return;
    }
    int id;
    cout<<"Task id: ";
    cin>>id;
    table.erase(table.begin()+id);
}
//3. View All-Task.
void viewAll(vector<vector<string>>table){
    if(table.size()==1){
        cout<<"Nothing to do."<<endl;
        return;
    }
    cout<<"Task id      Task                Status"<<endl;
    for(int i=1;i<table.size();++i)
    cout<<i<<"            "<<table[i][0]<<"             "<<table[i][1]<<endl;
}
//4. View Tasks by status.
void viewTask(vector<vector<string>>&table){
    if(table.size()==1){
        cout<<"Nothing to do."<<endl;
        return;
    }
    string status;
    cout<<"Task Status: ";
    cin>>status;
    cout<<"Task id      Task                Status"<<endl;
    for(int id=1;id<table.size();++id)
    if(table[id][1]==status)
    cout<<id<<"            "<<table[id][0]<<"             "<<table[id][1]<<endl;
}
//5. Update Task.
void update(vector<vector<string>>&table){
    if(table.size()==1){
        cout<<"No task to update."<<endl;
        return;
    }
    int id;
    cout<<"Task-id: ";
    cin>>id;
    if(table[id][1]=="pending")
        table[id][1]="completed";
    else table[id][1]=="pending";
}
int main(){
    vector<vector<string>>table;//(100,vector<string>(3));
    table.push_back({"Task","Status"});
    int option=-1;
    cout<<"____To-Do List____\n\n....Options....\n1.Add Task.\n2.Remove Task.\n3.View All-Task.\n4.View Tasks by status.\n5.Update Task.\n6.Exit"<<endl;
    while(option!=6){
        cout<<"\nEnter Option: ";
        cin>>option;
        switch(option){
            case 1:
                addTask(table);
                break;
            case 2:
               removeTask(table);
               break;
            case 3:
                viewAll(table);
                break;
            case 4:
                viewTask(table);
                break;
            case 5:
                update(table);
                break;
            case 6:
                option=6;
                break;
        }
    }
    return 0;
}