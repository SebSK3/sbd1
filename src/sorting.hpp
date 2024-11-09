#pragma once
#include "tape.hpp"
#include <iostream>
namespace sorting {
bool merge(Tape &mainTape, Tape &tape1, Tape &tape2) {
    bool sorted = true;
    mainTape.resetTape();
    tape1.goToStart();
    tape2.goToStart();
    Cylinder *lastCylinder = nullptr;
    Cylinder *lastCylinder1 = nullptr;
    Cylinder *lastCylinder2 = nullptr;
    Cylinder *cylinder1, *cylinder2;
    bool tape1Finished=false, tape2Finished=false;

    while (!tape1.isAtTapeEnd() || !tape2.isAtTapeEnd()) {
        cylinder1 = tape1.getCurrentRecord();
        cylinder2 = tape2.getCurrentRecord();
        if (cylinder1 == nullptr || cylinder2 == nullptr) break;
        if (*cylinder1 > *cylinder2) {
            mainTape.add(cylinder2);
            if (lastCylinder2 != nullptr && *lastCylinder2 > *cylinder2) {
                sorted = false;
            }
            lastCylinder2 = cylinder2;
            lastCylinder = cylinder2;
            tape2.next();
        } else {
            mainTape.add(cylinder1);
            if (lastCylinder1 != nullptr && *lastCylinder1 > *cylinder1) {
                sorted = false;
            }
            lastCylinder1 = cylinder1;
            lastCylinder = cylinder1;
            tape1.next();
        }
    }

    if (!tape1Finished) {
        sorted = mainTape.dumpTapeHere(&tape1, lastCylinder) && sorted;
    }
    if (!tape2Finished) {
        sorted = mainTape.dumpTapeHere(&tape2, lastCylinder) && sorted;
    }
    return sorted;
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

void sort(Tape &mainTape) {
    Tape tape1, tape2;
    tape1.resetTape();
    tape2.resetTape();
    Cylinder *lastCylinder = nullptr;
    Cylinder *lastCylinder1 = nullptr, *lastCylinder2 = nullptr;
    bool sorted = false;
    while (!sorted) {
        distribute(mainTape, tape1, tape2);
#ifdef DEBUG
        std::cout << "distributed tape1:\n";
        tape1.dump();
        std::cout << "distributed tape2:\n";
        tape2.dump();
#endif
        sorted = merge(mainTape, tape1, tape2);
#ifdef DEBUG
        std::cout << "merged tape:\n";
        mainTape.dump();
#endif
    }
}
} // namespace sorting
