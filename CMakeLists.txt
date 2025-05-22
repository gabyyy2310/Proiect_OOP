cmake_minimum_required(VERSION 3.31)
project(ProiectOOP_Gabriela)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProiectOOP_Gabriela main.cpp
        challenge.h
        mathchallenge.cpp
        mathchallenge.h
        estimatechallenge.cpp
        EstimateChallenge.h
        Item.cpp
        Item.h
        Trader.cpp
        Trader.h
        Map.cpp
        Map.h
        City.cpp
        City.h
        Randomised.cpp
        Randomised.h
        specialCity.cpp
        specialCity.h
        ChallengeManager.cpp
        ChallengeManager.h
        ChallengeFactory.cpp
        ChallengeFactory.h
        dangerousCity.cpp
        dangerousCity.h
        Metropolis.cpp
        Metropolis.h
)
