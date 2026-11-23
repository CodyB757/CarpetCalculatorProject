#include "RoomDimension.h"

RoomDimension::RoomDimension(const FeetInches& roomLength, const FeetInches& roomWidth)
    : length(roomLength), width(roomWidth) {
}

double RoomDimension::getArea() const {
    return length * width;
}

FeetInches RoomDimension::getLength() const {
    return length;
}

FeetInches RoomDimension::getWidth() const {
    return width;
}