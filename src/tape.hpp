#pragma once

#include "consts.hpp"
#include "cylinder.hpp"
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
    void load();
    void resetTape();
    void dumpTapeHere(Tape *tape);

    void goToStart();
    bool isAtEnd();
#ifdef DEBUG
    void dump();
#endif

  private:
    std::fstream file;
    uint current_record;
    Cylinder *page[RECORD_COUNT];
    bool checkForFullPage();
    bool isFull();
};
