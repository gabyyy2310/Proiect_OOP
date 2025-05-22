#include "EstimateChallenge.h"
#include <iostream>
using namespace std;

EstimateChallenge::EstimateChallenge(const string& q, float ans, int reward)
    : question(q), correctAnswer(ans), reward(reward) {}

void EstimateChallenge::display() const {
    cout << "[Challenge] If you are brave enough, do this estimation challenge: " << question << endl;
}

bool EstimateChallenge::checkAnswer(float answer) const {
    return answer / correctAnswer < 1.1 && answer / correctAnswer > 0.9;
}

int EstimateChallenge::getReward() const {
    return reward;
}
