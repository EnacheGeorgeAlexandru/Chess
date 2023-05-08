#pragma once
#include "Util.h"
#include "Move.h"

namespace Chess {

class Player {

    PieceColor color;
    Move* currentMove;

public:
    explicit Player(PieceColor color);

    const PieceColor& GetColor() const;

    void SetCurrentMove(const std::string&, const std::string&);

    const Move& GetCurrentMove() const;

    ~Player();
};

}

