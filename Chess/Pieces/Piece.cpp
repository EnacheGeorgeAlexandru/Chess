#include "Piece.h"

using namespace Chess;
using namespace Chess::Pieces;

Piece::Piece(PieceColor color) : color{color}{}

PieceColor Piece::GetPieceColor() const {
    return color;
}
