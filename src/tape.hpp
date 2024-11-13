#pragma once

#include "consts.hpp"
#include "cylinder.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Tape {
  public:
    Tape(std::string name);
    ~Tape();
    std::string name;

    Cylinder *getCurrentRecord();
    Cylinder *next();
    void add(int base, int height);
    void save();
    bool load();
    void resetFile();
    void resetTape();
    void resetPage();
    bool dumpRestOfTapeHere(Tape *tape, Cylinder *lastRecord);

    void goToStart();
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
