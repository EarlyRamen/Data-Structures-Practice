#include "problem.h"

#define MASK 0xFull

std::ostream& operator<<(std::ostream& out, const State& s)
{
    out << "----------------\n";
    out <<"| " << s.get(0) << " | " << s.get(1) << " | " << s.get(2) << " |\n"; 
    out << "----------------\n";
    out <<"| " << s.get(3) << " | " << s.get(4) << " | " << s.get(5) << " |\n";
    out << "----------------\n";
    out <<"| " << s.get(6) << " | " << s.get(7) << " | " << s.get(8) << " |\n";
    out << "----------------\n";
    return out;
}

uint64_t State::get(uint8_t pos) const
{
    uint8_t bitPos{static_cast<uint8_t>(pos << 2u)};
    return (board & (MASK << bitPos)) >> bitPos;
}

State State::move(uint8_t pos) const
{
    uint8_t bitPos{static_cast<uint8_t>(pos<<2u)};
    uint8_t blankBitPos{static_cast<uint8_t>(blankPos<<2u)};
    State newState{board,blankPos};
    uint64_t tile{get(pos)}; //tile is the value that we are swapping the blank with
    newState.board |= tile << blankBitPos; 
    newState.board &= (MASK << bitPos);

    newState.blankPos = pos;

    return newState;
}

State Problem::getInitialState() const {return initialState;}

bool Problem::goalTest(const State& s) const {return s==goal;}

uint64_t Problem::stepCost(const State& i, const State& j) {return 1;}

std::vector<State> Problem::adjacentState(const State& s) const
{
    std::vector<State> adjState;
    uint8_t blankPos=s.blankPos;

    for (size_t i = 0; i < 4 && transitionTable[i][blankPos]>=0; ++i)
        adjState.emplace_back(s.move(transitionTable[blankPos][i]));

    return adjState; 
}
