#pragma once

#include "consts.hpp"
#include "cylinder.hpp"
#include <fstream>
#include <string>
#include <vector>

class Tape {
  public:
    std::string name;

    Cylinder *getRecord(uint record);
    Cylinder* next();
    void add(Cylinder *record);

  private:
    std::fstream file;
    uint current_record;
    Cylinder* page[RECORD_COUNT];
    void save();
    void load();
    bool checkForFullPage();
    void resetPage();
    bool isFull();
};
