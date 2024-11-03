#pragma once

#include "consts.hpp"
#include <iostream>
/*
 * 29. File records: Right circular cylinders - the radius of the base and the
 * height of the cylinder. Sorting by volume.
 */

class Cylinder {
  public:
    double base;
    double height;
    double GetVolume() const;


    /* Operators */
    bool operator>(const Cylinder& other) const {
        return GetVolume() > other.GetVolume();
    }
    bool operator>=(const Cylinder& other) const {
        return GetVolume() >= other.GetVolume();
    }
    bool operator<(const Cylinder& other) const {
        return GetVolume() < other.GetVolume();
    }
    bool operator<=(const Cylinder& other) const {
        return GetVolume() <= other.GetVolume();
    }
    bool operator==(const Cylinder& other) const {
        return GetVolume() == other.GetVolume();
    }
};
