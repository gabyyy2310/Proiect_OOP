#ifndef CHALLENGEFACTORY_H
#define CHALLENGEFACTORY_H

#include <memory>
#include <string>
#include "Challenge.h"
#include "MathChallenge.h"
#include "EstimateChallenge.h"

class ChallengeFactory {
public:
    static std::shared_ptr<Challenge> createChallenge(const std::string& type,
                                                      const std::string& question,
                                                      float answer, int reward);
};

#endif
