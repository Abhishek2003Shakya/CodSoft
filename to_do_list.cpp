#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool done;
};

void showMenu() {
    cout<<"\n=======================|| To-do List Menu ||======================="<<endl;
    cout<<"1. Add Task"<<endl;
    cout<<"2. View Tasks"<<endl;
    cout<<"3. Mark Task as Done"<<endl;
    cout<<"4. Remove Task"<<endl; // Option to remove a task
    cout<<"5. Quit"<<endl;
}

void addTask(vector<Task>& tasks) {
    Task task;
    cout<<"Enter a task: ";
    cin.ignore(); // Clear input buffer
    getline(cin, task.description);
    task.done = false;
    tasks.push_back(task);
    cout<<"Task added!"<<endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout<<"\nCurrent Tasks:"<<endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        const std::string status = tasks[i].done ? "Done" : "Not Done";
        cout<<i + 1<<". "<<tasks[i].description<<" - "<<status<<endl;
    }
}

void markTaskDone(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t taskIdx;
    cout<<"Enter the task number to mark as done: ";
    cin>>taskIdx;

    if (taskIdx >= 1 && taskIdx <= tasks.size()) {
        tasks[taskIdx - 1].done = true;
        cout<<"Task marked as done!"<<endl;
    } else {
        cout<<"Invalid task number."<<endl;
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t taskIdx;
    cout<<"Enter the task number to remove: ";
    cin>>taskIdx;

    if (taskIdx >= 1 && taskIdx <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIdx - 1); // Remove the selected task
        cout<<"Task removed!"<<endl;
    } else {
        cout<<"Invalid task number."<<endl;
    }
}

int main() {
    vector<Task> tasks;
    while (true) {
        showMenu();
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskDone(tasks);
                break;
            case 4:
                removeTask(tasks); // Call the removeTask function
                break;
            case 5:
                cout<<"Goodbye!"<<endl;
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}
