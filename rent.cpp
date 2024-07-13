#include "main.h"

// Functions for the class Rent_Database
bool Rent_Database::getCarInfo(int id, string type){
    this->readInput();

    int count = 0;
    cout << endl;
    for(auto x: this->rent_data){
        if(x.id == id && x.type == type){
            cout << green << arrows << reset;
            cout << "Rent Date: " << x.rent_day << "/" << x.rent_month << "/" << x.rent_year << endl;
            cout << green << arrows << reset;
            cout << "Due Date: " << x.due_day << "/" << x.due_month << "/" << x.due_year << endl;
            cout << green << arrows << reset;
            cout << "Brand: " << x.brand << endl;
            cout << green << arrows << reset;
            cout << "Model: " << x.model << endl;
            cout << green << arrows << reset;
            cout << "Cost: " << x.cost << endl;
            cout << green << arrows << reset;
            cout << "Condition of the car when rented: " << x.condition << endl;
            cout << endl;

            count++;
        }
    }

    if(count == 0){
        cout << red << "No rented Cars found..." << reset << endl;
        return false;
    }
    return true;
}

int Rent_Database::countRentedCars(int id, string type){
    this->readInput();
    int count = 0;
    for(auto x: this->rent_data){
        if(x.id == id && x.type == type){
            count++;
        }
    }
    return count;
}

void Rent_Database::displayAllInfo(){
    this->readInput();
    for(auto x: this->rent_data){
        cout << green << arrows << reset;
        cout << "Rent Date: " << x.rent_day << "/" << x.rent_month << "/" << x.rent_year << endl;
        cout << green << arrows << reset;
        cout << "Due Date: " << x.due_day << "/" << x.due_month << "/" << x.due_year << endl;
        cout << green << arrows << reset;
        cout << "Brand: " << x.brand << endl;
        cout << green << arrows << reset;
        cout << "Model: " << x.model << endl;
        cout << green << arrows << reset;
        cout << "Cost: " << x.cost << endl;
        cout << green << arrows << reset;
        cout << "Condition of the car when rented: " << x.condition << endl;
        cout << endl;
    }
}

void Rent_Database::AddRentedCar(Rent_Structure NewRentedCar){
    this->readInput();
    this->rent_data.push_back(NewRentedCar);
    cout << endl;
    cout << green << arrows << reset;
    cout << "Rent Date: " << NewRentedCar.rent_day << "/" << NewRentedCar.rent_month << "/" << NewRentedCar.rent_year << endl;
    cout << green << arrows << reset;
    cout << "Due Date: " << NewRentedCar.due_day << "/" << NewRentedCar.due_month << "/" << NewRentedCar.due_year << endl;
    cout << green << arrows << reset;
    cout << "Brand: " << NewRentedCar.brand << endl;
    cout << green << arrows << reset;
    cout << "Model: " << NewRentedCar.model << endl;
    cout << green << arrows << reset;
    cout << "Cost: " << NewRentedCar.cost << endl;
    cout << green << arrows << reset;
    cout << "Condition of the car when rented: " << NewRentedCar.condition << endl;
    cout << endl;
    cout << green << arrows << reset;
    cout << "Car Rented Succesfully..." << endl;
    this->writeInput();
}

void Rent_Database::DeleteCar(Record_Structure& AddRecord){
    this->readInput();

    for(auto it = this->rent_data.begin(); it != this->rent_data.end();) {
        auto& x = *it;
        if(x.id == AddRecord.id && x.type == AddRecord.type && x.brand == AddRecord.brand && x.model == AddRecord.model && x.cost == AddRecord.cost){
            AddRecord.rent_condition = x.condition;
            AddRecord.rent_day = x.rent_day;
            AddRecord.rent_month = x.rent_month;
            AddRecord.rent_year = x.rent_year;
            AddRecord.due_day = x.due_day;
            AddRecord.due_month = x.due_month;
            AddRecord.due_year = x.due_year;
            it = this->rent_data.erase(it); 
        } else{
            ++it;
        }
    }

    this->writeInput();
}

void Rent_Database::readInput() {
    ifstream file("database/rented_cars");
    string id, type, brand, model, cost, condition, rent_day, rent_month, rent_year, due_day, due_month, due_year;
    string gap;
    while (getline(file, id)) {
        getline(file, type);
        getline(file, brand);
        getline(file, model);
        getline(file, cost);
        getline(file, condition);
        getline(file, rent_day);
        getline(file, rent_month);
        getline(file, rent_year);
        getline(file, due_day);
        getline(file, due_month);
        getline(file, due_year);
        getline(file, gap);

        Rent_Structure NowRentCar;
        NowRentCar.id = stoi(id);
        NowRentCar.type = type;
        NowRentCar.brand = brand;
        NowRentCar.model = model;
        NowRentCar.cost = stoi(cost);
        NowRentCar.condition = stoi(condition);
        NowRentCar.rent_day = stoi(rent_day);
        NowRentCar.rent_month = stoi(rent_month);
        NowRentCar.rent_year = stoi(rent_year);
        NowRentCar.due_day = stoi(due_day);
        NowRentCar.due_month = stoi(due_month);
        NowRentCar.due_year = stoi(due_year);
        this->rent_data.push_back(NowRentCar);
    }
    file.close();
}

void Rent_Database::writeInput(){
    ofstream file("database/rented_cars");

    for(auto x: this->rent_data){
        file << x.id << endl;
        file << x.type << endl;
        file << x.brand << endl;
        file << x.model<< endl;
        file << x.cost << endl;
        file << x.condition << endl;
        file << x.rent_day << endl;
        file << x.rent_month << endl;
        file << x.rent_year << endl;
        file << x.due_day << endl;
        file << x.due_month << endl;
        file << x.due_year << endl;
        file << endl;
    }
    file.close();
}