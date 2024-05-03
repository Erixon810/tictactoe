#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct Player
{
    std::string ID;
    char sign;
    int wins = 0;
    int draws = 0;
    int loses = 0;
    int games_played = 0;
    int points = 0;
};

bool compare(const Player& lhs, const Player& rhs)
{
    return lhs.points > rhs.points;
}

int player_count = 0;

void getPlayerInfo(std::vector<Player> &players)
{   
    std::string filename = "players.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    std::string line;
    while (std::getline(file, line))
    {
        Player player;
        player.ID = line.substr(0, 6);
        player.sign = line[7];
        players.push_back(player);
        player_count++;
    }
    file.close();
}

void check_results(std::vector<Player>& player)
{
    std::string filename = "tictactoe.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    std::string line;
    int line_number = 0;
    char game[3][3];
    char last_player = ' ';
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
        for (int i = 0; i < 3;++i)
        {
            game[line_number][i] = line[i]; 
        }
        line_number++;        
        if (line_number == 3)
        {
            for (int i = 0;i < player_count;++i)
            {
                if ((game[0][0] == player[i].sign || game[0][1] == player[i].sign || game[0][2] == player[i].sign || game[1][0] == player[i].sign || game[1][1] == player[i].sign ||
                    game[1][2] == player[i].sign || game[2][0] == player[i].sign || game[2][1] == player[i].sign || game[2][2] == player[i].sign) && player[i].sign != last_player)
                {
                    for (int j = 0; j < player_count; ++j)
                    {
                        if ((game[0][0] == player[j].sign || game[0][1] == player[j].sign || game[0][2] == player[j].sign || game[1][0] == player[j].sign || game[1][1] == player[j].sign ||
                            game[1][2] == player[j].sign || game[2][0] == player[j].sign || game[2][1] == player[j].sign || game[2][2] == player[j].sign) && player[i].sign != player[j].sign)
                        {  
                            last_player = player[j].sign;
                                if (game[0][0] == player[i].sign && game[0][1] == player[i].sign && game[0][2] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++; 
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[1][0] == player[i].sign && game[1][1] == player[i].sign && game[1][2] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[2][0] == player[i].sign && game[2][1] == player[i].sign && game[2][2] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;  
                                    line_number = 0;
                                }
                                else if(game[0][0] == player[i].sign && game[1][0] == player[i].sign && game[2][0] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[0][1] == player[i].sign && game[1][1] == player[i].sign && game[2][1] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[0][2] == player[i].sign && game[1][2] == player[i].sign && game[2][2] == player[i].sign)
                                {
                                    player[i].wins++;
                                    player[j].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                /////////////////////////////////////////////////////////////////////////////////////////////////
                                else if (game[0][0] == player[j].sign && game[0][1] == player[j].sign && game[0][2] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[1][0] == player[j].sign && game[1][1] == player[j].sign && game[1][2] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[2][0] == player[j].sign && game[2][1] == player[j].sign && game[2][2] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[0][0] == player[j].sign && game[1][0] == player[j].sign && game[2][0] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[0][1] == player[j].sign && game[1][1] == player[j].sign && game[2][1] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                else if (game[0][2] == player[j].sign && game[1][2] == player[j].sign && game[2][2] == player[j].sign)
                                {
                                    player[j].wins++;
                                    player[i].loses++;
                                    player[j].games_played++;
                                    player[i].games_played++;
                                    line_number = 0;
                                }
                                                     
                            else if (game[0][0] == player[i].sign && game[1][1] == player[i].sign && game[2][2] == player[i].sign)
                            {
                                player[i].wins++;
                                player[j].loses++;
                                player[j].games_played++;
                                player[i].games_played++;
                                line_number = 0;
                            }
                            else if (game[0][2] == player[i].sign && game[1][1] == player[i].sign && game[2][0] == player[i].sign)
                            {
                                player[i].wins++;
                                player[j].loses++;
                                player[j].games_played++;
                                player[i].games_played++;
                                line_number = 0;
                            }  
                            ////////////////////////////
                            else if (game[0][0] == player[j].sign && game[1][1] == player[j].sign && game[2][2] == player[j].sign)
                            {
                                player[j].wins++;
                                player[i].loses++;
                                player[j].games_played++;
                                player[i].games_played++;
                                line_number = 0;
                            }
                            else if (game[0][2] == player[j].sign && game[1][1] == player[j].sign && game[2][0] == player[j].sign)
                            {
                                player[j].wins++;
                                player[i].loses++;
                                player[j].games_played++;
                                player[i].games_played++;
                                line_number = 0;
                            }
                            else if (game[0][0] != '.' && game[0][1] != '.' && game[0][2] != '.' && game[1][0] != '.' && game[1][1] != '.' &&
                                game[1][2] != '.' && game[2][0] != '.' && game[2][1] != '.' && game[2][2] != '.')
                            {
                                player[i].draws++;
                                player[j].draws++;
                                player[j].games_played++;
                                player[i].games_played++;
                                line_number = 0;
                            }
                        }                      
                    }
                }
            }           
        }
        }
    }
    file.close();
}

void show_results()
{
    std::string filename = "tictactoe.txt";
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "nie udalo sie otworzyc pliku";
    }
    std::string line;
    int line_number = 0;
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
}

void show_stats(std::vector<Player> &player, int option)
{
    bool ID_found = false;
    std::string playerID;
    std::cout << "Enter player id: ";
    std::cin >> playerID;
    if (playerID == "0")
    {
        return;
    }
    for (int i = 0; i < player_count; ++i)
    {
        if (playerID == player[i].ID)
        {
            std::cout << player[i].ID << " " << player[i].sign << " " << player[i].wins << " " << player[i].draws << " " << player[i].loses << " " << player[i].points << std::endl;
            ID_found = true;
            break;
        }
    }
    if (ID_found == false)
    {
        std::cout << "unknown ID (type 0 to return to menu)\n";
        show_stats(player, option);       
    }
}

void count_points(std::vector<Player> &player)
{
    for (int i = 0; i < player_count; ++i)
    {
        player[i].points = player[i].wins * 3 + player[i].draws;
    }
}

int main()
{
    std::vector<Player> player;
    getPlayerInfo(player);
    check_results(player);
    count_points(player);
    std::sort(player.begin(), player.end(), compare);
    int option = 0;
    do
    {
        std::cout << "1 - show table\n";
        std::cout << "2 - show results\n";
        std::cout << "3 - show player stats\n";
        std::cout << "4 - exit\n";
        std::cout << "Choose option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            for (int i = 0; i < player_count; ++i)
            {
                std::cout << player[i].ID << " " << player[i].sign << " " << player[i].wins << " " << player[i].draws << " " << player[i].loses << " " << player[i].points << std::endl;
            }
            std::cout << std::endl;
            break;
        case 2:
            show_results();
            break;
        case 3:
            show_stats(player, option);
            std::cout << std::endl;
            break;
        }
    } while (option != 4);
}
