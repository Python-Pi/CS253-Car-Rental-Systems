#include "main.h"

// Functions of the class Record Database
void Record_Database::getRecordInfo(int id, string type){
    this->readInput();

    int count = 0;
    cout << endl;
    for(auto x: record_data){
        if(x.id == id && x.type == type){
            cout << green << arrows << reset;
            cout << "Rent Date: " << x.rent_day << "/" << x.rent_month << "/" << x.rent_year << endl;
            cout << green << arrows << reset;
            cout << "Due Date: " << x.due_day << "/" << x.due_month << "/" << x.due_year << endl;
            cout << green << arrows << reset;
            cout << "Returned Date: " << x.return_day << "/" << x.return_month << "/" << x.return_year << endl;

            cout << green << arrows << reset;
            cout << "Brand: " << x.brand << endl;
            cout << green << arrows << reset;
            cout << "Model: " << x.model << endl;
            cout << green << arrows << reset;
            cout << "Cost: " << x.cost << endl;
            cout << green << arrows << reset;
            cout << "Condition of the car when rented: " << x.rent_condition << endl;
            cout << green << arrows << reset;
             cout << "Condition of the car when returned: " << x.return_condition << endl;
            cout << endl;

            count++;
        }
    }

    if(count == 0){
        cout << red << "No Records found..." << reset << endl;
    }
}

void Record_Database::getAllRecords(){
    this->readInput();
     for(auto x: record_data){
        cout << green << arrows << reset;
        cout << "Rent Date: " << x.rent_day << "/" << x.rent_month << "/" << x.rent_year << endl;
        cout << green << arrows << reset;
        cout << "Due Date: " << x.due_day << "/" << x.due_month << "/" << x.due_year << endl;
        cout << green << arrows << reset;
        cout << "Returned Date: " << x.return_day << "/" << x.return_month << "/" << x.return_year << endl;

        cout << green << arrows << reset;
        cout << "Brand: " << x.brand << endl;
        cout << green << arrows << reset;
        cout << "Model: " << x.model << endl;
        cout << green << arrows << reset;
        cout << "Cost: " << x.cost << endl;
        cout << green << arrows << reset;
        cout << "Condition of the car when rented: " << x.rent_condition << endl;
        cout << green << arrows << reset;
        cout << "Condition of the car when returned: " << x.return_condition << endl;
        cout << endl;
    }
}

void Record_Database::Add(Record_Structure AddRecord){
    this->readInput();
    this->record_data.push_back(AddRecord);
    this->writeInput();
}

void Record_Database::UpdateRecord(Record_Structure& RecordInfo){
    this->readInput();
    for(auto& x: this->record_data){
        if(x.id == RecordInfo.id && x.type == RecordInfo.type && x.brand == RecordInfo.brand && x.model == RecordInfo.model){
            if(RecordInfo.return_condition != 0){
                x.return_condition = RecordInfo.return_condition;
            }
            if(RecordInfo.return_day != 0){
                x.return_day = RecordInfo.return_day;
            }
            if(RecordInfo.return_month != 0){
                x.return_month = RecordInfo.return_month;
            }
            if(RecordInfo.return_year != 0){
                x.return_year = RecordInfo.return_year;
            }
        }
    }
    this->writeInput();
}

void Record_Database::readInput() {
    ifstream file("database/records");
    string id, type, brand, model, cost, rent_condition, return_condition, rent_day, rent_month, rent_year, due_day, due_month, due_year, return_day, return_month, return_year;
    string gap;
    while (getline(file, id)) {
        getline(file, type);
        getline(file, brand);
        getline(file, model);
        getline(file, cost);
        getline(file, rent_condition);
        getline(file, return_condition);
        getline(file, rent_day);
        getline(file, rent_month);
        getline(file, rent_year);
        getline(file, due_day);
        getline(file, due_month);
        getline(file, due_year);
         getline(file, return_day);
        getline(file, return_month);
        getline(file, return_year);
        getline(file, gap);

        Record_Structure CurrentRecord;
        CurrentRecord.id = stoi(id);
        CurrentRecord.type = type;
        CurrentRecord.brand = brand;
        CurrentRecord.model = model;
        CurrentRecord.cost = stoi(cost);
        CurrentRecord.rent_condition = stoi(rent_condition);
        CurrentRecord.return_condition = stoi(return_condition);
        CurrentRecord.rent_day = stoi(rent_day);
        CurrentRecord.rent_month = stoi(rent_month);
        CurrentRecord.rent_year = stoi(rent_year);
        CurrentRecord.due_day = stoi(due_day);
        CurrentRecord.due_month = stoi(due_month);
        CurrentRecord.due_year = stoi(due_year);
        CurrentRecord.return_day = stoi(return_day);
        CurrentRecord.return_month = stoi(return_month);
        CurrentRecord.return_year = stoi(return_year);

        this->record_data.push_back(CurrentRecord);
    }
    file.close();
}

void Record_Database::writeInput(){
    ofstream file("database/records");

    for(auto x: this->record_data){
        file << x.id << endl;
        file << x.type<< endl;
        file << x.brand << endl;
        file << x.model << endl;
        file << x.cost << endl;
        file << x.rent_condition << endl;
        file << x.return_condition << endl;
        file << x.rent_day << endl;
        file << x.rent_month << endl;
        file << x.rent_year << endl;
        file << x.due_day << endl;
        file << x.due_month << endl;
        file << x.due_year << endl;
        file << x.return_day << endl;
        file << x.return_month << endl;
        file << x.return_year << endl;
        file << endl;
    }
    file.close();
}