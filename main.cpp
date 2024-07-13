#include "main.h"

// Misc Functions are written here
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto isLeapYear = [](int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    };
    int days1 = day1;
    for (int i = 1; i < month1; ++i) {
        days1 += daysInMonth[i];
        if (i == 2 && isLeapYear(year1)) 
            ++days1;
    }
    days1 += year1 * 365 + (year1 - 1) / 4 - (year1 - 1) / 100 + (year1 - 1) / 400;

    int days2 = day2;
    for (int i = 1; i < month2; ++i) {
        days2 += daysInMonth[i];
        if (i == 2 && isLeapYear(year2)) 
            ++days2;
    }
    days2 += year2 * 365 + (year2 - 1) / 4 - (year2 - 1) / 100 + (year2 - 1) / 400;
    return (days2 - days1);
}

void Login(){
    cout << "\n";
    cout << "Login In as: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. Customer" << endl;
    cout << green << arrows << reset;
    cout << "2. Employee" << endl;
    cout << green << arrows << reset;
    cout << "3. Manager" << endl;
    cout << green << arrows << reset;
    cout << red << "4. Exit" << reset << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\n";
        cout << red << "Invalid Data. Try Again!" << reset << endl;
        cout << "\n";
        Login();
    } else {
        if(input == 4){
            cout << "Thanks for using our Service!" << endl;
            exit(0);
        }
        if(input == 1){
            Customer_login();
        }
        if(input == 2){
            Employee_login();
        }
        if(input == 3){
            Manager_login();
        }
    }
}

void Program() {
    cout << green << arrows << reset;
    cout << "1. Login as a User" << endl;
    cout << green << arrows << reset;
    cout << "2. Register as a new Customer" << endl;
    cout << green << arrows << reset;
    cout <<  red << "3. Exit" << reset << endl;
    cout << "\n";
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;
    
    if (cin.fail() || (input != 1 && input != 2 && input != 3)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "\n";
        cout << red << "Invalid Data. Try Again!" << reset << endl;
        cout << "\n";
        Program();
    } else {
        if(input == 3){
            cout << endl;
            cout <<  green << "Thanks for using our Service!" << reset << endl;
            exit(0);
        }
        if(input == 2){
            cout << "\n";
            string name, password;
            cout << blue << "[INPUT] " << reset;
            cout << "Enter Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline(cin, name);
            cout << blue << "[INPUT] " << reset;
            cout << "Enter Password: ";
            cin >> password;

            Customer new_user(name, password);
            Customer_Database customerQuery(new_user);
            customerQuery.Add();
            cout << "\n";
            cout << "Login to continue..." << endl;
            Program();
        }
        if(input == 1){
            Login();
        }
    }
}

int main(){
       std::string welcomeString = R"(
###################################
||                               ||
||          WELCOME              ||
||                               ||
###################################
    )";

    std::cout << white << welcomeString << reset << std::endl;

    Program();
    return 0;
}
