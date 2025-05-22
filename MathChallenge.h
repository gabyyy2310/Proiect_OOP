#ifndef MATHCHALLENGE_H
#define MATHCHALLENGE_H
#include "Challenge.h"
#include <string>

class MathChallenge : public Challenge {
private:
    std::string question;
    float correctAnswer;
    int reward;

public:
    MathChallenge(const std::string& q, float ans, int reward);
    void display() const override;
    bool checkAnswer(float answer) const override;
    int getReward() const override;
};

#endif
