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

    return 0;
}