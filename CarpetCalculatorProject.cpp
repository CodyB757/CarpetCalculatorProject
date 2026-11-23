#include <iostream>
#include <iomanip>
#include "FeetInches.h"
#include "RoomDimension.h"
#include "RoomCarpet.h"

using namespace std;

int getValidNonNegative(const string& prompt) {
    int val;
    cout << prompt;
    while (!(cin >> val) || val < 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter 0 or greater: ";
    }
    return val;
}

double getValidPositivePrice(const string& prompt) {
    double val;
    cout << prompt;
    while (!(cin >> val) || val <= 0.0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid price. Enter a number greater than 0: ";
    }
    return val;
}

void runFeatureTests() {
    cout << "\n=== AUTOMATED FEATURE & RELATIONSHIP TESTS ===" << endl;

    FeetInches original(6, 4);
    FeetInches copyObj(original);
    copyObj.setFeet(10);
    cout << "Copy Test -> Original: " << original << " | Copy: " << copyObj << endl;

    FeetInches w1(10, 0), w2(12, 0);
    cout << "10'0\" * 12'0\" = " << (w1 * w2) << " sq ft (Expected: 120.00)" << endl;

    FeetInches f1(5, 6), f2(4, 3);
    cout << "5'6\" * 4'3\"   = " << setprecision(3) << (f1 * f2)
        << " sq ft (Expected: 23.375)" << setprecision(2) << endl;

    RoomDimension smallRoom(f1, f2);
    RoomCarpet budgetCarpet(&smallRoom, 4.00);
    RoomCarpet luxuryCarpet(&smallRoom, 8.50);
    cout << "Shared Room Budget Cost ($4.00/sqft): $" << budgetCarpet.getTotalCost() << endl;
    cout << "Shared Room Luxury Cost ($8.50/sqft): $" << luxuryCarpet.getTotalCost() << endl;
}

int main() {
    cout << fixed << setprecision(2);
    cout << "=== WESTFIELD CARPET CALCULATOR ===" << endl;

    int lenFeet = getValidNonNegative("Enter room length feet: ");
    int lenInches = getValidNonNegative("Enter room length inches: ");
    int widFeet = getValidNonNegative("Enter room width feet: ");
    int widInches = getValidNonNegative("Enter room width inches: ");
    double price = getValidPositivePrice("Enter carpet price per square foot: $");

    FeetInches length(lenFeet, lenInches);
    FeetInches width(widFeet, widInches);

    RoomDimension room(length, width);
    RoomCarpet carpet(&room, price);

    cout << "\n--- Room Quote ---" << endl;
    cout << "Length:        " << room.getLength() << endl;
    cout << "Width:         " << room.getWidth() << endl;
    cout << "Area:          " << room.getArea() << " sq ft" << endl;
    cout << "Price/Sq Ft:  $" << carpet.getCostPerSquareFoot() << endl;
    cout << "Total Cost:   $" << carpet.getTotalCost() << endl;

    runFeatureTests();
    return 0;
}