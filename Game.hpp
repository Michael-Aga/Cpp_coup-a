#pragma once
#include <string>
#include <vector>

namespace coup
{
    class Game
    {
    private:
        // All the characters that are playing the current match
        std::vector<std::string> _all_players;

        // The name of the player that this is his turn to play
        std::string _current_player;

    public:
        // Constructor
        Game() {}

        // Setter
        void set_turn(std::string &player);

        // Returns the name of the player that is playing now
        std::string turn();

        // Returns the names of all the active players in the game
        std::vector<std::string> &players();

        /*
        Returns who is the winner of the game.
        if the game is still in progress, then throw exception.
        */
        std::string winner();
    };
}