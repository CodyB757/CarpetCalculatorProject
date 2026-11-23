#ifndef ROOMCARPET_H
#define ROOMCARPET_H

#include "RoomDimension.h"

class RoomCarpet {
private:
    const RoomDimension* dimensions; // non-owning pointer (Aggregation)
    double costPerSquareFoot;

public:
    RoomCarpet(const RoomDimension* room, double price);
    double getTotalCost() const;
    double getCostPerSquareFoot() const;
};

#endif