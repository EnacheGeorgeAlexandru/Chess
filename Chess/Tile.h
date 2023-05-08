#pragma once
#include "Pieces/Piece.h"

namespace Chess {

class Tile {

    Pieces::Piece* piece;
    Position position;

public:
    explicit Tile(Pieces::Piece* = nullptr);
    Tile(const Tile&);
    Tile& operator=(const Tile&);

    void SetPiece(Pieces::Piece* );
    Pieces::Piece* GetPiece() const;

    Position GetPosition()const;
    void SetPosition(const Position&);

    bool IsTileEmpty() const;

    ~Tile();
};

}
