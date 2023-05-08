#include "Pawn.h"
#include "../Board.h"

using namespace Chess::Pieces;

Pawn::Pawn(PieceColor colorP) : Piece(colorP) {}

std::list<Chess::Position> Pawn::LegalMoves(const Board& board, const Position& startSquare) const{
    std::list<Position> LegalMoves;
    if (color == PieceColor::eWhite) {
        if (board.GetBoard()[startSquare.GetX() - 1][startSquare.GetY()]->IsTileEmpty()) {
            LegalMoves.push_back(Position(startSquare.GetX() - 1, startSquare.GetY()));
            if(startSquare.GetX() == 6 && board.GetBoard()[startSquare.GetX() - 2][startSquare.GetY()]->IsTileEmpty())
                LegalMoves.push_back(Position(startSquare.GetX() - 2, startSquare.GetY()));
        }
        if(startSquare.GetY() - 1 > -1)
            if(board.GetBoard()[startSquare.GetX() - 1][startSquare.GetY() - 1]->IsTileEmpty() == 0)
                if (board.GetBoard()[startSquare.GetX() - 1][startSquare.GetY() - 1]->GetPiece()->GetPieceColor() == PieceColor::eBlack)
                    LegalMoves.push_back(Position(startSquare.GetX() - 1, startSquare.GetY() - 1));
        if(startSquare.GetY() + 1 < 8)
            if (board.GetBoard()[startSquare.GetX() - 1][startSquare.GetY() + 1]->IsTileEmpty() == 0)
                if (board.GetBoard()[startSquare.GetX() - 1][startSquare.GetY() + 1]->GetPiece()->GetPieceColor() == PieceColor::eBlack)
                    LegalMoves.push_back(Position(startSquare.GetX() - 1, startSquare.GetY() + 1));
    }

    if (color == PieceColor::eBlack) {
        if (board.GetBoard()[startSquare.GetX() + 1][startSquare.GetY()]->IsTileEmpty()) {
            LegalMoves.push_back(Position(startSquare.GetX() + 1, startSquare.GetY()));
            if(startSquare.GetX() == 1 && board.GetBoard()[startSquare.GetX() + 2][startSquare.GetY()]->IsTileEmpty())
                LegalMoves.push_back(Position(startSquare.GetX() + 2, startSquare.GetY()));
        }
        if (startSquare.GetY() - 1 > -1)
            if (board.GetBoard()[startSquare.GetX() + 1][startSquare.GetY() - 1]->IsTileEmpty() == 0)
                if (board.GetBoard()[startSquare.GetX() + 1][startSquare.GetY() - 1]->GetPiece()->GetPieceColor() == PieceColor::eWhite)
                    LegalMoves.push_back(Position(startSquare.GetX() + 1, startSquare.GetY() - 1));
        if (startSquare.GetY() + 1 < 8)
            if (board.GetBoard()[startSquare.GetX() + 1][startSquare.GetY() + 1]->IsTileEmpty() == 0)
                if (board.GetBoard()[startSquare.GetX() + 1][startSquare.GetY() + 1]->GetPiece()->GetPieceColor() == PieceColor::eWhite)
                    LegalMoves.push_back(Position(startSquare.GetX() + 1, startSquare.GetY() + 1));
    }
    return LegalMoves;
}

bool Pawn::IsMoveLegal(const Board& board, const Move& move) const {
    std::list<Position> LegalMovesList = LegalMoves(board, move.GetStart());
    if (std::find(LegalMovesList.begin(), LegalMovesList.end(), move.GetEnd()) == LegalMovesList.end())
        return false;
    return true;
}
