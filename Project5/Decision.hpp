#ifndef DECISION_HPP
#define DECISION_HPP

class Decision {
private:
    double x; // The probability parameter

public:
    Decision(double val);
    // Returns 0 for play, 1 for not play
    int MakeDecision(int weather);
};

#endif
