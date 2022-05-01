#include "Player.hpp"
#include "Game.hpp"
#include <string>

namespace coup
{
    class Contessa : public Player
    {
    public:
        // Constructor
        Contessa(Game &game, std::string contessas_name) : Player(game, contessas_name) {}

        // The Contessas special abiliy is to block an assassination.
        void block(Player &targeted_assassin);
    };
}