#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game game, std::string assassins_name) : Player(game, assassins_name) {}

        // The Assassin is the only one that can coup with only 3 coins but can be blocked.
        virtual void coup(Player &index_player);
    };
}