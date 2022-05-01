#include "Game.hpp"
#include <string>

using namespace std;

void coup::Game::set_turn(string &player) {}

string coup::Game::turn()
{
    return this->_current_player;
}

vector<string> &coup::Game::players()
{
    return this->_all_players;
}

string coup::Game::winner()
{
    return this->_all_players.at(0);
}