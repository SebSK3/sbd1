#include "tape.hpp"

void Tape::add(Cylinder *record) {
    checkForFullPage();
    page[current_record] = record;
    current_record++;
}

bool Tape::isFull() { return current_record >= TAPE_SIZE; }

void Tape::resetTape() {
    save();
    current_record = 0;
    current_page = 0;
    for (uint i = 0; i < TAPE_SIZE; i++) {
        page[i] = nullptr;
    }
    load();
}

void Tape::reset() {
    current_record = 0;
    current_page = 0;
    for (uint i = 0; i < TAPE_SIZE; i++) {
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
    file.open(name, std::ios::out);
    file.seekg(current_page * PAGE_SIZE);
    for (int i = 0; i < TAPE_SIZE; i++) {
        if (page[i] != nullptr) {
            std::cout << Helpers::serialize(page[i]->base, BASE_LENGTH) << std::endl;
            file.write(std::to_string(page[i]->base).c_str(), BASE_LENGTH);
            file.write(std::to_string(page[i]->height).c_str(), HEIGHT_LENGTH);
        }
    }
    file.close();
}

void Tape::load() {
    file.open(name, std::ios::in);
    file.seekg(current_page * PAGE_SIZE);
    char bytes[PAGE_SIZE];
    file.read(bytes, PAGE_SIZE);
    auto readBytes = file.gcount();
    std::string builder;
    bool isBase = true;
    current_record = 0;

    Cylinder *cyl = new Cylinder;
    auto readRecords = std::min(PAGE_SIZE, readBytes);
    for (int i = 1; i < readRecords; i++) {
        builder += bytes[i - 1];
        if (i % BASE_LENGTH == 0 && isBase) {
            cyl->base = std::stoi(builder);
            builder = "";
            isBase = false;
        } else if (i % HEIGHT_LENGTH == 0 && !isBase) {
            cyl->height = std::stoi(builder);
            builder = "";
            isBase = true;
            add(cyl);
            cyl = new Cylinder;
        }
    }

    current_record = 0;
    std::cout << std::endl;
    file.close();
}

#ifdef DEBUG
void Tape::dump() {
    for (int i = 0; i < TAPE_SIZE; i++) {
        if (page[i] != nullptr)
            std::cout << *page[i] << std::endl;
        else {
            std::cout << "nullptr" << std::endl;
        }
    }
}
#endif

bool Tape::isAtTapeEnd() {
    return current_record >= TAPE_SIZE || page[current_record] == nullptr;
}

bool Tape::isAtFileEnd() { return false; }
void Tape::goToStart() { current_record = 0; }

bool Tape::dumpTapeHere(Tape *tape, Cylinder *lastRecord) {
    bool sorted = true;
    while (!tape->isAtTapeEnd()) {
        Cylinder *record = tape->getCurrentRecord();
        if (lastRecord != nullptr && *record < *lastRecord)
            sorted = false;
        lastRecord = record;
        add(record);
        tape->next();
    }
    return sorted;
}
// void Tape::getNextRecord() {

//     std::fstream file("pliczek.txt", std::ios::read);
//     file.read(5, 10);
// }
