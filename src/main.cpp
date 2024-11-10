#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include "sorting.hpp"
#include "helpers.hpp"
#include <iostream>

uint RECORD_COUNT;

int main() {
    helpers::clearFiles();
    RECORD_COUNT = 4;
    Tape tape;
    tape.name = TAPE_NAME;
    tape.load();
    sorting::sort(tape);
#ifdef DEBUG
    tape.dump();
    // sorting::sort(tape);
    // std::cout << "sorted:\n";
    // tape.dump();
#endif
    return 0;
}
