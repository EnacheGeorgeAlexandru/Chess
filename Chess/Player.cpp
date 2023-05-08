#include "Player.h"

using namespace Chess;

Player::Player(PieceColor color) {
    this->color = color;
    currentMove = new Move;
}

const PieceColor& Player::GetColor() const {
    return color;
}

void Player::SetCurrentMove(const std::string& startTileName, const std::string& endTileName) {
    int startLine, startColumn, endLine, endColumn;

    startLine = 8 - (startTileName[1] - '0');
    startColumn = startTileName[0] - 97;

    endLine = 8 - (endTileName[1] - '0');
    endColumn = endTileName[0] - 97;

    currentMove->SetStart(startLine, startColumn);
    currentMove->SetEnd(endLine, endColumn);
}

const Move& Player::GetCurrentMove() const {
    return *currentMove;
}

Player::~Player() {
    delete currentMove;
}
