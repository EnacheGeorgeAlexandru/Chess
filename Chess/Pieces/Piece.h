#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>


namespace Chess {
	class Board;
	class Move;
	namespace Pieces {
		class Piece {
		protected:
			std::string color;
		public:
			Piece(const std::string& color);
			//Piece(const std::string colorP);
			std::string getColor() const;
			virtual void printPiece() const = 0;
			virtual std::list<std::pair<int, int>> legalMoves(const Board&, const std::pair<int, int>&) const = 0;
			virtual bool isMoveLegal(const Board&, const Move&) const = 0;
		};
	}
}

