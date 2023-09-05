#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    system ("cls");
    cout<<"=========================|| Simple Calculator ||========================="<<endl;

    cout<<"Enter first number: ";
    if (!(cin >> num1)) {
        cout<<"Invalid input for the first number."<<endl;
        return 1;
    }

    cout<<"Enter operation (+, -, *, /): ";
    cin>>operation;

    cout << "Enter second number: ";
    if (!(cin >> num2)) {
        cout<<"Invalid input for the second number."<<endl;
        return 1;
    }

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout<<"Error: Division by zero is not allowed."<<endl;
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            cout<<"Invalid operation. Please use +, -, *, or /."<<endl;
            return 1;
    }

    cout<<"Result: "<<result<<endl;

    return 0;
}
