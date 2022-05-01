#pragma once

namespace roles
{
    enum role
    {
        Duke,
        Assassin,
        Ambassador,
        Captain,
        Contessa
    };
}

namespace coup
{
    class role
    {
        enum roles::role players_role;

    public:
        // Setter for a role for a player
        void set_role(enum roles::role new_role);

        // Getter for the role of a player
        void get_role();
    };
}