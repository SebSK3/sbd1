#pragma once

#include <fstream>

namespace helpers {
    void clearFiles() {
        std::fstream file;
        file.open(TAPE1_NAME, std::ios::out);
        file.write("", 0);
        file.close();
        file.open(TAPE2_NAME, std::ios::out);
        file.write("", 0);
        file.close();
    }
};
