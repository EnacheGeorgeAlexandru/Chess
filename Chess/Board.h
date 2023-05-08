#pragma once
#include <windows.h>
#include "Tile.h"
#include "Move.h"
#include "Player.h"
#include "Pieces/Pawn.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Rook.h"
#include "Pieces/Queen.h"
#include "Pieces/King.h"


namespace Chess {

class Player;

class Board {

    std::vector<std::vector<Tile*>> board;
    Position whiteKingPosition;
    Position blackKingPosition;
    std::vector<Move*> whiteLegalMoves;
    std::vector<Move*> blackLegalMoves;

public:

    Board();

    Tile* GetTileFromCoordinates(const Position&) const;

    Pieces::Piece* GetPieceFromCoordinates(const Position&) const;

    std::vector<std::vector<Tile*>> GetBoard() const;

    bool ValidCoordinates(const int&, const int&) const;

    bool IsCheckOnSquare(const Position&, PieceColor color) const;

    bool IsKingInCheck(PieceColor color) const;

    void UpdateKingPosition(const Move&, PieceColor color);

    void TakeMoveBack(const Move&, Pieces::Piece*);

    bool IsCheckmate();

    bool TakeNextMove(const Player&);

    bool MakeMoveIfLegal(const Move&, PieceColor);

    void SetWhiteLegalMoves();

    void SetBlackLegalMoves();

    ~Board();
};

}
