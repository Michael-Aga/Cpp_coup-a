#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, std::string captains_name) : Player(game, captains_name) {}

        // The captains special ability is to steal 2 coins from a player but can be blocked.
        void steal(Player &targeted_player);

        // The Captain can also block another Captain from stealing
        void block(Player &targeted_captain);
    };
}