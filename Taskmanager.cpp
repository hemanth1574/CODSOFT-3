#include <iostream>
#include <string>
using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool isCompleted;
};

Task taskList[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!\n";
        return;
    }

    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, taskList[taskCount].description);
    taskList[taskCount].isCompleted = false;
    taskCount++;

    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "\n--- TASK LIST ---\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". [" << (taskList[i].isCompleted ? "X" : " ") << "] "
             << taskList[i].description << endl;
    }
}

void markTaskCompleted() {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }

    taskList[index - 1].isCompleted = true;
    cout << "Task marked as completed.\n";
}

void deleteTask() {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }

    for (int i = index - 1; i < taskCount - 1; i++) {
        taskList[i] = taskList[i + 1];
    }
    taskCount--;

    cout << "Task deleted.\n";
}

void menu() {
    cout << "\n--- TO-DO LIST MENU ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
