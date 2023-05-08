#pragma once
#include "Piece.h"

namespace Chess::Pieces {
class Pawn : public Piece {
public:
    explicit Pawn(PieceColor colorP);

     std::list<Position> LegalMoves(const Board&, const Position&) const override;

     bool IsMoveLegal(const Board&, const Move&) const override;

    ~Pawn() override= default;
};
}
