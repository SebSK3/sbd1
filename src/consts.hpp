#pragma once
#include <string>

const double PI = 3.14159265;

// Settings for storing records
const uint BASE_LENGTH = 4;
const uint HEIGHT_LENGTH = 4;

const uint RECORD_SIZE = BASE_LENGTH + HEIGHT_LENGTH;
const uint RECORD_COUNT = 4;

// For this to work, PAGE_SIZE needs to be at least the size of RECORD_SIZE
const uint PAGE_SIZE = RECORD_SIZE * 1;

const std::string TAPE_NAME = "Main_Tape.txt";
const std::string TAPE1_NAME = "First_Tape.txt";
const std::string TAPE2_NAME = "Second_Tape.txt";

// std::string serialize() {
//     return (std::string)base + (std::string)height;
// }

// Cylinder deserialize(std::string serialized) {
//     Cylinder cyl;
//     std::string builder1;
//     for (int i=0; i<BASE_LENGTH; i++) {
//         builder1 += serialized[i];
//     }
//     cyl.base = stoi(builder1);
//     for (int i=BASE_LENGTH; i<HEIGHT_LENGTH; i++) {
//         builder1 += serialized[i];
//     }
//     cyl.height = stoi(builder1);
// }
