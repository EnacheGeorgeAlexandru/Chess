#pragma once

#include "Piece.h"

namespace Chess::Pieces {
    class Knight : public Piece {
    public:
        explicit Knight(PieceColor colorP);

         std::list<Position> LegalMoves(const Board &, const Position &) const override;

         bool IsMoveLegal(const Board &, const Move &) const override;

        ~Knight() override = default;
    };
}

