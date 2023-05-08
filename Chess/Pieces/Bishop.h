#pragma once

#include "Piece.h"

namespace Chess::Pieces {

    class Bishop : public Piece {
    public:
        explicit Bishop(PieceColor colorP);

         std::list<Position> LegalMoves(const Board &, const Position &) const override;

         bool IsMoveLegal(const Board &, const Move &) const override;

        ~Bishop() override= default;
    };

}


