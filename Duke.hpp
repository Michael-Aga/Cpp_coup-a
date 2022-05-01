#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Duke : public Player
    {
    public:
        // Constractur
        Duke(Game &game, std::string dukes_name);

        // The dukes special ability that gets a tax of 3 coins from the cash register
        void tax();

        // The duke blocks forein_aid from another player
        void block(Player &player);
    };
}