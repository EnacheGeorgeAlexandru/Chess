#include "Position.h"

using namespace Chess;

Position::Position() {
    x = 0;
    y = 0;
}
Position::Position(const int line, const int column) {
    x = line;
    y = column;
}

Position::Position(const Position& object) {
    x = object.x;
    y = object.y;
}

Position& Position::operator=(const Position& object) {
    if (this != &object) {
        x = object.x;
        y = object.y;
    }
    return *this;
}

bool Position::operator==(const Position& ob) const {
    return (x == ob.x and y == ob.y);
}

int Position::GetX() const {
    return x;
}

int Position::GetY() const {
    return y;
}

void Position::SetX(int line) {
    x = (int8_t)line;
}

void Position::SetY(int column) {
    y = (int8_t)column;
}



