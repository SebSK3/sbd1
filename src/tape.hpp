#pragma once

#include "consts.hpp"
#include "cylinder.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Tape {
  public:
    std::string name;

    Cylinder *getRecord(uint record);
    Cylinder *getCurrentRecord();
    Cylinder *next();
    void add(Cylinder *record);
    void save();
    bool load();
    void resetTape();
    void reset(bool shouldClearFile = false);
    bool dumpTapeHere(Tape *tape, Cylinder *lastRecord);

    void goToStart();
    bool isAtTapeEnd();
    bool isAtFileEnd();
#ifdef DEBUG
    void dump();
#endif

  private:
    std::fstream file;
    uint current_record = 0;
    uint current_page = 0;
    Cylinder *page[TAPE_SIZE];
    bool checkForFullPage();
    bool isFull();
};
