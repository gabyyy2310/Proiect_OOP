#include "ChallengeManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool ChallengeManager::loadChallenges(const std::string& filename) {
    challenges.clear();
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "[Error] Could not open challenge file: " << filename << "\n";
        return false;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string type, question, answerStr, rewardStr;

        if (!std::getline(ss, type, ';')) continue;
        if (!std::getline(ss, question, ';')) continue;
        if (!std::getline(ss, answerStr, ';')) continue;
        if (!std::getline(ss, rewardStr, ';')) continue;

        float answer = std::stof(answerStr);
        int reward = std::stoi(rewardStr);

        auto ch = ChallengeFactory::createChallenge(type, question, answer, reward);
        if (ch) {
            challenges.push_back(ch);
        }
    }
    return true;
}

const std::vector<std::shared_ptr<Challenge>>& ChallengeManager::getChallenges() const {
    return challenges;
}