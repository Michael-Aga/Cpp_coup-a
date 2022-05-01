#include "doctest.h"
#include "Player.hpp"
#include "Game.hpp"
#include "role.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
#include "Contessa.hpp"

using namespace std;
using namespace coup;

TEST_CASE("Player")
{
    Game current_game;
    Assassin al{current_game, " Al Mualim"};
    Assassin altair{current_game, "Altaïr Ibn-La'Ahad"};

    CHECK(altair.role().compare("Assassin"));
    CHECK(altair.coins() == 0);

    altair.income();

    CHECK(altair.coins() == 1);

    altair.foreign_aid();

    CHECK(altair.coins() == 3);

    altair.coup(al);
}

TEST_CASE("Duke")
{
    Game current_game;
    Duke bibi{current_game, "Bibi"};
    Captain sarah{current_game, "Sarah"};

    CHECK(bibi.coins() == 0);
    CHECK(sarah.coins() == 0);

    int people_in_israel = 9000000;
    for (int i = 0; i < people_in_israel; i++)
    {
        bibi.tax();
    }

    CHECK(bibi.coins() == 27000000);

    for (int i = 0; i < people_in_israel; i++)
    {
        sarah.steal(bibi);
    }

    CHECK(sarah.coins() == 18000000);
}

TEST_CASE("Ambassador")
{
    Game current_game;
    Ambassador a{current_game, "Malawah"};
    Assassin ass{current_game, "ass"};
    Duke d{current_game, "D"};

    CHECK_THROWS(ass.coup(d));
    CHECK_THROWS(a.block(ass));
    CHECK_THROWS(a.block(d));
    CHECK_THROWS(a.transfer(ass, d));

    ass.income();
    a.transfer(ass, d);

    CHECK(d.coins() == 1);
}

TEST_CASE("Assassin")
{
    Game current_game;

    Assassin man{current_game, "Man who threw a rock at his face"};
    Assassin ezio{current_game, "Ezio Auditore da Firenze"};

    CHECK(ezio.role().compare("Assassin"));
    CHECK(ezio.coins() == 0);

    ezio.income();

    CHECK(ezio.coins() == 1);
    ezio.foreign_aid();

    CHECK(ezio.coins() == 3);
    ezio.coup(man);

    ezio.foreign_aid();
    CHECK(ezio.coins() == 2);
    CHECK(current_game.players().size() == 1);
}

TEST_CASE("Captain")
{
    Game current_game;
    Captain robin{current_game, "Robin Hood"};
    Captain rich{current_game, "Rich people"};
    rich.foreign_aid();
    rich.foreign_aid();
    CHECK(rich.coins() == 4);

    robin.steal(rich);

    CHECK(robin.coins() == 2);
    CHECK(rich.coins() == 2);

    robin.steal(rich);

    CHECK(robin.coins() == 4);
    CHECK(rich.coins() == 0);
}

TEST_CASE("Contessa")
{
    Game current_game;
    Contessa con{current_game, "Mapleroyals"};
    Duke duke{current_game, "My life"};
    Assassin ass{current_game, "bsc in computer science and mathematics"};

    ass.foreign_aid();
    ass.income();
    con.block(ass);
    ass.coup(duke);

    CHECK(current_game.players().size() == 3);
}