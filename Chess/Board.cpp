#include "Board.h"

using namespace Chess;
using namespace Chess::Pieces;

Board::Board() {
    board.resize(8, std::vector<Tile*>(8));
    for(int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) {
            board[i][j] = new Tile;
            board[i][j]->SetPosition(Position(i, j));
        }
    for (auto& i : board[1])
        i->SetPiece(new Pawn(PieceColor::eBlack));
    board[0][0]->SetPiece(new Rook(PieceColor::eBlack));
    board[0][7]->SetPiece(new Rook(PieceColor::eBlack));
    board[0][1]->SetPiece(new Knight(PieceColor::eBlack));
    board[0][6]->SetPiece(new Knight(PieceColor::eBlack));
    board[0][2]->SetPiece(new Bishop(PieceColor::eBlack));
    board[0][5]->SetPiece(new Bishop(PieceColor::eBlack));
    board[0][3]->SetPiece(new Queen(PieceColor::eBlack));
    board[0][4]->SetPiece(new King(PieceColor::eBlack));
    blackKingPosition = Position(0, 4);

    for (auto& i : board[6])
        i->SetPiece(new Pawn(PieceColor::eWhite));
    board[7][0]->SetPiece(new Rook(PieceColor::eWhite));
    board[7][7]->SetPiece(new Rook(PieceColor::eWhite));
    board[7][1]->SetPiece(new Knight(PieceColor::eWhite));
    board[7][6]->SetPiece(new Knight(PieceColor::eWhite));
    board[7][2]->SetPiece(new Bishop(PieceColor::eWhite));
    board[7][5]->SetPiece(new Bishop(PieceColor::eWhite));
    board[7][3]->SetPiece(new Queen(PieceColor::eWhite));
    board[7][4]->SetPiece(new King(PieceColor::eWhite));
    whiteKingPosition = Position(7, 4);
}

Tile* Board::GetTileFromCoordinates(const Position& square) const {
    return board[square.GetX()][square.GetY()];
}

Piece* Board::GetPieceFromCoordinates(const Position& square) const {
    return board[square.GetX()][square.GetY()]->GetPiece();
}

std::vector<std::vector<Tile*>> Board::GetBoard() const {
    return board;
}

bool Board::ValidCoordinates(const int& line, const int& column) const {
    if (line < 0 || column < 0)
        return false;
    if (line > 7 || column > 7)
        return false;
    return true;
}

bool Board::IsCheckOnSquare(const Position& square, PieceColor color) const {
    std::vector <Position> opposideSideLegalSquares;
    if (color == PieceColor::eWhite)
        for (const auto& move : blackLegalMoves)
            opposideSideLegalSquares.push_back(move->GetEnd());
    if (color == PieceColor::eBlack)
        for (const auto& move : whiteLegalMoves)
            opposideSideLegalSquares.push_back(move->GetEnd());
    auto found = std::find(opposideSideLegalSquares.begin(), opposideSideLegalSquares.end(), square);
    if (found != opposideSideLegalSquares.end())
        return true;
    return false;
}

bool Board::IsKingInCheck(PieceColor color) const {
    if (color == PieceColor::eWhite)
        return IsCheckOnSquare(whiteKingPosition, color);
    else if (color == PieceColor::eBlack)
        return IsCheckOnSquare(blackKingPosition, color);
    return false;
}

void Board::UpdateKingPosition(const Move& move, PieceColor color) {
    if (color == PieceColor::eWhite && move.GetStart() == whiteKingPosition)
        whiteKingPosition = move.GetEnd();
    if (color == PieceColor::eBlack && move.GetStart() == blackKingPosition)
        blackKingPosition = move.GetEnd();
}

void Board::TakeMoveBack(const Move& move, Piece* onEndTile) {
    Tile* startTile = GetTileFromCoordinates(move.GetStart());
    Tile* endTile = GetTileFromCoordinates(move.GetEnd());
    Piece* pieceMoved = GetPieceFromCoordinates(move.GetEnd());
    startTile->SetPiece(pieceMoved);
    endTile->SetPiece(onEndTile);
    if (whiteKingPosition == move.GetEnd())
        whiteKingPosition = move.GetStart();
    if (blackKingPosition == move.GetEnd())
        blackKingPosition = move.GetStart();
}

bool Board::IsCheckmate() {
    SetWhiteLegalMoves();
    SetBlackLegalMoves();
    Position kingPosition = whiteKingPosition;
    std::vector<Move*> LegalMoves = whiteLegalMoves;
    bool checkmate = 0;
    if (IsKingInCheck(PieceColor::eWhite)) {
        checkmate = 1;
        for (const auto& move : LegalMoves) {
            Piece* onEndTile = GetPieceFromCoordinates(move->GetEnd());
            MakeMoveIfLegal(*move, PieceColor::eWhite);
            SetBlackLegalMoves();
            if (!IsKingInCheck(PieceColor::eWhite)) {
                checkmate = 0;
                TakeMoveBack(*move, onEndTile);
                break;
            }
            TakeMoveBack(*move, onEndTile);
        }
    }
    kingPosition = blackKingPosition;
    SetBlackLegalMoves();
    LegalMoves = blackLegalMoves;
    if (IsKingInCheck(PieceColor::eBlack)) {
        checkmate = 1;
        for (const auto& move : LegalMoves) {
            Piece* onEndTile = GetPieceFromCoordinates(move->GetEnd());
            MakeMoveIfLegal(*move, PieceColor::eBlack);
            SetWhiteLegalMoves();
            if (!IsKingInCheck(PieceColor::eBlack)) {
                checkmate = 0;
                TakeMoveBack(*move, onEndTile);
                break;
            }
            TakeMoveBack(*move, onEndTile);
        }
    }
    return checkmate;
}

bool Board::TakeNextMove(const Player& player) {
    const PieceColor& color = player.GetColor();
    const Move& move = player.GetCurrentMove();
    const Position& endPosition = move.GetEnd();
    const Tile& endTile = *board[endPosition.GetX()][endPosition.GetY()];

    Piece* onEndTile = GetPieceFromCoordinates(move.GetEnd());
    bool madeMove = MakeMoveIfLegal(move, color);
    if (color == PieceColor::eWhite)
        SetBlackLegalMoves();
    if (color == PieceColor::eBlack)
        SetWhiteLegalMoves();
    if (madeMove && IsKingInCheck(color)) {
        TakeMoveBack(move, onEndTile);
        madeMove = 0;
    }

    return madeMove;
}

bool Board::MakeMoveIfLegal(const Move& move,PieceColor color) {
    Piece* pieceToMove = GetPieceFromCoordinates(move.GetStart());
    if(pieceToMove && pieceToMove->GetPieceColor() == color)
        if (pieceToMove->IsMoveLegal(*this, move)) {
            Tile* startTile = GetTileFromCoordinates(move.GetStart());
            Tile* endTile = GetTileFromCoordinates(move.GetEnd());
            endTile->SetPiece(pieceToMove);
            startTile->SetPiece(nullptr);
            UpdateKingPosition(move, color);
            return true;
        }
    return false;
}

void Board::SetWhiteLegalMoves() {
    for (auto& move : whiteLegalMoves)
        delete move;
    whiteLegalMoves.clear();
    for(const auto& line : board)
        for(const auto& tile : line)
            if (tile->GetPiece() != nullptr && tile->GetPiece()->GetPieceColor() == PieceColor::eWhite)
                for (const auto& legalSquare : tile->GetPiece()->LegalMoves(*this, tile->GetPosition())) {
                    Move* move = new Move(tile->GetPosition(), legalSquare);
                    whiteLegalMoves.push_back(move);
                }
}

void Board::SetBlackLegalMoves() {
    for (auto& move : blackLegalMoves)
        delete move;
    blackLegalMoves.clear();
    for (const auto& line : board)
        for (const auto& tile : line)
            if (tile->GetPiece() != nullptr && tile->GetPiece()->GetPieceColor() == PieceColor::eBlack)
                for (const auto& legalSquare : tile->GetPiece()->LegalMoves(*this, tile->GetPosition())) {
                    Move* move = new Move(tile->GetPosition(), legalSquare);
                    blackLegalMoves.push_back(move);
                }
}

Board::~Board() {
    for (auto& move : whiteLegalMoves)
        delete move;
    for (auto& move : blackLegalMoves)
        delete move;
    for (auto& line : board)
        for (auto& tile : line)
            delete tile;
}
