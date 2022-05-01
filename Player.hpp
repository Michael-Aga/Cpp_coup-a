#pragma once
#include "Game.hpp"
#include "role.hpp"
#include <string>

namespace coup
{
    /*
    A player holds coins and has a rule if the character has 10 coins
    at the start of the round he has to coup
    */
    class Player
    {
    protected:
        std::string _player_name;
        role _player_role;
        int _player_coins;
        int _players_location;

    public:
        // Constructor
        Player(Game game, std::string name) {}

        // Getter
        std::string getName() const;

        // Gain 1 coin without the ability to block it.
        void income();

        // Gain 2 coins but needs to check if there was a block
        void foreign_aid();

        // To make a coup a player need 7 coins that will be taken from him
        void coup(Player &players_location);

        // Return the role of the player
        std::string role() const;

        // Return the amount of coins that a player has
        int coins() const;

        // checks if this is equal to the argument player by the player's index
        bool operator==(Player &player);
    };
}