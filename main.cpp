#include <iostream>
#include <iomanip>

#include <cstdint>

enum castling_flags {
    white_a_rook_moved = 1,
    white_h_rook_moved = 2,
    white_king_moved = 4,

    black_a_rook_moved = 8,
    black_h_rook_moved = 16,
    black_king_moved = 32,
};

struct position {
    uint64_t white_pawn;
    uint64_t white_rook;
    uint64_t white_knight;
    uint64_t white_bishop;
    uint64_t white_queen;
    uint64_t white_king;

    uint64_t black_pawn;
    uint64_t black_rook;
    uint64_t black_knight;
    uint64_t black_bishop;
    uint64_t black_queen;
    uint64_t black_king;

    uint64_t white_threats;
    uint64_t black_threats;

    uint64_t en_passant_pawns;
    uint64_t castling_flags;
    bool white_to_move;
};

uint64_t constexpr pos(int col, int row) {
    return 1ul << (col + 8 * row);
}

void constexpr set(uint64_t &board, int col, int row) {
    board |= pos(col, row);
}

void constexpr unset(uint64_t &board, int col, int row) {
    board &= ~pos(col, row);
}

bool constexpr isset(const uint64_t &board, int col, int row) {
    return board & pos(col, row);
}

position constexpr start_position() {
    position pos{};
    for (int col = 0; col < 8; col++) {
        set(pos.white_pawn, col, 1);
        set(pos.black_pawn, col, 6);
    }
    set(pos.white_rook,   0, 0);
    set(pos.white_knight, 1, 0);
    set(pos.white_bishop, 2, 0);
    set(pos.white_queen,  3, 0);
    set(pos.white_king,   4, 0);
    set(pos.white_bishop, 5, 0);
    set(pos.white_knight, 6, 0);
    set(pos.white_rook,   7, 0);

    set(pos.black_rook,   0, 7);
    set(pos.black_knight, 1, 7);
    set(pos.black_bishop, 2, 7);
    set(pos.black_queen,  3, 7);
    set(pos.black_king,   4, 7);
    set(pos.black_bishop, 5, 7);
    set(pos.black_knight, 6, 7);
    set(pos.black_rook, 7, 7);

    pos.white_to_move = true;
    return pos;
}

int main() {
    position pos = start_position();
    std::cout << pos.white_pawn << "\n";
    return 0;
}