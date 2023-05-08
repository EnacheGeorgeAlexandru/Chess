#include "Move.h"
#include <cstdlib>

using namespace Chess;

Move::Move(const Position& startPosition, const Position& endPosition) {
    start = startPosition;
    end = endPosition;
}

const Position& Move::GetStart() const {
    return start;
}

const Position& Move::GetEnd() const {
    return end;
}

void Move::SetEnd(const int line, const int column) {
    end.SetX(line);
    end.SetY(column);
}

void Move::SetStart(const int line, const int column) {
    start.SetX(line);
    start.SetY(column);
}

bool Move::IsAdjacentMove() const {
    if (abs(start.GetX() - end.GetX()) > 1 ) {
            return false;
    }
    if (abs(start.GetY() - end.GetY()) > 1) {
            return false;
    }
    return true;
}

