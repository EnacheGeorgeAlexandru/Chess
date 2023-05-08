#include "King.h"
#include "../Board.h"

using namespace Chess::Pieces;

King::King(PieceColor colorP) :Piece(colorP) {}

std::list<Chess::Position> King::LegalMoves(const Chess::Board& board, const Position& startSquare) const {
    std::list<Position> LegalMoves;
    std::list<Position> pseudoLegalMoves;
    for (int column = startSquare.GetY() - 1; column < startSquare.GetY() + 2; ++column) {
        if (board.ValidCoordinates(startSquare.GetX() - 1, column)) {
            if (board.GetBoard()[startSquare.GetX() - 1][column]->IsTileEmpty())
                pseudoLegalMoves.push_back(Position(startSquare.GetX() - 1, column));
            else
                if(board.GetBoard()[startSquare.GetX() - 1][column]->GetPiece()->GetPieceColor() != color)
                    pseudoLegalMoves.push_back(Position(startSquare.GetX() - 1, column));
        }
        if (board.ValidCoordinates(startSquare.GetX(), column)) {
            if (board.GetBoard()[startSquare.GetX()][column]->IsTileEmpty())
                pseudoLegalMoves.push_back(Position(startSquare.GetX(), column));
            else
                if (board.GetBoard()[startSquare.GetX()][column]->GetPiece()->GetPieceColor() != color)
                    pseudoLegalMoves.push_back(Position(startSquare.GetX(), column));
        }
        if (board.ValidCoordinates(startSquare.GetX() + 1, column)) {
            if (board.GetBoard()[startSquare.GetX() + 1][column]->IsTileEmpty())
                pseudoLegalMoves.push_back(Position(startSquare.GetX() + 1, column));
            else
                if (board.GetBoard()[startSquare.GetX() + 1][column]->GetPiece()->GetPieceColor() != color)
                    pseudoLegalMoves.push_back(Position(startSquare.GetX() + 1, column));
        }
    }
    return pseudoLegalMoves;
}

bool King::IsMoveLegal(const Chess::Board& board, const Chess::Move& move) const {
    Tile& destination = *board.GetBoard()[move.GetEnd().GetX()][move.GetEnd().GetY()];
    if (!move.IsAdjacentMove())
    {
        return false;
    }
    if (!destination.IsTileEmpty())
    {
        if(destination.GetPiece()->GetPieceColor() == color)
        {
            return false;
        }
    }
    return true;
}
