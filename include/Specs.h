#ifndef SPECS_H
#define SPECS_H
#include <vector>
#include <numeric>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

#include "utils.h"


class Specs{

    std::vector<int> widths;
    std::vector<int> heigths;

    public:

    int getMaxWidth() const;
    int getMaxHeight() const;
    int getAvgWidth() const;
    int getAvgHeight() const;

    std::tuple<int, int> parseFromFile(const std::string file_path);

};

#endif /*SPECS_H*/