#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include "sorting.hpp"
#include <iostream>

int main() {
    Cylinder cyl1;
    Cylinder cyl2;
    Cylinder cyl3;
    Cylinder cyl4;
    Cylinder cyl5;
    cyl1.base = 5;
    cyl2.base = 2;
    cyl3.base = 3;
    cyl4.base = 3;
    cyl1.height = 1;
    cyl2.height = 1;
    cyl3.height = 3;
    cyl4.height = 4;
    cyl5.height = 2;
    cyl5.base = 1;
    std::cout << (cyl1 > cyl2) << std::endl;
    Tape tape;
    tape.resetTape();
    tape.add(&cyl1);
    tape.add(&cyl2);
    tape.add(&cyl3);
    tape.add(&cyl4);
    tape.add(&cyl5);
    Tape tape1;
    tape1.resetTape();
    Tape tape2;
    tape2.resetTape();
    sorting::distribute(tape, tape1, tape2);
#ifdef DEBUG
    tape.dump();
    std::cout << "tape1:\n";
    tape1.dump();
    std::cout << "tape2:\n";
    tape2.dump();

    std::cout << "merged:\n";
    sorting::merge(tape, tape1, tape2);
    tape.dump();
#endif
    return 0;
}
