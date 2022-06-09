class Chip{
    private:
    static Chip *field[3][8];
    char color;
    Player* player;
    public:

    Chip(std::string coordinate, Player &player);
    static Chip getChip(std::string coordinate);
    static void resetField();
};