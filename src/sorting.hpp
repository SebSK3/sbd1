#pragma once
#include <iostream>
#include "tape.hpp"
namespace sorting {
void sort() {

}

void distribute(Tape &mainTape, Tape &tape1, Tape &tape2) {
    // mainTape.resetPage();
    tape1.resetPage();
    tape2.resetPage();
    Cylinder *lastCylinder = nullptr;
    bool tapeSwitch = true;
    for (int i=0; i<RECORD_COUNT; i++) {
        Cylinder *cylinder = mainTape.getRecord(i);
        if (cylinder == nullptr) break;

        if (cylinder < lastCylinder) {
            tapeSwitch = !tapeSwitch;
        }

        if (tapeSwitch) {
            tape1.add(cylinder);
        } else {
            tape2.add(cylinder);
        }
        lastCylinder = cylinder;
    }

}
} // namespace sorting
