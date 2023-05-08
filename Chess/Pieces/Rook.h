#pragma once
#include "Piece.h"

namespace Chess::Pieces {
class Rook : public Piece {
public:
    explicit Rook(PieceColor colorP);

     std::list<Position> LegalMoves(const Board&, const Position&) const override;

     bool IsMoveLegal(const Board&, const Move&) const override;

    ~Rook() override= default;
};
}
