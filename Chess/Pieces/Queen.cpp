#include "Queen.h"
#include "../Board.h"

using namespace Chess::Pieces;

Queen::Queen(PieceColor colorP) : Piece(colorP) {}

std::list<Chess::Position> Queen::LegalMoves(const Chess::Board& board, const Position& startSquare) const {
    std::list<Position> LegalMoves;
    Rook rook(color);
    Bishop bishop(color);
    for (const auto& it : rook.LegalMoves(board, startSquare))
        LegalMoves.push_back(it);
    for (const auto& it : bishop.LegalMoves(board, startSquare))
        LegalMoves.push_back(it);
    return LegalMoves;
}

bool Queen::IsMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
    std::list<Position> LegalMovesList = LegalMoves(board, move.GetStart());
    if (std::find(LegalMovesList.begin(), LegalMovesList.end(), move.GetEnd()) == LegalMovesList.end())
        return false;
    return true;
}
