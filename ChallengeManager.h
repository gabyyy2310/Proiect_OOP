#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Challenge.h"
#include "ChallengeFactory.h"

class ChallengeManager {
private:
    std::vector<std::shared_ptr<Challenge>> challenges;

public:
    bool loadChallenges(const std::string& filename);
    const std::vector<std::shared_ptr<Challenge>>& getChallenges() const;
};

#endif