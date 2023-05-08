#pragma once
#include <iostream>
#include "Position.h"

namespace Chess {

class Move {

    Position start;
    Position end;

public:
    explicit Move() = default;
    explicit Move(const Position&, const Position&);

    const Position& GetStart() const;
    const Position& GetEnd() const;

    void SetStart(int, int);
    void SetEnd(int, int);

    bool IsAdjacentMove() const;
};

}

