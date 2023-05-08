#pragma once
#include "Piece.h"

namespace Chess::Pieces {

class Queen : public Piece {
public:
    explicit Queen(PieceColor colorP);

     std::list<Position> LegalMoves(const Board&, const Position&) const override;

     bool IsMoveLegal(const Board&, const Move&) const override;

    ~Queen() override= default;
};
}
