#include "tape.hpp"

void Tape::add(Cylinder *record) {
    checkForFullPage();
    page[current_record] = record;
    current_record++;
}

bool Tape::isFull() { return current_record >= RECORD_COUNT; }

void Tape::resetTape() {
    current_record = 0;
    for (uint i = 0; i < RECORD_COUNT; i++) {
        page[i] = nullptr;
    }
}

Cylinder *Tape::getRecord(uint record) { return page[record]; }

Cylinder *Tape::getCurrentRecord() { return page[current_record]; }

Cylinder *Tape::next() {
    current_record++;
    if (checkForFullPage())
        return nullptr;
    return page[current_record];
}

bool Tape::checkForFullPage() {
    if (isFull()) {
        save();
        resetTape();
        return true;
    }
    return false;
}

void Tape::save() {
    for (int i = 0; i < RECORD_COUNT; i++) {
    }
}

#ifdef DEBUG
void Tape::dump() {
    for (int i = 0; i < RECORD_COUNT; i++) {
        if (page[i] != nullptr)
            std::cout << *page[i] << std::endl;
        else {
            std::cout << "nullptr" << std::endl;
        }
    }
}
#endif

bool Tape::isAtEnd() {
    return current_record >= PAGE_SIZE || page[current_record] == nullptr;
}
void Tape::goToStart() {
    current_record = 0;
}

void Tape::dumpTapeHere(Tape *tape) {
    while (!tape->isAtEnd()) {
        add(tape->getCurrentRecord());
        tape->next();
    }
}
// void Tape::getNextRecord() {

//     std::fstream file("pliczek.txt", std::ios::read);
//     file.read(5, 10);
// }
