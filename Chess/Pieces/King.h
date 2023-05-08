#pragma once

#include "Piece.h"

namespace Chess::Pieces {
    class King : public Piece {
    public:
        explicit King(PieceColor colorP);

         std::list<Position> LegalMoves(const Board &, const Position &) const override;

         bool IsMoveLegal(const Board &, const Move &) const override;

        ~King() override = default;
    };
}

