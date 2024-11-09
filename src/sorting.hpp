#pragma once
#include "tape.hpp"
#include <iostream>
namespace sorting {
void sort(Tape &mainTape, Tape &tape1, Tape &tape2) {
    tape1.resetTape();
    tape2.resetTape();
    Cylinder *lastCylinder = nullptr;
    Cylinder *lastCylinder1 = nullptr, *lastCylinder2 = nullptr;
}

void merge(Tape &mainTape, Tape &tape1, Tape &tape2) {
    mainTape.resetTape();
    tape1.goToStart();
    tape2.goToStart();
    Cylinder *lastCylinder = nullptr;
    Cylinder *cylinder1, *cylinder2;
    bool tape1Finished=false, tape2Finished=false;

    while (!tape1.isAtTapeEnd() || !tape2.isAtTapeEnd()) {
        cylinder1 = tape1.getCurrentRecord();
        cylinder2 = tape2.getCurrentRecord();
        if (cylinder1 == nullptr) tape1Finished = true;
        if (cylinder2 == nullptr) tape2Finished = true;
        if (tape1Finished || tape2Finished) {
            break;
        }
        if (*cylinder1 > *cylinder2) {
            mainTape.add(cylinder2);
            tape2.next();
        } else {
            mainTape.add(cylinder1);
            tape1.next();
        }
    }

    if (!tape1Finished) {
        mainTape.dumpTapeHere(&tape1);
    }
    if (!tape2Finished) {
        mainTape.dumpTapeHere(&tape2);
    }
}

void distribute(Tape &mainTape, Tape &tape1, Tape &tape2) {
    // mainTape.resetPage();
    tape1.resetTape();
    tape2.resetTape();
    Cylinder *lastCylinder = nullptr;
    bool tapeSwitch = true;
    for (int i = 0; i < RECORD_COUNT; i++) {
        Cylinder *cylinder = mainTape.getRecord(i);
        if (cylinder == nullptr)
            break;

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
