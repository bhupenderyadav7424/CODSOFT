#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(const string& desc)
    {
        description = desc;
        completed = false;
    }
};

class ToDoList
{
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc)
    {
        tasks.push_back(Task(desc));
        cout << "Task added : " << desc << endl;
    }

    void viewTasks()
    {
        cout << "Tasks :" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            tasks[index].completed = true;
            cout << "Task marked as completed : " << tasks[index].description << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(int index)
    {
        if (index >= 0 && index < tasks.size())
        {
            cout << "Task removed : " << tasks[index].description << endl;
            tasks.erase(tasks.begin() + index);
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }
};

int main()
{
    ToDoList toDoList;
    int choice;

    while (true)
    {
        cout << "To-Do List Manager!!!" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1 :
        {
            string taskDescription;
            cout << "Enter task description : ";
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, taskDescription);
            toDoList.addTask(taskDescription);
            break;
        }

        case 2 :
        {
            toDoList.viewTasks();
            break;
        }

        case 3 :
        {
            int index;
            toDoList.viewTasks();
            cout << "Enter the index of the task to mark as completed : ";
            cin >> index;
            toDoList.markTaskAsCompleted(index - 1);
            break;
        }

        case 4 :
        {
            int index;
            toDoList.viewTasks();
            cout << "Enter the index of the task to remove : ";
            cin >> index;
            toDoList.removeTask(index - 1);
            break;
        }

        case 5 :
        {
            cout << "Exit." << endl;
            break;
        }

        default :
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }

        if (choice == 5)
        {
            break;
        }
    }

    return 0;
}
