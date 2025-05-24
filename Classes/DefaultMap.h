#ifndef DEFAULTMAP_H
#define DEFAULTMAP_H
#pragma once
#include <vector>


class DefaultMap {
    inline std::vector<std::vector<int>> defaultTileIndices = {
        {6, 6, 6, 6, 6, 9, 9, 9, 9, 9},
        {6, 8, 8, 8, 6, 0, 0, 0, 9, 9},
        {6, 8, 9, 8, 6, 0, 12, 0, 9, 9},
        {6, 8, 8, 8, 6, 0, 0, 0, 9, 9},
        {6, 6, 6, 6, 6, 0, 0, 0, 9, 9},
        {9, 9, 9, 9, 9, 0, 0, 0, 9, 9},
        {9, 0, 0, 0, 0, 0, 0, 0, 9, 9},
        {9, 0, 0, 0, 0, 0, 0, 0, 9, 9},
    };
};



#endif //DEFAULTMAP_H
