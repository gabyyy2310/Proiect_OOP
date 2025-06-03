#include "StealMoney.h"
#include <iostream>
#include <random>
using namespace std;

StealMoney::StealMoney(ChallengeManager& cm) : challengeManager(cm) {}

void StealMoney::attemptTheft(Trader& trader) const {
    cout << "[Thief] Stop! You look wealthy... Answer this, and you might walk away richer!\n";

    const auto& challenges = challengeManager.getChallenges();
    if (challenges.empty()) {
        cout << "[Thief] No challenge? Then I’ll just take your money!\n";
        trader.lose(rand() % 30 + 10);
        return;
    }

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, challenges.size() - 1);
    auto& challenge = challenges[dist(gen)];

    challenge->display();
    string input;
    cin >> input;

    try {
        float answer = stof(input);
        if (challenge->checkAnswer(answer)) {
            int reward = challenge->getReward();
            cout << "[Thief] Impressive! Here, take " << reward << " as a reward!\n";
            trader.earn(reward);
        } else {
            int loss = rand() % 30 + 10;
            cout << "[Thief] Wrong! You lose " << loss << " money.\n";
            trader.lose(loss);
        }
    } catch (...) {
        int loss = rand() % 30 + 10;
        cout << "[Thief] You didn’t even try. I’ll take " << loss << " money.\n";
        trader.lose(loss);
    }
}