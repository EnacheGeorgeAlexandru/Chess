#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "../Util.h"
#include "../Position.h"

namespace Chess {
class Board;
class Move;
namespace Pieces {
class Piece {
protected:
    PieceColor color;
public:
    explicit Piece(PieceColor color);

     PieceColor GetPieceColor() const;

     virtual std::list<Position> LegalMoves(const Board&, const Position&) const = 0;

     virtual bool IsMoveLegal(const Board&, const Move&) const = 0;

    virtual ~Piece()= default;
};
}
}
