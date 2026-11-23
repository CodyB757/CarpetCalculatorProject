#include "RoomCarpet.h"

RoomCarpet::RoomCarpet(const RoomDimension* room, double price)
    : dimensions(room), costPerSquareFoot(price > 0.0 ? price : 0.0) {
}

double RoomCarpet::getTotalCost() const {
    if (dimensions == nullptr) {
        return 0.0;
    }
    return dimensions->getArea() * costPerSquareFoot;
}

double RoomCarpet::getCostPerSquareFoot() const {
    return costPerSquareFoot;
}