// #include<iostream>
// using namespace std;
// string tasks[10];
// int count=0;
// void Add_Task(){
// string task;
// cout<<"Enter the name of the task\n";
// getline(cin,task);
// cin.ignore();
// if(true){
//     count++;
//     tasks[count]=task;
// }
// cout<<"Task is added successfully\n";


// }
// void View_Tasks(){
// cout<<"\t\t\t\t***TASKS\n";
// for(int i=0; i<=count; i++){
//     if(tasks[i]!="0"){
//     cout<<"Task1 No:"<<i<<endl;
//     cout<<"Task Name:"<<tasks[i]<<endl;
//     }
// }
// }
// void Mark_Complete(){
//     int index;
//     cout<<"Enter the task number which you want to mark as completed:";
//     cin>>index;
//     if(index<=count){
//     tasks[index]="0";
// cout<<"Task is marked as completed\n";
//     }else{
//         cout<<"This task does not exists\n";
//     }
// }
// void Remove_Task(){
//     int index;
//     cout<<"Enter the task number which you want to remove:";
//     cin>>index;
//     tasks[index]="0";
// cout<<"Task is removed successfully\n";
// }
// int main(){
// char choice;
// cout<<"\t\t\t***TO-DO-LIST-MANAGER\n";
// cout<<"Enter 1 to add task\n";
// cout<<"Enter 2 to view tasks\n";
// cout<<"Enter 3 to mark taskas completed\n";
// cout<<"Enter 4 to remove task\n";
// cout<<"Enter 5 to exit the program\n";
// bool LoopControl=true;
// while (LoopControl)
// {
// cout<<"Enter your choice:";
// cin.ignore();
// cin>>choice;
//     switch (choice)
//     {
//     case '1':
//     Add_Task();
//         break;
//     case '2':
//     View_Tasks();
//         break;
//     case '3':
//     Mark_Complete();
//         break;
//     case '4':
//     Remove_Task();
//         break;
//     case '5':
//     cout<<"Program is exiting\n";
//     LoopControl=false;
//         break;
//     default:
//         cout << "Invalid Choice!!!Please Enter your choice again\n";
//         break;
//     }
// }
//     return 0;
// }



#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void addTask(const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
    std::cout << "Task added successfully!" << std::endl;
}

void viewTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
    } else {
        std::cout << "Tasks:" << std::endl;
        for (const auto& task : tasks) {
            std::string status = task.completed ? "[x]" : "[ ]";
            std::cout << status << " " << task.description << std::endl;
        }
    }
}

void markTaskAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    int choice;
    std::string description;
    int index;

    while (true) {
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                std::cout << "Enter task index: ";
                std::cin >> index;
                markTaskAsCompleted(index);
                break;
            case 4:
                std::cout << "Enter task index: ";
                std::cin >> index;
                removeTask(index);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }

        std::cout << std::endl;
    }
}