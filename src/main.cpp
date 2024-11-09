#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include <iostream>

int main() {
    Cylinder cyl1;
    Cylinder cyl2;
    Cylinder cyl3;
    Cylinder cyl4;
    cyl1.base = 5;
    cyl2.base = 2;
    cyl3.base = 3;
    cyl4.base = 3;
    cyl1.height = 1;
    cyl2.height = 1;
    cyl3.height = 3;
    cyl4.height = 4;
    std::cout << (cyl1 > cyl2) << std::endl;
    Tape tape;
    tape.add(&cyl1);
#ifdef DEBUG
    tape.dump();
#endif
    return 0;
}
