#include "Rook.h"
#include "../Board.h"

using namespace Chess::Pieces;

Rook::Rook(PieceColor colorP) : Piece(colorP) {}

std::list<Chess::Position> Rook::LegalMoves(const Chess::Board& board, const Position& startSquare) const {
    std::list<Position> LegalMoves;
    int line, column = startSquare.GetY();
    for (line = startSquare.GetX() + 1; line < 8; ++line)
        if (board.GetBoard()[line][column]->IsTileEmpty())
            LegalMoves.push_back(Position(line, column));
        else {
            if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                LegalMoves.push_back(Position(line, column));
            break;
        }
    for (line = startSquare.GetX() - 1; line > -1; --line)
        if (board.GetBoard()[line][column]->IsTileEmpty())
            LegalMoves.push_back(Position(line, column));
        else {
            if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                LegalMoves.push_back(Position(line, column));
            break;
        }
    line = startSquare.GetX();
    for (column = startSquare.GetY() + 1; column < 8; ++column)
        if (board.GetBoard()[line][column]->IsTileEmpty())
            LegalMoves.push_back(Position(line, column));
        else {
            if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                LegalMoves.push_back(Position(line, column));
            break;
        }
    for (column = startSquare.GetY() - 1; column > -1; --column)
        if (board.GetBoard()[line][column]->IsTileEmpty())
            LegalMoves.push_back(Position(line, column));
        else {
            if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                LegalMoves.push_back(Position(line, column));
            break;
        }
    return LegalMoves;
}

bool Rook::IsMoveLegal( const Chess::Board& board, const Chess::Move& move) const {
    std::list<Position> LegalMovesList = LegalMoves(board, move.GetStart());
    if (std::find(LegalMovesList.begin(), LegalMovesList.end(), move.GetEnd()) == LegalMovesList.end())
        return false;
    return true;
}
