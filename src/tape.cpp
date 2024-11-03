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

Cylinder *Tape::getRecord() {
    return page[current_record];
}

Cylinder *Tape::next() {
    current_record++;
    checkForFullPage();
    return page[current_record];
}

void Tape::checkForFullPage() {
    if (isFull()) {
        save();
        resetPage();
    }
}
void Tape::save() {}
