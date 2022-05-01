#include "Duke.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>

using namespace std;

coup::Duke::Duke(coup::Game &game, string dukes_name) : Player(game, dukes_name) {}

void coup::Duke::tax() {}

void coup::Duke::block(Player &player) {}