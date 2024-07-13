#include "main.h"

// Functions for class Manager
void Manager::AddCustomer(){
    string name;
    string password;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;
    
    Customer NewUser(name, password);
    Customer_Database CustomerQuery(NewUser);
    CustomerQuery.Add();
}

void Manager::DeleteCustomer(){
    string name;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << endl;

    Customer NewUser(name, "Unknown");
    Customer_Database CustomerQuery(NewUser);
    CustomerQuery.DeleteByName();

    cout << green << "Customer deleted Successfully" << reset << endl;
}

void Manager::UpdateCustomer(int id, string new_name, string new_password){
    Customer CurrentUser(id);
    Customer_Database CustomerQuery(CurrentUser);
    CustomerQuery.UpdateById(new_name, new_password);
}

void Manager::SearchCustomer(){
    string name;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << endl;

    Customer NewUser(name, "Unknown");
    Customer_Database CustomerQuery(NewUser);
    CustomerQuery.displayByName();
}

void Manager::ViewAllCustomers(){
    Customer_Database CustomerQuery;
    CustomerQuery.displayAll();
}

void Manager::AddEmployee(){
    string name;
    string password;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;

    Employee NewUser(name, password);
    Employee_Database EmployeeQuery(NewUser);
    EmployeeQuery.Add();
}

void Manager::DeleteEmployee(){
    string name;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << endl;

    Employee NewUser(name, "Unknown");
    Employee_Database EmployeeQuery(NewUser);
    EmployeeQuery.DeleteByName();

    cout << green << "Employee deleted Successfully" << reset << endl;
}

void Manager::UpdateEmployee(int id, string new_name, string new_password){
    Employee CurrentUser(id);
    Employee_Database EmployeeQuery(CurrentUser);
    EmployeeQuery.UpdateById(new_name, new_password);
}

void Manager::SearchEmployee(){
    string name;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << endl;

    Employee NewUser(name, "Unknown");
    Employee_Database EmployeeQuery(NewUser);
    EmployeeQuery.displayByName();
}

void Manager::ViewAllEmployees(){
    Employee_Database EmployeeQuery;
    EmployeeQuery.displayAll();
}

void Manager::AddCar(){
    Car_Structure NewCar;
    string brand;
    string model;
    int cost;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Brand: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, brand);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Model: ";
    getline(cin, model);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Cost: ";
    cin >> cost;
    cout << endl;

    NewCar.brand = brand;
    NewCar.model = model;
    NewCar.cost = cost;
    NewCar.condition = 5;

    Car_Database CarQuery;
    CarQuery.Add(NewCar);
}

void Manager::DeleteCar(){
    string brand;
    string model;
    int cost;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Brand: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, brand);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Model: ";
    getline(cin, model);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Cost: ";
    cin >> cost;
    cout << endl;

    Car NowCar(brand, model, cost);
    Car_Database CarQuery(NowCar);
    Car_Structure temp;
    CarQuery.Delete(temp);
}

void Manager::UpdateCar(){
    string brand;
    string model;
    int cost, condition;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Brand: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, brand);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Model: ";
    getline(cin, model);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Cost(Press 0 to keep it unchanged): ";
    cin >> cost;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Condition(Press 0 to keep it unchanged): ";
    cin >> condition;
    cout << endl;

    Car_Database CarQuery;
    CarQuery.UpdateCostCondition(brand, model, cost, condition);
}

void Manager::SearchCar(){
    string brand;
    string model;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Brand: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, brand);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Model: ";
    getline(cin, model);
    cout << endl;

    Car_Database CarQuery;
    CarQuery.displayByInfo(brand, model);
}

void Manager::ViewAllAvailableCars(){
    Car_Database CarQuery;
    CarQuery.displayAvailableCars();
}

void Manager::ViewAllRentedCars(){
    Rent_Database RentQuery;
    RentQuery.displayAllInfo();
}

void Manager::UpdateRecord(){
    Record_Structure RecordInfo;
    int in, id;
    cout << endl;
    cout << "Enter the details of the record" << endl;
    cout << endl;
    cout << "Choose the User: " << endl;
    cout << green << arrows << reset;
    cout << "1. Customer" << endl;
    cout << green << arrows << reset;
    cout << "2. Employee" << endl;
    cout << "Enter Input: ";
    cin >> in;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter ID:";
    cin >> id;
    cout << endl;
    string type;
    if(in == 1){
        type = "customer";
    } else {
        type = "employee";
    }
    Record_Database RecordQuery;
    RecordQuery.getRecordInfo(id, type);
    string brand;
    string model;
    int new_return_condition;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Brand: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, brand);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Model: ";
    getline(cin, model);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter New Return Condition(Press 0 to keep it unchanged): ";
    cin >> new_return_condition;
    cout << endl;
    int new_return_day, new_return_month, new_return_year;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter New Return Day(Press 0 to keep it unchanged): ";
    cin >> new_return_day;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter New Return Month(Press 0 to keep it unchanged): ";
    cin >> new_return_month;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter New Return Year(Press 0 to keep it unchanged): ";
    cin >> new_return_year;

    RecordInfo.id = id;
    RecordInfo.type = type;
    RecordInfo.brand = brand;
    RecordInfo.model = model;
    RecordInfo.cost = 0;
    RecordInfo.rent_condition = 0;
    RecordInfo.return_condition = new_return_condition;
    RecordInfo.return_day = new_return_day;
    RecordInfo.return_month = new_return_month;
    RecordInfo.return_year = new_return_year;

    RecordQuery.UpdateRecord(RecordInfo);
}

void Manager::SearchRecord(){
    int in, id;
    cout << endl;
    cout << "Enter the details of the record" << endl;
    cout << endl;
    cout << "Choose the User: " << endl;
    cout << green << arrows << reset;
    cout << "1. Customer" << endl;
    cout << green << arrows << reset;
    cout << "2. Employee" << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Input: ";
    cin >> in;
    cout << blue << "[INPUT] " << reset;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter ID:";
    cin >> id;
    cout << endl;

    string type;
    if(in == 1){
        type = "customer";
    } else {
        type = "employee";
    }

    Record_Database RecordQuery;
    RecordQuery.getRecordInfo(id, type);
}

void Manager::ViewAllRecords(){
    Record_Database RecordQuery;
    RecordQuery.getAllRecords();
}


// Inner Login Functions

void Modify_Customer(){
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. Add Customer " << endl;
    cout << green << arrows << reset;
    cout << "2. Update Customer" << endl;
    cout << green << arrows << reset;
    cout << "3. Delete Customer" << endl;
    cout << green << arrows << reset;
    cout << "4. Search Customer" << endl;
    cout << green << arrows << reset;
    cout << "5. View all Customers" << endl;
    cout << green << arrows << reset;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if(cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << red << "Invalid Data, Try Again!" << reset << endl;
        cout << "\n";
        Manager_login_request(false);
    } else {
        Manager manager;

        if(input == 1){
            manager.AddCustomer();
            cout << endl;
            cout << green << "Customer Added Successfully" << reset << endl;
            Manager_login_request(false);
        }

        if(input == 2){
            manager.ViewAllCustomers();
            int id;
            string new_name, new_password;
            cout << endl;
            cout << blue << "[INPUT] " << reset;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << blue << "[INPUT] " << reset;
            cout << "Enter New Name(Press 0 to Keep Unchanged): ";
            getline(cin, new_name);
            cout << blue << "[INPUT] " << reset;
            cout << "Enter New Password(Press 0 to Keep Unchanged): ";
            getline(cin, new_password);

            // Update Customer
            manager.UpdateCustomer(id, new_name, new_password);
            cout << green << "Details Changed..." << reset << endl;
            Manager_login_request(false);
        }

        if(input == 3){
            manager.DeleteCustomer();
            Manager_login_request(false);
        }

        if(input == 4){
            manager.SearchCustomer();
            Manager_login_request(false);
        }

        if(input == 5){
            manager.ViewAllCustomers();
            Manager_login_request(false);
        }

        if(input == 6){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}

void Modify_Employee(){
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. Add Employee " << endl;
    cout << green << arrows << reset;
    cout << "2. Update Employee" << endl;
    cout << green << arrows << reset;
    cout << "3. Delete Employee" << endl;
    cout << green << arrows << reset;
    cout << "4. Search Employee" << endl;
    cout << green << arrows << reset;
    cout << "5. View all Employees" << endl;
    cout << green << arrows << reset;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if(cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << red << "Invalid Data, Try Again!" << reset << endl;
        cout << "\n";
        Manager_login_request(false);
    } else {   
        Manager manager;

        if(input == 1){
            manager.AddEmployee();
            cout << endl;
            cout << green << "Employee Added Successfully" << reset << endl;
            Manager_login_request(false);
        }

        if(input == 2){
            manager.ViewAllEmployees();
            int id;
            string new_name, new_password;
            cout << endl;
            cout << blue << "[INPUT] " << reset;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << blue << "[INPUT] " << reset;
            cout << "Enter New Name(Press 0 to Keep Unchanged): ";
            getline(cin, new_name);
            cout << blue << "[INPUT] " << reset;
            cout << "Enter New Password(Press 0 to Keep Unchanged): ";
            getline(cin, new_password);

            // Update Customer
            manager.UpdateEmployee(id, new_name, new_password);
            cout << green << "Details Changed..." << reset << endl;
            Manager_login_request(false);
        }   

        if(input == 3){
            manager.DeleteEmployee();
            Manager_login_request(false);
        }

        if(input == 4){
            manager.SearchEmployee();
            Manager_login_request(false);  
        }

        if(input == 5){
            manager.ViewAllEmployees();
            Manager_login_request(false);
        }

        if(input == 6){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}

void Modify_Cars(){
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. Add Car " << endl;
    cout << green << arrows << reset;
    cout << "2. Update Car" << endl;
    cout << green << arrows << reset;
    cout << "3. Delete Car" << endl;
    cout << green << arrows << reset;
    cout << "4. Search Car" << endl;
    cout << green << arrows << reset;
    cout << "5. View all available Cars" << endl;
    cout << green << arrows << reset;
    cout << "6. View all rented Cars" << endl;
    cout << green << arrows << reset;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if(cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6 && input != 7)){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout <<  red << "Invalid Data, Try Again!" << reset << endl;
        cout << "\n";
        Manager_login_request(false);
    } else {
        Manager manager;

        if(input == 1){
            manager.AddCar();
            cout << green << "Car Added Successfully..."<< reset << endl;
            Manager_login_request(false);
        }

        if(input == 2){
            manager.ViewAllAvailableCars();
            manager.UpdateCar();
            cout << green << "Updated Succesfully" << reset << endl;
            Manager_login_request(false);
        }

        if(input == 3){
            manager.DeleteCar();
            cout << green << "Deleted Successfully"<< reset << endl;
            Manager_login_request(false);
        }

        if(input == 4){
            manager.SearchCar();
            Manager_login_request(false);            
        }

        if(input == 5){
            manager.ViewAllAvailableCars();
            Manager_login_request(false);
        }

        if(input == 6){
            manager.ViewAllRentedCars();
            Manager_login_request(false);
        }

        if(input == 7){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}

void Modify_Records(){
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. View all Records " << endl;
    cout << green << arrows << reset;
    cout << "2. Update Records" << endl;
    cout << green << arrows << reset;
    cout << "3. Search Record" << endl;
    cout << green << arrows << reset;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if(cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 )){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Invalid Data, Try Again!" << endl;
        cout << "\n";
        Manager_login_request(false);
    } else {
        Manager manager;

        if(input == 1){
            manager.ViewAllRecords();
            Manager_login_request(false);
        }

        if(input == 2){
            manager.UpdateRecord();
            cout << green << "Updated Successfully" << reset << endl;
            Manager_login_request(false);
        }

        if(input == 3){
            manager.SearchRecord();
            Manager_login_request(false);
        }

        if(input == 4){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}

// Manager Login Functions
void Manager_login(){
    string name;
    string password;
    cout << endl;
    cout << "Login Details" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, name);
    cout << blue << "[INPUT] " << reset;
    cout << "Enter Password: ";
    cin >> password;
    cout << endl;

    // As per the question only one Manager account is made
    ifstream file("database/manager_database");
    string admin_name, admin_password;
    getline(file, admin_name);
    getline(file, admin_password);

    if(name == admin_name && password == admin_password){
        Manager_login_request(true);
    } else{
        cout << red << "Access Denied!" << reset << endl;
        Login();
    }
}

void Manager_login_request(bool display){
    if(display){
        cout << endl;
        cout << "Hi, Admin" << endl;
    }
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. View and Modify Customers" << endl;
    cout << green << arrows << reset;
    cout << "2. View and Modify Employees" << endl;
    cout << green << arrows << reset;
    cout << "3. View and Modify Cars" << endl;
    cout << green << arrows << reset;
    cout << "4. View and Modify Records" << endl;
    cout << green << arrows << reset;
    cout << "5. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;
    
    if(cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 && input != 5)){
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << red << "Invalid Data, Try Again!" << reset << endl;
        cout << "\n";
        Manager_login_request(false);
    } else {
        if(input == 1){
            Modify_Customer();
        }
        if(input == 2){
            Modify_Employee();
        }
        if(input == 3){
            Modify_Cars();
        }
        if(input == 4){
            Modify_Records();
        }   
        if(input == 5){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}
