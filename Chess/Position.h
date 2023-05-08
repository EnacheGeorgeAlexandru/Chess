#pragma once
#include <iostream>

namespace Chess {

class Position {

    int8_t x;
    int8_t y;

public:
    explicit Position();

    explicit Position(int, int);

    Position(const Position&);

    Position& operator=(const Position&);

    bool operator==(const Position&) const;

    int GetX() const;

    int GetY() const;

    void SetX(int);

    void SetY(int);

    ~Position() = default;
};

}

