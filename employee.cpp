#include "main.h"

// Misc Functions 
int getCount_Employee(){
    std::ifstream file_in("database/employee_count");
    string s;
    std::getline(file_in, s);
    file_in.close();

    int count = stoi(s);
    std::ofstream file_out("database/employee_count");
    file_out << (count + 1) << endl;
    file_out.close();

    return count;
}

// Functions for class Employee
void Employee::ClearDue(int amount){
    this->due =  -1 * amount; 
    // Should immediately class UpdateDue in class Employee_Database
}

void Employee::getRentedCars(bool& anyRentedCars){
    Rent_Database RentQuery;
    bool anyCars = RentQuery.getCarInfo(this->id, "employee");
    anyRentedCars = anyCars;
}   

int Employee::countRentedCars(){
    Rent_Database RentQuery;
    return RentQuery.countRentedCars(this->id, "employee");
}

void Employee::getRecords(){
    Record_Database RecordQuery;
    RecordQuery.getRecordInfo(this->id, "employee");
}

void Employee::returnRequest(){
    int returnId = this->id;
    string returnType = "employee";
    string brand, model, str_date;
    int rent_condition, now_condition, cost;
    cout << "Car Details: " << endl;
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
    cout << blue << "[INPUT] " << reset;
    cout << "Enter condition when rented: ";
    cin >> rent_condition;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter condition now: ";
    cin >> now_condition;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter return data(DD/MM/YYYY, 0 for today): ";
    cin >> str_date;

    int return_date, return_month, return_year;

    if(str_date == "0"){
        system_clock::time_point now = system_clock::now();
        time_t now_time = system_clock::to_time_t(now);
        tm* local_time = localtime(&now_time);
        return_date = local_time->tm_mday;
        return_month = local_time->tm_mon + 1;
        return_year = local_time->tm_year + 1900;
    } else {
        size_t pos1 = str_date.find('/');
        size_t pos2 = str_date.find('/', pos1 + 1);

        string dayStr = str_date.substr(0, pos1);
        string monthStr = str_date.substr(pos1 + 1, pos2 - pos1 - 1);
        string yearStr = str_date.substr(pos2 + 1);

        return_date = stoi(dayStr);
        return_month = stoi(monthStr);
        return_year = stoi(yearStr);
    }

    Car_Structure AddCar;
    Record_Structure AddRecord;
    AddRecord.id = returnId;
    AddRecord.type = returnType;
    AddRecord.brand = brand;
    AddRecord.model = model;
    AddRecord.cost = cost;

    Rent_Database RentQuery;
    RentQuery.DeleteCar(AddRecord);

    AddCar.brand = brand;
    AddCar.model = model;
    AddCar.cost = cost;
    AddCar.condition = now_condition;

    AddRecord.return_condition = now_condition;
    AddRecord.return_day = return_date;
    AddRecord.return_month = return_month;
    AddRecord.return_year = return_year;

    Car_Database CarQuery;
    Record_Database RecordQuery;
    CarQuery.Add(AddCar);
    RecordQuery.Add(AddRecord);

    bool late = false;
    if(return_year > AddRecord.due_year){
        late = true;
    }
    if(return_month > AddRecord.due_month && return_year == AddRecord.due_year){
        late = true;
    }
    if(return_date > AddRecord.due_day && return_month == AddRecord.due_month && return_year == AddRecord.due_year){
        late = true;
    }

    if(now_condition < rent_condition && late){
        int damage_fee = (int)(rent_condition - now_condition) * 0.2 * cost * 0.85;
        int late_days = daysBetweenDates(AddRecord.due_day, AddRecord.due_month, AddRecord.due_year, return_date, return_month, return_year);
        int late_fee = late_days * 0.008 * cost * 0.85;
        cout << endl;
        cout << green << arrows << reset;
        cout << "Employee Discount: 15%" << endl;
        cout << red <<"Damage Fee: " << damage_fee << reset << endl;
        cout << red << "Late Fee: " << late_fee << reset << endl;
        Employee NowEmployee(this->name, this->password);
        Employee_Database UserQuery(NowEmployee);
        UserQuery.ClearDue(-1 * (damage_fee + late_fee));
        UserQuery.UpdateDue();
    }

    if(now_condition < rent_condition && !late){
        int extra_fee = (int)(rent_condition - now_condition) * 0.2 * cost;
        cout << endl;
        cout << red << "Damage Fee: " << extra_fee << reset << endl;
        Employee NowEmployee(this->name, this->password);
        Employee_Database UserQuery(NowEmployee);
        UserQuery.ClearDue(-1 * extra_fee);
        UserQuery.UpdateDue();
    }

}

// Functions for class Employee_Database
void Employee_Database::displayAll(){
    this->readInput();

    cout << endl;
    for(auto x: this->Employee_data){
        cout << green << arrows << reset;
        cout << "Employee ID: " << x.id << endl;
        cout << green << arrows << reset;
        cout << "Employee Name: " << x.name << endl;
        cout << green << arrows << reset;
        cout << "Employee Password: " << x.password << endl;
        cout << green << arrows << reset;
        cout << "Employee Due: " << x.due << endl;
        cout << endl;
    }
}

void Employee_Database::displayByName(){
    this->readInput();

    cout << endl;
    for(auto x: this->Employee_data){
        if(x.name == this->name){
            cout << green << arrows << reset;
            cout << "Employee ID: " << x.id << endl;
            cout << green << arrows << reset;
            cout << "Employee Name: " << x.name << endl;
            cout << green << arrows << reset;
            cout << "Employee Password: " << x.password << endl;
            cout << green << arrows << reset;
            cout << "Employee Due: " << x.due << endl;
            cout << endl;
        }
    }
}

void Employee_Database::Add(){
    this->readInput();
    Employee_Structure new_user;

    new_user.id = getCount_Employee();
    new_user.name = this->name;
    new_user.password = this->password;
    new_user.due = 0;

    this->Employee_data.push_back(new_user);
    this->writeData();
}

bool Employee_Database::Authenticate(Employee_Structure& now){
    this->readInput();

    for(auto x: this->Employee_data){
        if(x.name == this->name && x.password == this->password){
            now.id = x.id;
            now.name = x.name;
            now.password = x.password;
            now.due = x.due;
            return true;
        }
    }
    return false;
}

void Employee_Database::UpdateById(string new_name, string new_password){
    this->readInput();

    for(auto& x: this->Employee_data){
        if(x.id == this->id){
            if(new_name != "0"){
                x.name = new_name;
            }
            if(new_password != "0"){
                x.password = new_password;
            }
        }
    }

    this->writeData();
}

void Employee_Database::UpdateDue(){
    this->readInput();
    for(auto& x: this->Employee_data){
        if(x.name == this->name && x.password == this->password){
            x.due = x.due + this->due;
            cout << green << arrows << reset;
            cout << "Current Due: " << x.due << endl;
        }
    }
    this->writeData();
}

void Employee_Database::DeleteByName(){
    this->readInput();

    for(auto it = this->Employee_data.begin(); it != this->Employee_data.end();) {
        auto& x = *it;
        if(x.name == this->name){
            it = this->Employee_data.erase(it); 
        } else{
            ++it;
        }
    }
    this->writeData();
}

void Employee_Database::readInput(){
    ifstream file("database/employee_database");
    string id, name, password, gap, due;
    while(getline(file, id)){
        int int_id = stoi(id);
        getline(file, name);
        getline(file, password);
        getline(file, due);
        getline(file, gap);
        int int_due = stoi(due);
        Employee_Structure UserNow;
        UserNow.id = int_id;
        UserNow.name = name;
        UserNow.password = password;
        UserNow.due = int_due;
        Employee_data.push_back(UserNow);
    }
    file.close();
}

void Employee_Database::writeData(){
    ofstream file("database/employee_database");
    for(auto x : Employee_data){
        file << x.id << endl;
        file << x.name << endl;
        file << x.password << endl;
        file << x.due << endl;
        file << endl;
    }
    file.close();
}

// Functions for Login 
void Employee_login(){
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

    Employee LoginUser(name, password);
    Employee_Database EmployeeQuery(LoginUser);

    Employee_Structure CurrentEmployee;
    bool check = EmployeeQuery.Authenticate(CurrentEmployee);


    if(check){
        cout << green << "Login Successful!" << reset << endl;
        cout << endl;
        Employee_login_request(CurrentEmployee, true);
    } else {
        cout << red << "Access Denied!" << reset << endl;
        Login();
    }
}

void Employee_login_request(Employee_Structure CurrentUser, bool display){
    if(display){
        cout << "Hi, " << CurrentUser.name << endl;
    }
    cout << endl;
    cout << "Actions: " << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "1. Rent a car" << endl;
    cout << green << arrows << reset;
    cout << "2. Clear due" << endl;
    cout << green << arrows << reset;
    cout << "3. View record" << endl;
    cout << green << arrows << reset;
    cout << "4. View Rented Cars" << endl;
    cout << green << arrows << reset;
    cout << "5. Return Car" << endl;
    cout << green << arrows << reset;
    cout << "6. Exit" << endl;
    cout << endl;
    cout << blue << "[INPUT] " << reset;
    cout << "Enter: ";
    int input;
    cin >> input;

    if (cin.fail() || (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << red << "Invalid Data, Try Again!" << reset << endl;
        cout << "\n";
        Employee_login_request(CurrentUser, false);
    } else {
        if(input == 1){
            Car_Database CarQuery;
            bool checkAvailability = CarQuery.displayAvailableCars();

            if(!checkAvailability){
                Employee_login_request(CurrentUser, false);
            } else {
                Employee NowUser(CurrentUser.id);
                int count = NowUser.countRentedCars();

                if(CurrentUser.due > 50000){
                    cout << red << "No cars will be allowed to rent before clearing dues..." << reset << endl;
                } else if(count >= 5){
                    cout << red << "Max Limit Reached" << reset << endl;
                } else {
                Car_Structure DeletedCar;
                string brand, model;
                int cost, days;
                cout << "Enter the details of the car: " << "\n\n";
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
                cout << blue << "[INPUT] " << reset;
                cout << "Number of Days: ";
                cin >> days;

                Car RequestedCar(brand, model, cost);
                RequestedCar.carRentRequest(CurrentUser.id, "employee");

                Car_Database CarQueryAgain(RequestedCar);
                CarQueryAgain.Delete(DeletedCar);

                system_clock::time_point now = system_clock::now();
                time_t now_time = system_clock::to_time_t(now);
                tm* local_time = localtime(&now_time);
                int rent_day = local_time->tm_mday;
                int rent_month = local_time->tm_mon + 1;
                int rent_year = local_time->tm_year + 1900;

                auto thirty_days = duration<int, ratio<60 * 60 * 24>>(days);
                system_clock::time_point after_30_days = now +thirty_days;
                time_t after_30_days_time = system_clock::to_time_t(after_30_days);
                tm* after_30_days_local_time = localtime(&after_30_days_time);
                int due_day = after_30_days_local_time->tm_mday;
                int due_month = after_30_days_local_time->tm_mon + 1;
                int due_year = after_30_days_local_time->tm_year + 1900;

                Rent_Structure NewRentedCar;
                NewRentedCar.id = CurrentUser.id;
                NewRentedCar.type = "employee";
                NewRentedCar.brand = DeletedCar.brand;
                NewRentedCar.model = DeletedCar.model;
                NewRentedCar.cost = DeletedCar.cost;
                NewRentedCar.condition = DeletedCar.condition;
                NewRentedCar.rent_day = rent_day;
                NewRentedCar.rent_month = rent_month;
                NewRentedCar.rent_year = rent_year;
                NewRentedCar.due_day = due_day;
                NewRentedCar.due_month = due_month;
                NewRentedCar.due_year = due_year;

                Rent_Database RentQuery;
                RentQuery.AddRentedCar(NewRentedCar);
                
                cout << green << arrows << reset;
                cout << "Cost of Renting: 0.5% of the cost of car per day" << endl;
                cout << green << arrows << reset;
                cout << "Employee Discount: 15%" << endl;
                int extra_fee = (int)(0.005 * days * cost * 0.85);
                cout << green << arrows << reset;
                cout << "Rent Fee: " << extra_fee << endl;
                Employee NowEmployee(CurrentUser.name, CurrentUser.password);
                Employee_Database UserQuery(NowEmployee);
                UserQuery.ClearDue(-1 * extra_fee);
                UserQuery.UpdateDue();
                }
                Employee_login_request(CurrentUser, false);
            }
        }
        
         if(input == 2){
            cout << endl;
            cout << green << arrows << reset;
            cout << "Due: " << CurrentUser.due<< endl;
            cout << blue << "[INPUT] " << reset;
            cout << "Enter amount: ";
            int amount;
            cin >> amount;

            if(amount > CurrentUser.due || amount < 0){
                cout << endl;
                cout << red << "Invalid Amount!, Try Again!" << reset << endl;
            } else {
                Employee NowEmployee(CurrentUser.name, CurrentUser.password);
                Employee_Database UserQuery(NowEmployee);
                UserQuery.ClearDue(amount);
                UserQuery.UpdateDue();
            }
            Employee_login_request(CurrentUser, false);
        }

        if(input == 3){
            Employee NowUser(CurrentUser.id);
            NowUser.getRecords();
            Employee_login_request(CurrentUser, false);
        }

        if(input == 4){
            bool anyRentedCars;
            Employee NowUser(CurrentUser.id);
            NowUser.getRentedCars(anyRentedCars);
            Employee_login_request(CurrentUser, false);

            int count = NowUser.countRentedCars();
            cout << "\n" << green << "Number of Cars Rented: " << count << reset << "\n" << endl;
        }

        if(input == 5){
            bool anyRentedCars;
            Employee NowUser(CurrentUser.id, CurrentUser.name, CurrentUser.password);
            NowUser.getRentedCars(anyRentedCars);

            if(anyRentedCars){
                NowUser.returnRequest();
            }
            Employee_login_request(CurrentUser, false);
        }

        if(input == 6){
            cout << endl;
            cout << green << "Thanks for using our service!" << reset << endl;
            exit(0);
        }
    }
}