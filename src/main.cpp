#include "consts.hpp"
#include "cylinder.hpp"
#include "tape.hpp"
#include "sorting.hpp"
#include "helpers.hpp"
#include <iostream>

uint RECORD_COUNT;

int main() {
    helpers::clearFiles();
    Tape *mainTape = new Tape(TAPE_NAME);
    mainTape->load();
    mainTape->dump();
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
