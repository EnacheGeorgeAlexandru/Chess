#include "Bishop.h"
#include "../Board.h"

using namespace Chess::Pieces;

Bishop::Bishop(PieceColor colorP) : Piece(colorP) {}

std::list<Chess::Position> Bishop::LegalMoves(const Board& board, const Position& startSquare) const {
    std::list<Position> LegalMoves;
    int line = startSquare.GetX(), column = startSquare.GetY();
    for (line = startSquare.GetX() + 1; line < 8; ++line) {
        column++;
        if(board.ValidCoordinates(line, column))
            if (board.GetBoard()[line][column]->IsTileEmpty())


                LegalMoves.emplace_back(line, column);
            else {
                if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                    LegalMoves.emplace_back(line, column);
                break;
            }
    }
    column = startSquare.GetY();
    for (line = startSquare.GetX() - 1; line > - 1; --line) {
        column++;
        if (board.ValidCoordinates(line, column))
            if (board.GetBoard()[line][column]->IsTileEmpty())
                LegalMoves.emplace_back(line, column);
            else {
                if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                    LegalMoves.emplace_back(line, column);
                break;
            }
    }
    column = startSquare.GetY();
    for (line = startSquare.GetX() + 1; line < 8; ++line) {
        column--;
        if (board.ValidCoordinates(line, column))
            if (board.GetBoard()[line][column]->IsTileEmpty())
                LegalMoves.emplace_back(line, column);
            else {
                if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                    LegalMoves.emplace_back(line, column);
                break;
            }
    }
    column = startSquare.GetY();
    for (line = startSquare.GetX() - 1; line > -1; --line) {
        column--;
        if (board.ValidCoordinates(line, column))
            if (board.GetBoard()[line][column]->IsTileEmpty())
                LegalMoves.emplace_back(line, column);
            else {
                if (board.GetBoard()[line][column]->GetPiece()->GetPieceColor() != color)
                    LegalMoves.emplace_back(line, column);
                break;
            }
    }
    return LegalMoves;
}

bool Bishop::IsMoveLegal(const Board& board, const Move& move) const {
    std::list<Position> LegalMovesList = LegalMoves(board, move.GetStart());
    if (std::find(LegalMovesList.begin(), LegalMovesList.end(), move.GetEnd()) == LegalMovesList.end())
        return false;
    return true;
}
