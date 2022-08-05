#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>
using namespace std;

class Player
{
private:
    string name_;
    int score_=0;
public:
    Player(string name);
    string get_name();
    int get_points();
    bool has_won();
    void add_points(int x);

};

#endif // PLAYER_HH
