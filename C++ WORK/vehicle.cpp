#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <map>
#include <algorithm>
#include <limits>
#include <exception>
#include <regex>

using namespace std;

class Vehicle{
    protected: 
        string id, make, model;
        int passengerCapacity, storageCapacity;
        bool readyToRent;
        double lateFeeRate;
        bool isReserved;


    public: 
        Vehicle(string id, string make, string model, int passengerCapacity, int storageCapacity, bool readyToRent, double lateFeeRate = 0.0)
            : id(id), make(make), model(model), passengerCapacity(passengerCapacity), storageCapacity(storageCapacity), readyToRent(readyToRent), lateFeeRate(lateFeeRate), isReserved(false) {}

        string getId() const {return id; }
        string getMake () const {return make;}
        string getModel () const {return model;}
        int getPassengerCapacity () const {return passengerCapacity;}
        int  getStorageCapacity () const {return storageCapacity;}
        bool  isReadyToRent () const {return readyToRent;}
        void setAvailableToRent (bool status) {readyToRent = status ;}
        double getLateFeeRate() const {return lateFeeRate;}
        void setLateFeeRate(double rate) {lateFeeRate = rate;}
        bool isCurrentlyReserved() const {return isReserved;}

        //these are for when we want to reserve, cancel or return the vehicle
        void reserve() {isReserved = true;}
        void cancelReservation() {isReserved = false;}
        void becomeAvailable() {isReserved = false;}

        virtual ~Vehicle()
        {
            cout << "Destroying Vehicle: " << id << endl;
        }



};

class Car : public Vehicle {
    public:
        Car(string id, string make, string model, int passengerCapacity, int storageCapacity, bool readyToRent)
            :Vehicle(id, make, model, passengerCapacity, storageCapacity, readyToRent, 10.00) {}

        ~Car() override{
        cout << "Destroying Car: " << getId() << endl;
    }
};

class Van : public Vehicle {
    public:
        Van(string id, string make, string model, int passengerCapacity, int storageCapacity, bool readyToRent)
            : Vehicle(id, make, model, passengerCapacity, storageCapacity, readyToRent, 20.00) {}

        ~Van() override {
            cout << "Destroying Van: " << getId() << endl;
        }
};

class MiniBus : public Vehicle {
    public:
        MiniBus(string id, string make, string model, int passengerCapacity, int storageCapacity, bool readyToRent)
            : Vehicle(id, make, model, passengerCapacity, storageCapacity, readyToRent, 30.00) {}

        ~MiniBus() override {
            cout << "Destroying MiniBus: " << getId() << endl;
        }
};

bool isValidDate(const string& date)
    {
        regex datePattern(R"(\d{4}-\d{2}-\d{2})");
        return regex_match(date, datePattern);
    }


class Customer 
{
    string nationalId, name;
    vector <string> rentedVehicles;

    public:

        Customer() : nationalId(""), name ("") {}


        Customer(string nationalId, string name) : nationalId(nationalId), name(name) {}

        string getNationalId() const {return nationalId;}
        string getName() const {return name;}

        void rentVehicle(const string& vehicleID)
        {
            //fix this dami to avoid duplicate entries
            if (find(rentedVehicles.begin(), rentedVehicles.end(), vehicleID) == rentedVehicles.end()) {
                rentedVehicles.push_back(vehicleID);
            }
        }
        void returnVehicle(const string& vehicleID)
        {
            auto it = find(rentedVehicles.begin(), rentedVehicles.end(), vehicleID );
            if (it != rentedVehicles.end()) rentedVehicles.erase(it);
        }

        const vector<string>& getRentedVehicles() const { return rentedVehicles; }

        //chukwu chukwu chuk chuk chu chu chu chuku chuku chuk chuk chu chu chu chuku chuk
};

class RentalCompany 
{
    private:
    vector<Vehicle*> vehicles;
    map <string, Customer> customers;
    map <string, string> dueDates;
    map <string, vector<string>> vehicleReservations;

    public:


        void addCustomer(const Customer& customer) 
        {

            const string& customerId = customer.getNationalId();
            regex idPattern(R"(^\d{3}$)");

            if (!regex_match(customerId,idPattern))
            {
                cout << "Invalid customer ID! Please use exactly 3 numeric digits (e.g 101)." << endl;
                return;
            }
            auto it = customers.find(customer.getNationalId());

            if (it != customers.end())
            {
                cout << "Warning: The customer with ID " << customer.getNationalId() << "(" << it->second.getName() << ") already exists." << endl;
                cout << "Do you want to replace the existing customer with the new one? (yes/no): ";


                //using char instead of string so that only the first letter matters anyways(for more consistent inputing or in case they spell yes wrong)

                char choice;
                cin >> choice;

                if (choice == 'y' || choice == 'Y') 
                {
                    customers[customer.getNationalId()] = customer;
                    cout << "Customer replaced successfully." << endl;
                }

                else
                {
                    cout << "The existing customer will be kept" << endl;

                }

            }

            else 
            {
                customers[customer.getNationalId()] = customer;
                cout << "New customer added successfully." << endl;

            }
        }

        void removeCustomer(const string& customerId) 
        {
            auto it = customers.find(customerId);
            if (it != customers.end()) 
            {
                string customerName = it->second.getName();

                customers.erase(it);
                cout << "Customer " << customerName << "(" << customerId << ") removed successfully!" << endl;   
            }

            else
            {
                cout << "Customer not found!" << endl;
            }
        }

        void addVehicle(Vehicle* vehicle) 
        {

            string vehicleId = vehicle->getId();

            //validating vehicle ID format
            if (vehicleId.length() < 2 || vehicleId.length() > 4)
            {
                cout << "Invalid Vehicle ID fomrat! Please use the format 'V101.' (capital letter V and 3 digits) " << endl;
                return;
            }

            if (vehicleId[0] != 'V')
            {
                cout << "Invalid Vehicle ID fomrat! Please use the format 'V101.'(capital letter V and 3 digits) " <<endl;
                return;
            }

            for (size_t i = 1; i < vehicleId.length(); ++i)
            {
                if (!isdigit(vehicleId[i]))
                {
                    cout << "Invalid Vehicle ID fomrat! Please use the format 'V101.'(capital letter V and 3 digits) " << endl;
                    return;
                }
            }

            //checking for duplicate Vehicle IDs
            for (auto& v : vehicles)
            {
                if (v->getId() == vehicleId)
                {
                    cout << "Error! Vehicle ID '" << vehicleId << "' already exists in the system." << endl;
                    return;
                }
            }

            //validating passenger capacity
            if (vehicle->getPassengerCapacity() <= 0)
            {
                cout << "Error! Passenger capacity must be greater than 0." << endl;
                return;

            }

            //validating storage capacity
            if (vehicle->getStorageCapacity() <= 0)
            {
                cout << "Error! Storage capacity must be greater than 0." << endl;
                return;

            }

            // check readyToRent and assign the appriopriate status
            if (!vehicle->isReadyToRent())
            {
                vehicle->setAvailableToRent(false);
                cout << "Vehicle added with status: Not available" << endl;

            }
            else 
            {
                cout << "Vehicle added with status: Available for Rent." << endl;
            }

            //adding vehicles to te system
            vehicles.push_back(vehicle); 
            cout << "Vehicle with ID" << vehicleId << " added successfully!" << endl;
            cout << "Vehicle Type: " << typeid(*vehicle).name() << endl;

            //display all vehicles in the system (this is to allow one to see all vehicles and their types)
            for (auto& v: vehicles)
            {
                cout << "Vehicle ID in system: " << v->getId() << ", Type: " << typeid(*v).name() << endl;
            }
        }

        void removeVehicle(const string& vehicleId) 
        {
            auto it = find_if(vehicles.begin(), vehicles.end(), //continued it on next line
                    [&vehicleId](Vehicle* v) {return v->getId() == vehicleId;});

            if (it != vehicles.end()) 
            {

                string vehicleMake = (*it)->getMake();
                string vehicleModel = (*it)->getModel();
                delete *it;
                vehicles.erase(it);
                cout << "Vehicle with ID " << vehicleId << "(" << vehicleMake << " " << vehicleModel << ") has been removed successfully." << endl;
            } 
            else 
            {
                cout << "Vehicle with ID " << vehicleId << " not found." << endl;
            }
        }


        void rentVehicle(const string& customerID, const string& vehicleId )
        {
            auto customer = customers.find(customerID);
            if (customer == customers.end()) throw invalid_argument("Customer not found!");

            for (auto& vehicle: vehicles) {
                if (vehicle->getId() == vehicleId) 
                {
                    if (!vehicle->isReadyToRent()) throw runtime_error("Vehicle not available!");

                    vehicle->setAvailableToRent(false);
                    customer->second.rentVehicle(vehicleId);

                    string dueDate;
                    cout << "Enter due date for this vehicle(in the format YYYY-MM-DD)" << endl;
                    cin >> dueDate;

                    if (!isValidDate(dueDate))
                    {
                        cout << "Invalid date format. Please use YYYY-MM-DD." << endl;
                    }

    
                    setDueDate(vehicleId, dueDate);

                    vehicle->setAvailableToRent(false);
                    customer->second.rentVehicle(vehicleId);

                    cout << "Vehicle rented successfully!" << endl;
                    return;
                }
            }

            throw invalid_argument("Vehicle ID not found!");

            
        }


        void returnVehicle(const string& customerID, const string&vehicleId) 
        {
            auto customerIt = customers.find(customerID);
            if (customerIt == customers.end()) throw invalid_argument("Customer not found!");


            for (auto& vehicle: vehicles) 
            {
                if(vehicle->getId() == vehicleId) 
                {
                    vehicle->setAvailableToRent(true);
                    customerIt->second.returnVehicle(vehicleId);
                    cout << "Vehicle " << vehicleId << "returned successfully!" << endl;


                    string returnDate;
                    cout << "Enter return date for the vehicle (Must be in the format YYYY-MM-DD): " << endl;
                    cin >> returnDate;

                    try 
                    {
                        double lateFee = calculateLateFee(vehicleId, returnDate);

                        if (lateFee > 0)
                        {
                            cout << "This vehicle was not returned on time" << endl;
                            cout << "Late fee for this vehicle" <<vehicleId << "is : £" << lateFee << endl;
                        }
                        else
                        {
                            cout << "No late fee for Vehicle " <<vehicleId << endl;
                        }
                    }

                    catch (const exception& e)
                    {
                        cout << "Error calculating late fee: " << e.what() << endl;
                    }

                    if (vehicleReservations.find(vehicleId) != vehicleReservations.end())
                    {
                        makeVehicleRentable(vehicleId);                        
                    } 
                    else 
                    {
                        dueDates.erase(vehicleId);
                    }

                    return;
                }
            }

            throw invalid_argument("Vehicle ID not found!");
 
        };

        
        //check sum here
        void displayAvailableVehicles() 
        {
            cout << "VEHICLES IN THE SYSTEM: " << endl;

            if (vehicles.empty())
            {
                cout << "No vehicles available in the system." << endl;
                return;
            }

            for (auto& vehicle : vehicles)
            {
                cout << endl;
                cout << "Vehicle ID: " << vehicle->getId() << endl;

                cout << "ID: " << vehicle->getId() << endl;
                cout << "Make: " << vehicle->getMake() << endl;
                cout << "Model: " << vehicle->getModel() << endl;
                cout << "Passenger Capacity: " << vehicle->getPassengerCapacity() << endl;
                cout << "Storage Capacity: " << vehicle->getStorageCapacity() << endl;
                cout << "Status: " << (vehicle->isReadyToRent() ? "Availble for Rent" : "Currently Rented") << endl;

                if(!vehicle->isReadyToRent())
                {
                    cout << "Status: Not available" << endl;
                }

                else if(vehicle->isCurrentlyReserved())
                {
                    cout << "Status: Reserved " << endl;
                }
                
                else
                {
                    cout << "Status: Available for Rent" << endl;
                }
            }
        }

        void setDueDate(const string& vehicleId, const string& returnDate)
        {
           dueDates[vehicleId] = returnDate; 
           
        }

        double calculateLateFee(const string& vehicleId, const string& returnDate)
        {
            if(dueDates.find(vehicleId) == dueDates.end())
            {
                throw runtime_error("Due date not found for this vehicle.");
            }

            int due = stoi(dueDates[vehicleId].substr(0,4)) * 365 + stoi(dueDates[vehicleId].substr(5,2)) * 30 + stoi(dueDates[vehicleId].substr(8,2));
            int returned = stoi(returnDate.substr(0,4)) * 365 + stoi(returnDate.substr(5,2)) * 30 + stoi(returnDate.substr(8,2));

            int daysLate = max(0, returned - due);

            auto it = find_if(vehicles.begin(), vehicles.end(), [&vehicleId](Vehicle* v) {return v->getId() == vehicleId;});

            if (it == vehicles.end())
            {
                throw runtime_error("Vehicle not found.");
            }

            double lateFeeRate = (*it)->getLateFeeRate();
            return daysLate * lateFeeRate;

        }

        
        void searchVehicleById(const string& vehicleId)
        {
            auto it = find_if(vehicles.begin(), vehicles.end(), [&vehicleId](Vehicle* v) {return v->getId() == vehicleId;});
        

            if (it != vehicles.end()) 
            {
                Vehicle* vehicle = *it;
                cout << "Car found: " << endl;
                cout << "ID: " << vehicle->getId() << endl;
                cout << "Make: " << vehicle->getMake() << endl;
                cout << "Model: " << vehicle->getModel() << endl;
                cout << "Passenger Capacity: " << vehicle->getPassengerCapacity() << endl;
                cout << "Storage Capacity: " << vehicle->getStorageCapacity() << endl;
                cout << "Ready to Rent: " << (vehicle->isReadyToRent() ? "Yes" : "No") << endl;

            }

            else 
            {
                cout << "Car with ID " << vehicleId << " not found." << endl;
            }

        }

        void displayCustomers() 
        {
            cout << "Customers: " << endl;
            for (auto& customer : customers) {
                cout << "ID: " << customer.second.getNationalId() << ", Name: " << customer.second.getName() << endl;

                const vector<string>& rentedVehicles = customer.second.getRentedVehicles();
                if (!rentedVehicles.empty()) 
                {
                    cout << "  Rented Vehicles: ";
                    for (const auto& vehicleId : rentedVehicles) 
                    {
                        cout << vehicleId << " "; // Display each rented vehicle ID
                    }
                    cout << endl;
                }

                else
                {
                    cout << "No vehicles rented." << endl;
                }
            }

        }

        void reserveVehicle(const string& vehicleId, const string& customerId)
        {
            auto vehicleIt = find_if(vehicles.begin(), vehicles.end(), [&vehicleId](Vehicle* v) { return v->getId() == vehicleId;});

            if (vehicleIt == vehicles.end())
            {
                cout << " Error! Vehicle with ID " << vehicleId << "does not exist." << endl;
                return;
            }

            //finds the customer
            auto customerIt = customers.find(customerId);

            if (customerIt == customers.end()) 
            {
                cout << "Error: Customer with ID " << customerId << " does not exist." << endl;
                return;
            }

            Vehicle* vehicle = *vehicleIt;

            //search for the vehicle in the system to see if it's already reserved
            if (vehicleReservations.find(vehicleId) != vehicleReservations.end())
            {
                cout << "This vehicle is already reserved by other customer(s). You will be notified when it becomes available." << endl;

                cout<< "CUSTOMER RESERVATION QUEUE FOR: " << vehicleId << "(" << vehicleId << ")" << endl;
                cout << endl;

                const vector<string>& reservationQueue = vehicleReservations[vehicleId];
                for (size_t i = 0; i < reservationQueue.size(); ++i)
                {
                    cout << i + 1 << ". Customer ID: " << reservationQueue[i] << endl;
                }
                cout << endl;

                if(find(reservationQueue.begin(), reservationQueue.end(), customerId) == reservationQueue.end())
                {
                    vehicleReservations[vehicleId].push_back(customerId);
                    cout << "Customer " << customerId << "has been added to the reservation queue for vehicle " << vehicleId << "." << endl;
                    return;
                }

                else
                {
                    cout << "Customer " << customerId << "has already reserved this vehicle. " << endl;
                }

                return;
            }

            vehicleReservations[vehicleId].push_back(customerId);
            cout << "Vehicle with ID " << vehicleId << " has been reserved successfully by customer " << customerId << "." << endl;
                        
            //to check if the vehicle has been rented already
            if (!vehicle->isReadyToRent())
            {
                cout << "Note: The vehicle is currently rented. You will be notified once it is returned" << endl;
            }
        }

        bool isVehicleResreved(const string& vehicleId) 
        {
            return vehicleReservations.find(vehicleId) != vehicleReservations.end();

        }

        void makeVehicleRentable(const string& vehicleId)
        {
            for (auto& vehicle : vehicles)
            {
                if (vehicle->getId() == vehicleId)
                {
                    // Marking the vehicle as available
                    vehicle->becomeAvailable();
                    vehicle->setAvailableToRent(true);
                    cout << "Vehicle " << vehicleId << " is now available!" << endl;

                    // Alerts the reserving customer
                    if (vehicleReservations.find(vehicleId) != vehicleReservations.end())
                    {
                        vector<string>& reservationQueue = vehicleReservations[vehicleId];

                        while (!reservationQueue.empty())
                        {
                            string customerId = reservationQueue.front();
                            reservationQueue.erase(reservationQueue.begin());

                            cout << "Alert: The reserved vehicle" << vehicleId << "is now available for customer " << customerId << "!" << endl;

                            char choice;
                            cout << "Customer " << customerId << ", would you like to rent the vehicle now? (y/n): "<< endl;
                            cin >> choice;

                            if (choice == 'y' || choice == 'Y')
                            {
                                try
                                {
                                    rentVehicle(customerId, vehicleId);
                                    break;
                                }
                                catch (const exception& e)
                                {
                                    cout << e.what() << endl;

                                }
                            }

                            else 
                            {
                                cout << "Reservation declined by customer " <<customerId << "." << endl;
                            }
                        }

                        //if reservation queue is empty, remove the reservation entry 
                        if (reservationQueue.empty()) 
                        { 
                            vehicleReservations.erase(vehicleId);
                        }
                    }
                    return;
                }
            }

            cout << "Error: Vehicle with ID " << vehicleId << "not found." << endl;
        }

        void loadSampleData(const string& vehicleFile, const string& customerFile) 
        {
            ifstream vehicleStream(vehicleFile);
            string line;

            if (vehicleStream.is_open()) 
            {
                while (getline(vehicleStream, line)) 
                {
                    stringstream ss(line);
                    string id, make, model;
                    int seats, price, available;

                    // Read and parse the line for vehicle data
                    ss >> id >> make >> model >> seats >> price >> available;

                    // Create a new vehicle object and add it to the rental company
                    Vehicle* vehicle = new Vehicle(id, make, model, seats, price, available);
                    addVehicle(vehicle);
                }
                vehicleStream.close();
            } 
            else 
            {
                cout << "Failed to open vehicle data file." << endl;
            }
        }

        //had to differentiate this void from the other one similar. 
        // this is to remove the vehicle from being Not Available
        // it is different from rented and can be redone without customer ID

        void makeVehicleAvailable(const string& vehicleId)
        {
            for (auto& vehicle : vehicles)
            {
                if (vehicle->getId() == vehicleId)
                {
                    vehicle->setAvailableToRent(true);
                    vehicle->becomeAvailable();
                    cout << "Vehicle " << vehicleId << "is now available" << endl;
                    return;
                }
            }

            cout << "Error: Vehicle with ID " << vehicleId << "not found." << endl;
        }



};

void displayMenu() {
    cout << "\nRENTAL COMPANY MENU:" << endl;
    cout << "1. Add a Customer" << endl;
    cout << "2. Remove a customer" << endl;
    cout << "3. Add a Vehicle" << endl;
    cout << "4. Remove a Vehicle" << endl;
    cout << "5. Rent a Vehicle" << endl;
    cout << "6. Return a Vehicle" << endl;
    cout << "7. Display all customers" << endl;
    cout << "8. Display all vehicles" << endl;
    cout << "9. Search for a vehicle" << endl;
    cout << "10. Reserve a vehicle" << endl;
    cout << "11. Exit menu" << endl;
}

int main() {
    RentalCompany company;


    while (true) 
    {
        displayMenu();
        int choice;
        cout << "Enter your choice (from 1 to 10): ";
        cin>> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 10." << endl;
            continue;
        }

        switch (choice) 
        {

            //adding a customer
            case 1:
            {
                string nationalId, name;
                cout << "ADDING A CUSTOMER" << endl;
                cout << "Enter Customer ID: ";
                cin >> nationalId;
                cout << "Enter Customer's name: ";
                cin >> name;

                Customer customer(nationalId, name);
                company.addCustomer(customer);
                break;

            }

            //removing a customer
            case 2:
            {

                cout << "Available Customer IDs: ";
                company.displayCustomers(); 
                cout << endl;
                string customerId;
                cout << "REMOVING A CUSTOMER" << endl;
                cout << "Enter Customer ID to remove: ";
                cin >> customerId;

                company.removeCustomer(customerId);
                break;
            }


            //adding a vehicle
            case 3: 
            {
                string id, make, model;
                int passengerCapacity, storageCapacity;
                bool readyToRent;
                string vehicleType; 

                cout << "YOU ARE ADDING A VEHICLE:" << endl;
                cout << "Enter Vehicle ID: " << endl; 
                cin >> id;

                cout << "Enter Make: " << endl;
                cin >> make;

                cout << "Enter Model:" << endl;  
                cin >> model;

                cout << "Enter Passenger Capacity:" << endl;  
                cin >> passengerCapacity;

                cout << "Enter Storage Capacity:" << endl;  
                cin >> storageCapacity;

                cout << "Is the vehicle ready to rent? (1 for yes, 0 for no): " << endl;
                cin >> readyToRent;

                cout << "Enter Vehicle Type (C for Car, V for Van, M for MiniBus): ";
                cin >> vehicleType;

                Vehicle* vehicle = nullptr;

                if (vehicleType == "C" || vehicleType == "c") 
                {
                    vehicle = new Car(id, make, model, passengerCapacity, storageCapacity, readyToRent);
                }
                else if (vehicleType == "V" || vehicleType == "v") 
                {
                    vehicle = new Van(id, make, model, passengerCapacity, storageCapacity, readyToRent);
                }
                else if (vehicleType == "M" || vehicleType == "m") 
                {
                    vehicle = new MiniBus(id, make, model, passengerCapacity, storageCapacity, readyToRent);
                }
                else 
                {
                    cout << "Invalid vehicle type!" << endl;
                    break;
                }

                if (vehicle != nullptr)
                {
                    company.addVehicle(vehicle);
                }
                
                break;
                
            }

            //removing a vehicle
            case 4:
            {
                string vehicleId;
                cout << "REMOVING A VEHICLE" << endl; 
                cout << "Enter Vehicle ID to remove vehicle: ";
                cin >> vehicleId;

                company.removeVehicle(vehicleId);
                break;
            }

            //rent a vehicle
            case 5:
            {
                string customerId, vehicleId;
                cout << "Enter Customer ID:";
                cin >> customerId;
                cout << "Enter Vehicle ID:";
                cin >> vehicleId;

                try
                {
                    company.rentVehicle(customerId, vehicleId);
                }

                catch(const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;

            }

            //returning a vehicle
            case 6:
            {
                string customerId, vehicleId;
                cout << "Enter Customer ID:";
                cin >> customerId;
                cout << "Enter Vehicle ID:";
                cin >> vehicleId;

                try
                {
                    company.returnVehicle(customerId, vehicleId);
                }

                catch(const exception& e)
                {
                    cout << e.what() << endl;
                }
                break;
            }

            //display all customers 
            case 7:
            {
                company.displayCustomers();
                break;
            }

            //display available vehicles
            case 8:
            {
                company.displayAvailableVehicles();
                break;
            }

              
            //searching for a vehicle
            case 9:
            {
                string vehicleId;
                cout << "Enter Vehicle ID to search: ";
                cin >> vehicleId;
                company.searchVehicleById(vehicleId);
                break;
            } 

            //reserving a vehicle
            case 10:
            {
                string vehicleId, customerId;
                cout << "Enter vehicle ID to reserve" << endl;
                cin >> vehicleId;

                cout << "Enter Customer ID: " << endl;
                cin >> customerId;

                try
                {
                    company.reserveVehicle(vehicleId, customerId);
                }
                catch (const exception& e)
                {
                    cout << e.what() << endl;

                }
                break;
            }    

            //exiting a program
            case 11:
            {
                cout << "Exited program successfully." << endl;
                return 0;
            } 

            //reserving a vehicle
                

            default:
            {
                cout << "Invalid choice. Please enter a number from 1 to 10" << endl;
            }

        }

        

    }



    return 0;
}


