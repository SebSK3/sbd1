#pragma once
#include "tape.hpp"
namespace sorting {
bool merge(Tape *mainTape, Tape *tape1, Tape *tape2) {
    bool sorted = true;
    mainTape->resetPage();
    tape1->goToStart();
    tape2->goToStart();
    Cylinder *lastCylinder = new Cylinder();
    Cylinder *lastCylinder1 = new Cylinder();
    Cylinder *lastCylinder2 = new Cylinder();
    Cylinder *cylinder1 = new Cylinder();
    Cylinder *cylinder2 = new Cylinder();
    lastCylinder->clear();
    lastCylinder1->clear();
    lastCylinder2->clear();
    cylinder1->clear();
    cylinder2->clear();
    bool tape1Finished=false, tape2Finished=false;
    while (!tape1->isAtFileEnd() || !tape2->isAtFileEnd()) {
        *cylinder1 = *tape1->getCurrentRecord();
        *cylinder2 = *tape2->getCurrentRecord();
        if (!cylinder1->exists()) {
            tape1Finished = true;
            break;
        }
        if (!cylinder2->exists()) {
            tape2Finished = true;
            break;
        }
        if (*cylinder1 > *cylinder2) {
            mainTape->add(cylinder2->base, cylinder2->height);
            if (*lastCylinder2 > *cylinder2) {
                sorted = false;
            }
            *lastCylinder2 = *cylinder2;
            *lastCylinder = *cylinder2;
            tape2->next();
        } else {
            mainTape->add(cylinder1->base, cylinder1->height);
            if (*lastCylinder1 > *cylinder1) {
                sorted = false;
            }
            *lastCylinder1 = *cylinder1;
            *lastCylinder = *cylinder1;
            tape1->next();
        }
    }

    if (!tape1Finished) {
        sorted = mainTape->dumpRestOfTapeHere(tape1, lastCylinder) && sorted;
    }
    if (!tape2Finished) {
        sorted = mainTape->dumpRestOfTapeHere(tape2, lastCylinder) && sorted;
    }
    delete lastCylinder;
    delete lastCylinder1;
    delete lastCylinder2;
    delete cylinder1;
    delete cylinder2;
    mainTape->save();
    tape1->resetPage();
    tape2->resetPage();
    return sorted;
}

void distribute(Tape *mainTape, Tape *tape1, Tape *tape2) {
    mainTape->goToStart();
    tape1->resetPage();
    tape1->resetFile();
    tape2->resetPage();
    tape2->resetFile();
    Cylinder *lastCylinder = new Cylinder();
    lastCylinder->clear();
    mainTape->load();
    Cylinder *cylinder = new Cylinder();
    *cylinder = *mainTape->getCurrentRecord();
    bool tapeSwitch = true;
    while (!mainTape->isAtFileEnd()) {
        if (!cylinder->exists())
            break;

        if (*cylinder < *lastCylinder) {
            tapeSwitch = !tapeSwitch;
        }

        if (tapeSwitch) {
            tape1->add(cylinder->base, cylinder->height);
        } else {
            tape2->add(cylinder->base, cylinder->height);
        }
        lastCylinder->base = cylinder->base;
        lastCylinder->height = cylinder->height;

        *cylinder = *mainTape->next();
    }
    tape1->save();
    tape2->save();
    tape1->resetTape();
    tape2->resetTape();
    delete lastCylinder;
    delete cylinder;
}

void sort(Tape *mainTape) {
    Tape *tape1 = new Tape(TAPE1_NAME);
    Tape *tape2 = new Tape(TAPE2_NAME);
    bool sorted = false;
    while (!sorted) {
        distribute(mainTape, tape1, tape2);
        sorted = merge(mainTape, tape1, tape2);
    }
// #ifdef DEBUG
//     std::cout << "maintape: \n";
//     mainTape->dumpFile();
//     std::cout << "tape1: \n";
//     tape1->dumpFile();
//     std::cout << "tape2: \n";
//     tape2->dumpFile();
// #endif
    delete tape1;
    delete tape2;
}
} // namespace sorting
