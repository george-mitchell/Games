// Noughts and Crosses Game

#include <iostream> 
#include <vector>

using namespace std;

int BeginPlay()
{
    cout << "\nNoughts and Crosses Game" << endl;
    cout << "===================================" << endl; 
    int NumOfPlayers {}; 
    do
    { 
        cout << "1.........Single Player (Player vs AI)" << endl;
        cout << "2.........Two Players (Player1 vs Player2)" << endl; 
        cout << "3.........Quit Game" << endl;
        cout << "===================================" << endl; 
        cout << "How many players: ";
        cin >> NumOfPlayers; 

    } while (NumOfPlayers != 1 && NumOfPlayers != 2 && NumOfPlayers != 3);
    
    
    return NumOfPlayers;
}

void DisplayBoard (vector <char> turns)
{
    cout << endl;
    for ( int i {1}; i <= 9; ++i)
    {
        if ((i % 3 == 0) && i != 9)
        {
            if( turns.at(i-1) == 'U')
            {
                cout << " " << endl; 
                cout << "----------" << endl;
            }
            else
            { 
                cout << turns.at(i-1) << endl;
                cout << "----------" << endl;
            }
        }
        else if (i ==9)
        {
            if (turns.at(i-1) == 'U')
            {
                cout << " " << endl;
            }
            else
            {
                cout << turns.at(i-1) << endl;
            }
        }
        else
        {
            if ( turns.at(i-1) == 'U')
             {
                cout << " " << " | "; 
            }
            else
            {
                cout << turns.at(i-1) << " | ";
            }
        }
    }
    cout << endl;
}

bool PlayerWon (vector <int> PlayerTurns)
{
    
    if (PlayerTurns.at(0) == 1 && PlayerTurns.at(1) == 1 && PlayerTurns.at(2) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(0) == 1 && PlayerTurns.at(3) == 1 && PlayerTurns.at(6) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(0) == 1 && PlayerTurns.at(4) == 1 && PlayerTurns.at(8) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(1) == 1 && PlayerTurns.at(4) == 1 && PlayerTurns.at(7) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(2) == 1 && PlayerTurns.at(5) == 1 && PlayerTurns.at(8) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(2) == 1 && PlayerTurns.at(4) == 1 && PlayerTurns.at(6) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(3) == 1 && PlayerTurns.at(4) == 1 && PlayerTurns.at(5) == 1)
    {
        return true; 
    }
    if (PlayerTurns.at(6) == 1 && PlayerTurns.at(7) == 1 && PlayerTurns.at(8) == 1)
    {
        return true; 
    }

    return false;
}

int GamePlay (const char player1, const char player2, const string name1, const string name2)
{
    int PlayerTurn {1}; 
    vector <int> Player1Turns (9); 
    vector <int> Player2Turns (9);
    vector <char> GameState {'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'};
    bool GameOver {false}; 
    int winner {};


    if (name2 != "TuRiNg")
    {
        do
        {
            if (PlayerTurn == 1)
            {
                int pos {};
                cout << name1 << ": ";
                cin >> pos; 
                if (Player1Turns.at(pos-1) == 0 && Player2Turns.at(pos-1) == 0)
                {
                    Player1Turns.at(pos-1) = 1; 
                    if(PlayerWon(Player1Turns))
                    {
                        GameOver = true;
                        winner = 1;
                        break;
                    }
                    
                    //update game board
                    GameState.at(pos-1) = player1; 

                    // check that there are still moves available
                    int count {0};
                    for (auto x: GameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        DisplayBoard(GameState);
                        PlayerTurn = 2;
                    }
                    else
                    {
                        winner = 3; 
                        break;
                    }
                    
                }
            }

            if (PlayerTurn == 2)
            {
                int pos {};
                cout << name2 << ": ";
                cin >> pos; 
                if (Player1Turns.at(pos-1) == 0 && Player2Turns.at(pos-1) == 0)
                {
                    Player2Turns.at(pos-1) = 1; 
                    if(PlayerWon(Player2Turns))
                    {
                        GameOver = true;
                        winner = 2;
                        break;
                    }
                    
                    GameState.at(pos-1) = player2; 
                    int count {0};
                    for (auto x: GameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        DisplayBoard(GameState);
                        PlayerTurn = 1;
                    }
                    else
                    {
                        winner = 3; 
                        break;
                    }
                }
            }



        } while (!GameOver);
    }
    else
    {
        do
        {
            if (PlayerTurn == 1)
            {
                int pos {};
                cout << name1 << ": ";
                cin >> pos; 
                if (Player1Turns.at(pos-1) == 0 && Player2Turns.at(pos-1) == 0)
                {
                    Player1Turns.at(pos-1) = 1; 
                    if(PlayerWon(Player1Turns))
                    {
                        GameOver = true;
                        winner = 1;
                        break;
                    }
                    
                    //update game board
                    GameState.at(pos-1) = player1; 

                    // check that there are still moves available
                    int count {0};
                    for (auto x: GameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        DisplayBoard(GameState);
                        PlayerTurn = 2;
                    }
                    else
                    {
                        winner = 3; 
                        break;
                    }
                    
                }
            }

            if (PlayerTurn == 2)
            {
                int pos { (rand() % 9) + 1};
                if (Player1Turns.at(pos-1) == 0 && Player2Turns.at(pos-1) == 0)
                {
                    Player2Turns.at(pos-1) = 1; 
                    if(PlayerWon(Player2Turns))
                    {
                        GameOver = true;
                        winner = 2;
                        break;
                    }
                    
                    GameState.at(pos-1) = player2; 
                    int count {0};
                    for (auto x: GameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        DisplayBoard(GameState);
                        PlayerTurn = 1;
                    }
                    else
                    {
                        winner = 3; 
                        break;
                    }
                }
            }



        } while (!GameOver);
    }



    return winner;
    
}

void Noughts (const int players) 
{
    int winner {};

    if (players == 1)
    {
        string name {}; 
        cout << "Enter name for Player: "; 
        cin >> name; 

        cout << "\nHere is the board: " << endl; 
        vector <char> board {'1','2','3','4','5','6','7','8','9'}; 
        DisplayBoard(board);

        cout << "The Player will place their mark by using the corresponding number (1-9) on the board" << endl;

        cout << "\nIs " << name << " playing as noughts 'O' or crosses 'X'? "; 
        char OorX {}; 
        cin >> OorX; 

        char player1 {}; 
        char player2 {}; 

        if (OorX == 'O' || OorX == 'o')
        {
            player1 = 'O';
            player2 = 'X';
        }
        else
        {
            player1 = 'X';
            player2 = 'O';
        }

        cout << endl;
        cout << "Let's play!" << endl;
        cout << "=====================" << endl; 

        winner = GamePlay(player1, player2, name, "TuRiNg"); 

        if (winner == 1)
        {
            cout << name << " is the winner!" << endl;
        }

        if (winner == 2)
        {
            cout << "Sorry, you lost." << endl;
        }

        if (winner == 3)
        {
            cout << "It's a draw!" << endl; 
        }
    }


    if (players == 2)
    {
        string name1 {}, name2{}; 
        cout << "Enter name for Player 1: "; 
        cin >> name1; 
        cout << "Enter name for Player 2: "; 
        cin >> name2; 

        cout << "\nHere is the board: " << endl; 
        vector <char> board {'1','2','3','4','5','6','7','8','9'}; 
        DisplayBoard(board);
        
        
        cout << "Players will place their mark by using the corresponding number (1-9) on the board" << endl; 

        cout << "\nIs " << name1 << " playing as noughts 'O' or crosses 'X'? "; 
        char OorX {}; 
        cin >> OorX; 

        char player1 {}; 
        char player2 {}; 

        if (OorX == 'O' || OorX == 'o')
        {
            player1 = 'O';
            player2 = 'X';
        }
        else
        {
            player1 = 'X';
            player2 = 'O';
        }

        cout << endl;
        cout << "Let's play!" << endl;
        cout << "=====================" << endl; 

        winner = GamePlay(player1, player2, name1, name2); 

        if (winner == 1)
        {
            cout << name1 << " is the winner!" << endl;
        }

        if (winner == 2)
        {
            cout << name2 << " is the winner!" << endl;
        }

        if (winner == 3)
        {
            cout << "It's a draw!" << endl; 
        }
    }

}


int main () 
{
    int GameSetting {BeginPlay()}; 

    Noughts(GameSetting); 

    return 0;
}

