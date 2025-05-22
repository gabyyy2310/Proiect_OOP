#ifndef CHALLENGE_H
#define CHALLENGE_H
#include <string>

class Challenge {
public:
    virtual void display() const = 0;
    virtual bool checkAnswer(float answer) const = 0;
    virtual int getReward() const = 0;
    virtual ~Challenge() = default;
};

#endif
