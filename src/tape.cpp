#include "tape.hpp"

void Tape::add(Cylinder *record) {
    checkForFullPage();
    page[current_record] = record;
    current_record++;
}

bool Tape::isFull() { return current_record >= RECORD_COUNT; }

void Tape::resetPage() {
    current_record = 0;
    for (uint i = 0; i < RECORD_COUNT; i++) {
        page[i] = nullptr;
    }
}

Cylinder *Tape::getRecord(uint record) { return page[record]; }


Cylinder *Tape::next() {
    current_record++;
    if (checkForFullPage())
        return nullptr;
    return page[current_record];
}

bool Tape::checkForFullPage() {
    if (isFull()) {
        save();
        resetPage();
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
