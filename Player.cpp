#include "Player.hpp"

using namespace std;

string coup::Player::getName() const
{
    return this->_player_name;
}

void coup::Player::income()
{
    this->_player_coins++;
}

void coup::Player::foreign_aid() {}

void coup::Player::coup(Player &player_location) {}

string coup::Player::role() const
{
    return "The players role is: ";
}

int coup::Player::coins() const
{
    return this->_player_coins;
}

bool coup::Player::operator==(Player &player)
{
    return false;
}