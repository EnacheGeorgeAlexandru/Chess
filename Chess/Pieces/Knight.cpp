#include "Knight.h"
#include "../Board.h"

using namespace Chess::Pieces;

Knight::Knight(PieceColor colorP) : Piece(colorP) {}

std::list<Chess::Position> Knight::LegalMoves(const Chess::Board& board, const Position& startSquare) const {
    std::list<Position> LegalMoves;
    std::list<Position> potentialMoves;
    int i = startSquare.GetX(), j = startSquare.GetY();
    potentialMoves.push_back(Position (i - 1, j + 2));
    potentialMoves.push_back(Position(i - 1, j - 2));
    potentialMoves.push_back(Position(i + 1, j + 2));
    potentialMoves.push_back(Position(i + 1, j - 2));
    potentialMoves.push_back(Position(i - 2, j + 1));
    potentialMoves.push_back(Position(i - 2, j - 1));
    potentialMoves.push_back(Position(i + 2, j + 1));
    potentialMoves.push_back(Position(i + 2, j - 1));
    for (auto move : potentialMoves)
        if (board.ValidCoordinates(move.GetX(), move.GetY()))
            if (board.GetBoard()[move.GetX()][move.GetY()]->IsTileEmpty())
                LegalMoves.push_back(move);
            else
                if (board.GetBoard()[move.GetX()][move.GetY()]->GetPiece()->GetPieceColor() != color)
                    LegalMoves.push_back(move);
    return LegalMoves;
}

bool Knight::IsMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
    std::list<Position> LegalMovesList = LegalMoves(board, move.GetStart());
    if (std::find(LegalMovesList.begin(), LegalMovesList.end(), move.GetEnd()) == LegalMovesList.end())
        return false;
    return true;
}
