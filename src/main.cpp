#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include <iostream>

int main() {
    Cylinder cyl1;
    Cylinder cyl2;
    cyl1.base = 5;
    cyl2.base = 2;
    cyl1.height = 1;
    cyl2.height = 1;
    std::cout << (cyl1 > cyl2) << std::endl;
    Tape tape;
    tape.add(&cyl1);
    return 0;
}
