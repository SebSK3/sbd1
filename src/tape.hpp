#pragma once

#include "consts.hpp"
#include "cylinder.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Tape {
  public:
    Tape(std::string name);
    ~Tape();
    std::string name;

    Cylinder *getRecord(uint record);
    Cylinder *getCurrentRecord();
    Cylinder *next();
    void add(int base, int height);
    void save();
    bool load();
    void nullTape();
    void resetTape();
    void resetPage();
    void freeTape();
    void reset(bool shouldClearFile = false);
    bool dumpRestOfTapeHere(Tape *tape, Cylinder *lastRecord);

    void goToStart();
    bool isAtTapeEnd();
    bool isAtFileEnd();
#ifdef DEBUG
    void dump();
    void dumpFile();
    void dumpToFile();
#endif

  private:
    std::fstream file;
    uint current_record = 0;
    uint current_page = 0;
    Cylinder *page[TAPE_SIZE];
    bool fullPageHandler(bool shouldSave = false);
    bool isFull();
};
