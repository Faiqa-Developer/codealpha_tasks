// CodeAlpha_Project_To Do List Application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>
#include<ctime>
using namespace :: std;

class ToDoItem {
private:
    int id;
    string description;
    bool completed;
public:
    ToDoItem() : id(0), description(""), completed(false) {}
    ~ToDoItem() = default;

    int getId() { return id; }
    string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) {
        completed = val;
    }
    bool create(string new_description) {
        id = rand() % 100+1;
        description = new_description;
        return true;
    }
};
int main()
{
    string in_description;
    int in_id;
    char choice;
    string version = "v0.2.0";
    list <ToDoItem> todoitems;
    list <ToDoItem> ::iterator it;
    todoitems.clear();
    
    while (1) {
        system("cls");
        cout << "ToDo List Maker " << version << endl;
        cout << endl << endl;

        for (it = todoitems.begin(); it != todoitems.end(); it++) {
            string completed = it->isCompleted() ? "completed" : "pending";
            cout << it->getId() << " | " << it->getDescription() << " | " << completed << endl;
        }
        if (todoitems.empty()) {
            cout << "Add your first ToDo!" << endl;
        }
        cout << endl<<endl;
        cout << "[A]dd a new ToDo" << endl;
        cout << "[C]omplete a ToDo" << endl;
        cout << "[Q]uit" << endl;

        cout << "choice:";
        cin >> choice;

        if (choice == 'Q') {
            cout << "Have a good day!" << endl;
            break;
        }
        else if (choice == 'A') {
            cout << "Describe your ToDo:";
            cin.clear();
            cin.ignore();
            getline(cin , in_description);

            ToDoItem newtodo;
            newtodo.create(in_description);
            todoitems.push_back(newtodo);

        }
        else if (choice=='C') {
            cout << "Enter the id of the ToDo you have completed:";
            cin >> in_id;

            for (it = todoitems.begin(); it != todoitems.end(); it++) {
                if (in_id == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
