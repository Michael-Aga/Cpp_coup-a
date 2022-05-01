#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game game, std::string ambassadors_name) : Player(game, ambassadors_name) {}

        // Transfers a coin from one player to another
        void transfer(Player &from_player, Player &to_player);

        // Block the Captain from stealing 2 coins from another player.
        void block(Player &targeted_captain);
    };
}