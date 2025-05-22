#ifndef ESTIMATECHALLENGE_H
#define ESTIMATECHALLENGE_H
#include "Challenge.h"
#include <string>

class EstimateChallenge : public Challenge {
private:
    std::string question;
    float correctAnswer;
    int reward;

public:
    EstimateChallenge(const std::string& q, float ans, int reward);
    void display() const override;
    bool checkAnswer(float answer) const override;
    int getReward() const override;
};

#endif
