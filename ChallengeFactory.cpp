#include "ChallengeFactory.h"

std::shared_ptr<Challenge> ChallengeFactory::createChallenge(const std::string& type,
                                                             const std::string& question,
                                                             float answer, int reward) {
    if (type == "math") {
        return std::make_shared<MathChallenge>(question, answer, reward);
    } else if (type == "estimate") {
        return std::make_shared<EstimateChallenge>(question, answer, reward);
    }
    return nullptr;
}
