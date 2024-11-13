#pragma once
#include "tape.hpp"
namespace sorting {
// bool merge(Tape &mainTape, Tape &tape1, Tape &tape2) {
//     bool sorted = true;
//     mainTape.nullTape();
//     Cylinder *lastCylinder = nullptr;
//     Cylinder *lastCylinder1 = nullptr;
//     Cylinder *lastCylinder2 = nullptr;
//     Cylinder *cylinder1, *cylinder2;
//     bool tape1Finished=false, tape2Finished=false;

//     while (!tape1.isAtTapeEnd() || !tape2.isAtTapeEnd()) {
//         cylinder1 = tape1.getCurrentRecord();
//         cylinder2 = tape2.getCurrentRecord();
//         if (cylinder1 == nullptr) {
//             tape1Finished = true;
//             break;
//         }
//         if (cylinder2 == nullptr) {
//             tape2Finished = true;
//             break;
//         }
//         if (*cylinder1 > *cylinder2) {
//             mainTape.add(cylinder2);
//             if (lastCylinder2 != nullptr && *lastCylinder2 > *cylinder2) {
//                 sorted = false;
//             }
//             lastCylinder2 = cylinder2;
//             lastCylinder = cylinder2;
//             tape2.next();
//         } else {
//             mainTape.add(cylinder1);
//             if (lastCylinder1 != nullptr && *lastCylinder1 > *cylinder1) {
//                 sorted = false;
//             }
//             lastCylinder1 = cylinder1;
//             lastCylinder = cylinder1;
//             tape1.next();
//         }
//     }

//     if (!tape1Finished) {
//         sorted = mainTape.dumpTapeHere(&tape1, lastCylinder) && sorted;
//     }
//     if (!tape2Finished) {
//         sorted = mainTape.dumpTapeHere(&tape2, lastCylinder) && sorted;
//     }
//     mainTape.save();
//     tape1.nullTape();
//     tape2.nullTape();
//     return sorted;
// }

void distribute(Tape *mainTape, Tape *tape1, Tape *tape2) {
    mainTape->resetTape();
    tape1->resetPage();
    tape2->resetPage();
    Cylinder *lastCylinder = new Cylinder();
    lastCylinder->clear();
    mainTape->load();
    // mainTape.reset();
    // tape1.reset(true);
    // tape2.reset(true);
    Cylinder *cylinder = mainTape->getCurrentRecord();
    bool tapeSwitch = true;
    while (!mainTape->isAtFileEnd()) {
        if (!cylinder->exists())
            break;

        if (lastCylinder != nullptr && *cylinder < *lastCylinder) {
            tapeSwitch = !tapeSwitch;
        }

        if (tapeSwitch) {
            tape1->add(cylinder->base, cylinder->height);
        } else {
            tape2->add(cylinder->base, cylinder->height);
        }
        lastCylinder->base = cylinder->base;
        lastCylinder->height = cylinder->height;

        cylinder = mainTape->next();
    }
    tape1->save();
    tape2->save();
    tape1->resetTape();
    tape2->resetTape();
    delete lastCylinder;
}

void sort(Tape *mainTape) {
    Tape *tape1 = new Tape(TAPE1_NAME);
    Tape *tape2 = new Tape(TAPE2_NAME);
    bool sorted = false;
    // while (!sorted) {
        distribute(mainTape, tape1, tape2);
        // sorted = merge(mainTape, tape1, tape2);
    // }
#ifdef DEBUG
    std::cout << "maintape: \n";
    mainTape->dumpFile();
    std::cout << "tape1: \n";
    tape1->dumpFile();
    std::cout << "tape2: \n";
    tape2->dumpFile();
#endif
    delete tape1;
    delete tape2;
}
} // namespace sorting
