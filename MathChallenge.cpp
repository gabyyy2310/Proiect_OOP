#include "MathChallenge.h"
#include <iostream>
#include <cmath>
using namespace std;

MathChallenge::MathChallenge(const string& q, float ans, int reward)
    : question(q), correctAnswer(ans), reward(reward) {}

void MathChallenge::display() const {
    cout << "[Challenge] If you are brave enough, solve this math problem: " << question << endl;
}

bool MathChallenge::checkAnswer(float answer) const {
    return fabs(answer - correctAnswer) < 1e-4;
}

int MathChallenge::getReward() const {
    return reward;
}
