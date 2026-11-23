#include <cstdlib>
#include "FeetInches.h"
void FeetInches::simplify() {
    if (inches >= 12) {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0) {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}
FeetInches::FeetInches(const FeetInches& other) {
    feet = other.feet;
    inches = other.inches;
}
FeetInches FeetInches::operator+(const FeetInches& right) {
    FeetInches temp;
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

FeetInches FeetInches::operator-(const FeetInches& right) {
    FeetInches temp;
    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

FeetInches FeetInches::operator++() {
    ++inches;
    simplify();
    return *this;
}

FeetInches FeetInches::operator++(int) {
    FeetInches temp(feet, inches);
    inches++;
    simplify();
    return temp;
}

bool FeetInches::operator>(const FeetInches& right) {
    if (feet > right.feet) return true;
    if (feet == right.feet && inches > right.inches) return true;
    return false;
}

bool FeetInches::operator<(const FeetInches& right) {
    if (feet < right.feet) return true;
    if (feet == right.feet && inches < right.inches) return true;
    return false;
}

bool FeetInches::operator==(const FeetInches& right) {
    return (feet == right.feet && inches == right.inches);
}

FeetInches::operator double() {
    return feet + (inches / 12.0);
}

FeetInches::operator int() {
    return feet;
}

ostream& operator<<(ostream& strm, const FeetInches& obj) {
    strm << obj.feet << " feet, " << obj.inches << " inches";
    return strm;
}

istream& operator>>(istream& strm, FeetInches& obj) {
    cout << "Feet: ";
    strm >> obj.feet;
    cout << "Inches: ";
    strm >> obj.inches;
    obj.simplify();
    return strm;
}
double FeetInches::operator*(const FeetInches& right) const {
    int leftTotalInches = feet * 12 + inches;
    int rightTotalInches = right.feet * 12 + right.inches;
    double squareInches = static_cast<double>(leftTotalInches) * rightTotalInches;
    return squareInches / 144.0;
}