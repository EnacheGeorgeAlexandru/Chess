#include "Tile.h"

using namespace Chess;

Tile::Tile(Pieces::Piece* pieceP) {
    piece = pieceP;
}

Tile::Tile(const Tile& object) {
    piece = object.piece;
    position = object.position;
}

Tile& Tile::operator=(const Tile& object) {
    if (this != & object) {
        piece = object.piece;
        position = object.position;
    }
    return *this;
}

void Tile::SetPiece(Pieces::Piece* pieceP) {
    piece = pieceP;
}

Pieces::Piece* Tile::GetPiece() const {
    return piece;
}

bool Tile::IsTileEmpty() const {
    return nullptr == piece;
}

Position Tile::GetPosition() const {
    return position;
}

void Tile::SetPosition(const Position& positionP) {
    position = positionP;
}

Tile::~Tile() {
    delete piece;
}