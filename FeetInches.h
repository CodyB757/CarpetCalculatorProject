#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches {
private:
    int feet;
    int inches;
    void simplify();

public:
    FeetInches(int f = 0, int i = 0) {
        feet = f;
        inches = i;
        simplify();
    }
    FeetInches(const FeetInches& other);
    double operator*(const FeetInches& right) const;
    void setFeet(int f) { feet = f; }
    void setInches(int i) { inches = i; simplify(); }

    int getFeet() const { return feet; }
    int getInches() const { return inches; }

    FeetInches operator+(const FeetInches&);
    FeetInches operator-(const FeetInches&);
    FeetInches operator++();
    FeetInches operator++(int);
    bool operator>(const FeetInches&);
    bool operator<(const FeetInches&);
    bool operator==(const FeetInches&);

    operator double();
    operator int();

    friend ostream& operator<<(ostream&, const FeetInches&);
    friend istream& operator>>(istream&, FeetInches&);
};

#endif