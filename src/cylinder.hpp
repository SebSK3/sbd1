#pragma once

#include "consts.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
/*
 * 29. File records: Right circular cylinders - the radius of the base and the
 * height of the cylinder. Sorting by volume.
 */

class Cylinder {
  public:
    int base;
    int height;
    double GetVolume() const;

    std::string serializeBase();
    std::string serializeHeight();

    /* Operators */
    bool operator>(const Cylinder &other) const {
        return GetVolume() > other.GetVolume();
    }
    bool operator>=(const Cylinder &other) const {
        return GetVolume() >= other.GetVolume();
    }
    bool operator<(const Cylinder &other) const {
        return GetVolume() < other.GetVolume();
    }
    bool operator<=(const Cylinder &other) const {
        return GetVolume() <= other.GetVolume();
    }
    bool operator==(const Cylinder &other) const {
        return GetVolume() == other.GetVolume();
    }
    friend std::ostream &operator<<(std::ostream &os, const Cylinder &cyl) {
        os << cyl.GetVolume();
        return os;
    }
};
