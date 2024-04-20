#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Base class
class Servicing {
protected:
    string customerName;
    string vehicleNo;
    string mobileNo;
    double totalBill;

public:
    Servicing(string _customerName, string _vehicleNo, string _mobileNo) : customerName(_customerName), vehicleNo(_vehicleNo), mobileNo(_mobileNo), totalBill(0.0) {}

    virtual void calculateTotalBill() = 0; // Pure virtual function
};

// Derived class for Maintenance
class Maintenance : public Servicing {
protected:
    string partName;
    double partPrice;
    double labourCharge;

public:
    Maintenance(string _customerName, string _vehicleNo, string _mobileNo, string _partName, double _partPrice, double _labourCharge)
        : Servicing(_customerName, _vehicleNo, _mobileNo), partName(_partName), partPrice(_partPrice), labourCharge(_labourCharge) {}

    void calculateTotalBill() override {
        // Checking for negative prices
        if (partPrice < 0 || labourCharge < 0) {
            throw invalid_argument("Price cannot be negative.");
        }

        double totalPartPrice = partPrice * 1.05; // Including 5% GST
        double totalLabourCharge = labourCharge * 1.05; // Including 5% GST

        totalBill = totalPartPrice + totalLabourCharge;
    }
};

// Derived class for Oil Change
class OilChange : public Servicing {
protected:
    string oilName;
    double oilPrice;

public:
    OilChange(string _customerName, string _vehicleNo, string _mobileNo, string _oilName, double _oilPrice)
        : Servicing(_customerName, _vehicleNo, _mobileNo), oilName(_oilName), oilPrice(_oilPrice) {}

    void calculateTotalBill() override {
        // Checking for negative prices
        if (oilPrice < 0) {
            throw invalid_argument("Price cannot be negative.");
        }

        double totalOilPrice = oilPrice * 1.12; // Including 12% GST

        totalBill = totalOilPrice;
    }
};

// User-defined exception class
class NegativePriceException : public exception {
public:
    const char* what() const throw() {
        return "Price cannot be negative.";
    }
};

int main() {
    string customerName, vehicleNo, mobileNo;
    cout << "Enter customer name: ";
    getline(cin, customerName);
    cout << "Enter vehicle number: ";
    getline(cin, vehicleNo);
    cout << "Enter mobile number: ";
    getline(cin, mobileNo);

    int choice;
    cout << "Enter type of servicing (1 for Maintenance/Repairing, 2 for Engine/Gear Oil Change): ";
    cin >> choice;

    try {
        if (choice == 1) {
            string partName;
            double partPrice, labourCharge;
            cout << "Enter part name: ";
            cin.ignore();
            getline(cin, partName);
            cout << "Enter part price: ";
            cin >> partPrice;
            cout << "Enter labour charge: ";
            cin >> labourCharge;

            Maintenance maintenance(customerName, vehicleNo, mobileNo, partName, partPrice, labourCharge);
            maintenance.calculateTotalBill();

            cout << "Total bill: $" << maintenance.totalBill << endl;
        } else if (choice == 2) {
            string oilName;
            double oilPrice;
            cout << "Enter oil name: ";
            cin.ignore();
            getline(cin, oilName);
            cout << "Enter oil price: ";
            cin >> oilPrice;

            OilChange oilChange(customerName, vehicleNo, mobileNo, oilName, oilPrice);
            oilChange.calculateTotalBill();

            cout << "Total bill: $" << oilChange.totalBill << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } catch (const NegativePriceException& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
