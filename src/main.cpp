#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include "sorting.hpp"
#include "helpers.hpp"
#include <iostream>

uint RECORD_COUNT;

int main() {
    helpers::clearFiles();
    RECORD_COUNT = 5;
    Tape *mainTape = new Tape(TAPE_NAME);
    mainTape->load();

    sorting::sort(mainTape);
    delete mainTape;
    // mainTape.load();

#ifdef DEBUG
    // tape.dump();
    // sorting::sort(tape);
    // std::cout << "sorted:\n";
    // tape.dump();
#endif
    return 0;
}
