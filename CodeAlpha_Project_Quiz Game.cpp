// CodeAlpha_Project_Quiz Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int Q_No = 1, correct = 0, wrong = 0;
bool ask[10] = ( true, true, true, true, true, true, true, true, true, true);
void display_random_question();
void display();
void question(string question, string a, string b, string c, string d, char correct);
void result();

int main()
{
    display();
    return 0;
}

void display(){
    system("cls");
    cout << "Question No:" << Q_No << "\t\tCorrect Answers:" << correct << "\t\t Wrong Answers:" << wrong << endl << endl;
    display_random_question();
}

void display_random_question() {
    srand(time(0));
    bool is_question_remaining = false;
    for (int i = 0; i < 10; i++) {
        if (ask[i]) {
            is_question_remaining = true;
            break;
        }
    }
    while (is_question_remaining) {
        int no = rand() % 10;
        if (ask[no]) {
            ask[no] = false;
            switch (no){
            case 0:
                question("1. Which oop concept allows code reuse?", "inheritance", "abstraction", "polymorphism", "generalization", "a");
                break;
            case 1:
                question("2. Which oop concept allows hiding internal details of function?", "inheritance", "abstraction", "polymorphism", "generalization", "b");
                break;
            case 2:
                question("3. Which oop concept refers to the ability of different objects to respond to the same message in different ways?", "inheritance", "abstraction", "polymorphism", "generalization", "c");
                break;
            case 3:
                question("4. Which oop concept allows class inheritance from another class?", "inheritance", "abstraction", "polymorphism", "generalization", "a");
                break;
            case 4:
                question("5. what is an object in oop?", "class", "unit", "base", "instance","d");
                break;
            case 5:
                question("6. what is a class in oop?", "blueprint", "unit", "base", "instance", "a");
           
            break; 
            case 6:
                question("7. What is it called when an object takes many forms?", "inheritance", "abstraction", "polymorphism", "generalization", "c");
                break;
            case 7:
                question("8. What allows the function to have different implementations in a base and derived class", "inheritance", "abstraction", "overriding", "generalization", "c");
                break;
            case 8:
                question("9. Which is not the oop concept?", "inheritance", "compilation", "polymorphism", "generalization", "b");
                break;
            case 9:
                question("10. Which oop concept involves using a class or function that works with any data type?", "templates", "abstraction", "polymorphism", "generalization", "a");
                break;
            }
        }
    }
    result();
}
void result() {
    system("cls");
    cout << "Total Questions = " << Q_No - 1 << endl;
    cout << "Correct Answers = " << correct  << endl;
    cout << "Wrong Answers = " << wrong << endl;
    if (correct > wrong)
        cout << "Result = Pass" << endl;
    else if (correct < wrong)
        cout << "Result = Fail" << endl;
    else
        cout << "Result = Tie" << endl;
 }

void question(string question, string a, string b, string c, string d, char corect_answer) {
    cout << question << endl;
    cout << "A.\t" << a << endl;
    cout << "B.\t" << b << endl;
    cout << "C.\t" << c << endl;
    cout << "D.\t" << d << endl;
    char answer;
    if (answer == correct_answer)
        correct++;
    else
        wrong++;
    Q_No++;
    display();
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
