#include "main.h"

// Functions for Class Car
void Car::carRentRequest(int id, string type){
    cout << endl;
    cout << "Removing current car from Available Cars..." << endl;
    // Immediately Remove this car from the available cars;
}

// Functions for Car_Database
void Car_Database::Add(Car_Structure& AddCar){
    this->readInput();
    this->car_data.push_back(AddCar);
    this->writeInput();
}

void Car_Database::Delete(Car_Structure& DeletedCar){
    this->readInput();

    for(auto it = this->car_data.begin(); it != this->car_data.end();) {
        auto& x = *it;
        if(x.brand == this->brand && x.model == this->model && x.cost == this->cost){
            DeletedCar.brand = x.brand;
            DeletedCar.model = x.model;
            DeletedCar.cost = x.cost;
            DeletedCar.condition = x.condition;
            it = this->car_data.erase(it); 
        } else{
            ++it;
        }
    }
    this->writeInput();
}

bool Car_Database::displayAvailableCars(){
    this->readInput();

    if(this->car_data.size() == 0){
        cout << endl;
        cout << "No Cars Available at the moment" << endl;
        return false;
    } else {
        cout << endl;
        for(auto x: this->car_data){
            cout << green << arrows << reset;
            cout << "Brand: " << x.brand << endl;
            cout << green << arrows << reset;
            cout << "Model: "  << x.model << endl;
            cout << green << arrows << reset;
            cout << "Cost: " << x.cost << endl;
            cout << green << arrows << reset;
            cout << "Condition: " << x.condition << endl;
            cout << endl;
        }
        return true;
    }
}

void Car_Database::displayByInfo(string brand, string model){
    this->readInput();

    for(auto x: this->car_data){
        if(x.brand == brand && x.model == model){
            cout << green << arrows << reset;
            cout << "Brand: " << x.brand << endl;
            cout << green << arrows << reset;
            cout << "Model: "  << x.model << endl;
            cout << green << arrows << reset;
            cout << "Cost: " << x.cost << endl;
            cout << green << arrows << reset;
            cout << "Condition: " << x.condition << endl;
            cout << endl;
        }
    }

}

void Car_Database::UpdateCostCondition(string brand, string model, int cost, int condition){
    this->readInput();
    for(auto& x: this->car_data){
        if(x.brand == brand && x.model == model){
            if(cost != 0){
                x.cost = cost;
            }
            if(condition != 0){
                x.condition = condition;
            }
        }
    }
    this->writeInput();
}

void Car_Database::readInput(){
    ifstream file("database/available_cars");
    string brand, model, condition, cost, gap;
    while(getline(file, brand)){
        getline(file, model);
        getline(file, cost);
        getline(file, condition);
        getline(file, gap);

        Car_Structure CarNow;
        CarNow.brand = brand;
        CarNow.model = model;
        CarNow.condition = stoi(condition);
        CarNow.cost = stoi(cost);
        car_data.push_back(CarNow);
    }
    file.close();
}

void Car_Database::writeInput(){
    ofstream file("database/available_cars");
    for(auto x : car_data){
        file << x.brand << endl;
        file << x.model << endl;
        file << x.cost << endl;
        file << x.condition << endl;
        file << endl;
    }
    file.close();
}