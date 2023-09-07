#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Simple Calculator" << endl;

    // Input the two numbers and the operation from the user
    cout << "Enter first number : ";
    cin >> num1;

    cout << "Enter second number : ";
    cin >> num2;

    cout << "Select operation (+, -, *, /) : ";
    cin >> operation;

    // Perform the selected operation and display the result
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation." << endl;
    }

    return 0;
}
