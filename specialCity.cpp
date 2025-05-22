#include "specialCity.h"
#include <iostream>
#include <random>
#include <sstream>
#include <algorithm>
using namespace std;

specialCity::specialCity(const string& name, int id, vector<Item> sell, vector<Item> demand,
                         float city_capital, const string& mayor, ChallengeManager& cm)
    : City(name, id, sell, demand, city_capital), mayorName(mayor), challengeManager(cm) {}

void specialCity::tradeWith(Trader& trader) {
    cout << "\n[Mayor] Welcome to " << name << "!\n";
    cout << "[Mayor] My name is " << mayorName << " and I am the mayor of this City!\n";
    cout << "[Banker] Are you looking for a specific item from our land?\n";

    string requested_item;
    cin >> requested_item;

    if (requested_item != "-") {
        auto p = find_if(item_to_sell.begin(), item_to_sell.end(), [&](const Item& item) {
            return item.getName() == requested_item;
        });

        if (p != item_to_sell.end()) {
            cout << "\n[Mayor] Yes, we have " << requested_item << "! But be careful... You have to solve a challenge to get it. Do you accept? (y/n)\n";
            char choice;
            cin >> choice;

            if (choice == 'y') {
                const auto& challenges = challengeManager.getChallenges();
                if (challenges.empty()) {
                    cout << "[Mayor] No challenges available right now.\n";
                } else {
                    static random_device rd;
                    static mt19937 gen(rd());
                    uniform_int_distribution<> dist(0, challenges.size() - 1);

                    auto& challenge = challenges[dist(gen)];
                    challenge->display();

                    string answer1;
                    cin >> answer1;
                    try {
                        float answer = stof(answer1);
                        if (challenge->checkAnswer(answer)) {
                            cout << "[Mayor] Correct! You may have the " << requested_item << ".\n";
                        } else {
                            cout << "[Mayor] Wrong answer! You cannot have the item.\n";
                        }
                    } catch (...) {
                        cout << "[Mayor] Invalid answer format. You lose the chance to get the item.\n";
                    }
                }
            } else {
                cout << "[Mayor] Oh, what a shame... Maybe next time!\n";
            }
        } else {
            cout << "[Mayor] We don't have " << requested_item << "!\n";
        }
    }

    cout << "[Mayor] Now, excuse me, but my team has a very important match that I don't want to miss.\n";
    cout << "I have other deals to do, you can talk to our Banker. Good luck!\n";

    City::tradeWith(trader);
}