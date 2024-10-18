#include <ostream>
#include <cstdint>
#include <vector>

#ifndef BA3E613A_3097_4DA2_AA30_40032BB325D7
#define BA3E613A_3097_4DA2_AA30_40032BB325D7

struct State
{
    bool operator==(const State& s) const {return s.board == board;}
    bool operator!=(const State& s) const {return !(*this == s);}

    uint64_t get(uint8_t pos) const;
    State move(uint8_t pos) const;

    friend std::ostream& operator<<(std::ostream&, const State&);
    uint64_t board;
    uint8_t blankPos;
};

class Problem
{
public:
    State getInitialState() const;
    bool goalTest(const State&) const;
    uint64_t stepCost(const State&, const State&);
    std::vector<State> adjacentState(const State& ) const;

private:
    const State initialState{0x854207613, 4};
    const State goal {0x876543210,0};

    const int8_t transitionTable[9][4]
    {
        1, 3, -1, -1,
        0, 2,  4, -1,
        1, 5, -1, -1,
        0, 4,  6, -1,
        1, 3,  5,  7,
        2, 4,  8, -1,
        3, 7, -1, -1,
        4, 6,  8, -1,
        5, 7, -1, -1
    };
};

#endif /* BA3E613A_3097_4DA2_AA30_40032BB325D7 */
