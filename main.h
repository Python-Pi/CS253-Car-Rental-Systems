#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class User{
protected:
    string name;
    string password;
public:
    User(){};
    User(const std::string& n, const std::string& p) : name(n), password(p) {}
    ~User(){};
};

class Customer: public User{
protected:
    int id;
    int due;
public:
    Customer(){};
    Customer(const int i) : id(i){};
    Customer(const std::string& n, const std::string& p) 
        : User(n, p){};
    Customer(const int i, const std::string& n, const std::string& p) 
        : User(n, p), id(i){};
    void ClearDue(int amount);
    void getRentedCars(bool& anyRentedCars);
    int countRentedCars();
    void getRecords();
    void returnRequest();
    ~Customer(){};
};

struct Customer_Structure{
    int id;
    string name;
    string password;
    int due;
};

class Customer_Database: public Customer{
    vector<Customer_Structure> customer_data;
public:
    Customer_Database(){};
    Customer_Database(const Customer &obj) : Customer(obj) {};
    void Add();
    bool Authenticate(Customer_Structure& now);
    void DeleteByName();
    void UpdateById(string new_name, string new_password);
    void displayAll();
    void displayByName();
    void UpdateDue();
    void readInput();
    void writeData();
    ~Customer_Database(){};
};

class Employee: public User{
protected:
    int id;
    int due;
public:
    Employee(){};
    Employee(const int i) : id(i){};
    Employee(const std::string& n, const std::string& p) 
        : User(n, p){};
    Employee(const int i, const std::string& n, const std::string& p) 
        : User(n, p), id(i){};
    void ClearDue(int amount);
    void getRentedCars(bool& anyRentedCars);
    int countRentedCars();
    void getRecords();
    void returnRequest();
    ~Employee(){};
};

struct Employee_Structure{
    int id;
    string name;
    string password;
    int due;
};

class Employee_Database: public Employee{
    vector<Employee_Structure> Employee_data;
public:
    Employee_Database(){};
    Employee_Database(const Employee &obj) : Employee(obj) {};
    void Add();
    bool Authenticate(Employee_Structure& now);
    void DeleteByName();
    void UpdateById(string new_name, string new_password);
    void displayAll();
    void displayByName();
    void UpdateDue();
    void readInput();
    void writeData();
    ~Employee_Database(){};
};

class Manager: public User{
public:
    void AddCustomer();
    void DeleteCustomer();
    void UpdateCustomer(int id, string new_name, string new_password);
    void SearchCustomer();
    void ViewAllCustomers();
    
    void AddEmployee();
    void DeleteEmployee();
    void UpdateEmployee(int id, string new_name, string new_password);
    void SearchEmployee();
    void ViewAllEmployees();

    void AddCar();
    void DeleteCar();
    void UpdateCar();
    void SearchCar();
    void ViewAllAvailableCars();
    void ViewAllRentedCars();

    void UpdateRecord();
    void SearchRecord();
    void ViewAllRecords();
    ~Manager(){};
};  

class Car{
protected:
    string brand;
    string model;
    int condition;
    int cost;
public:
    Car(){};
    Car(string b, string m, int c) : brand(b), model(m), cost(c){};
    void carRentRequest(int id, string type);
    ~Car(){};
};

struct Car_Structure{
    string brand;
    string model;
    int cost;
    int condition;
};

class Car_Database: public Car{
    vector<Car_Structure> car_data;
public:
    Car_Database(){};
    Car_Database(const Car &obj) : Car(obj){};
    void Add(Car_Structure& AddCar);
    void Delete(Car_Structure& DeletedCar);
    void UpdateCostCondition(string brand, string model, int cost, int condition);
    bool displayAvailableCars();
    void displayByInfo(string brand, string model);
    void readInput();
    void writeInput();
    ~Car_Database(){};
};

struct Rent_Structure{
    int id;
    string type;
    string brand;
    string model;
    int cost;
    int condition;

    int rent_day;
    int rent_month;
    int rent_year;

    int due_day;
    int due_month;
    int due_year;
};

struct Record_Structure{
    int id;
    string type;
    string brand;
    string model;
    int cost;

    int rent_condition;
    int return_condition;

    int rent_day;
    int rent_month;
    int rent_year;

    int due_day;
    int due_month;
    int due_year;

    int return_day;
    int return_month;
    int return_year;
};

class Rent_Database{
    vector<Rent_Structure> rent_data;
public:
    void AddRentedCar(Rent_Structure NewRentedCar);
    void DeleteCar(Record_Structure& AddRecord);
    bool getCarInfo(int id, string type);
    int countRentedCars(int id, string type);
    void displayAllInfo();
    void readInput();
    void writeInput();
    ~Rent_Database(){};
};

class Record_Database{
    vector<Record_Structure> record_data;
public:
    void Add(Record_Structure AddRecord);
    void getRecordInfo(int id, string type);
    void getAllRecords();
    void UpdateRecord(Record_Structure& RecordInfo);
    void readInput();
    void writeInput();
    ~Record_Database(){};
};

// Functions in main.cpp
void Login();
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2);

// Functions in customer.cpp
void Customer_login();
void Customer_login_request(Customer_Structure CurrentUser, bool display);

// Functions in employee.cpp
void Employee_login();
void Employee_login_request(Employee_Structure CurrentUser, bool display);

// Functions in manager.cpp
void Manager_login();
void Manager_login_request(bool display);
void Modify_Customer();
void Modify_Employee();
void Modify_Cars();
void Modify_Records();

// Colors and modifiers
    
const std::string red = "\033[1;31m";
const std::string green = "\033[1;32m";
const std::string yellow = "\033[1;33m";
const std::string blue = "\033[1;34m";
const std::string magenta = "\033[1;35m";
const std::string cyan = "\033[1;36m";
const std::string white = "\033[1;37m";
const std::string reset = "\033[0m";
const string arrows = ">> ";