// Noughts and Crosses Game

#include <iostream> 
#include <vector>

using namespace std;

long long int Exponent (const int base, const int expo)
{
    long long int result {1};
    for(int i {1}; i <= expo; i++)
    {
        result = result * base; 
    }

    return result;
}

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

int AIDecision (vector <int> Player1Turns, vector <int> Player2Turns, vector <char> GameState, const int Difficulty, const char player1, const char player2)
{
    vector <int> NewPlayer1Turns {Player1Turns};
    for (int i {1}; i <= 9; ++i)
    {
        NewPlayer1Turns.at(i-1) = 1;
        if (PlayerWon(NewPlayer1Turns) && GameState.at(i-1) == 'U')
        {
            return i;
        }
        else
        {
            NewPlayer1Turns = Player1Turns; 
        }
    }


    // Computer runs simulation of game
    vector <vector <int>> Trials {}; 
    long long int NumberOfTrials {Exponent(10, (Difficulty +2))}; 
    bool GameOver {false}; 
    vector <char> NewGameState = GameState;
    vector <int> NewPlayer2Turns = Player2Turns;
    vector <int> TrialStages (2); 
    long long int debug {0};
    long long int debug2 {0}; 

    for (long long int i {1}; i <= NumberOfTrials; ++i)
    {
        int PlayerTurn {2};
        int FirstMove {1};
        TrialStages = {0,0}; 
        NewGameState = GameState; 
        NewPlayer1Turns = Player1Turns; 
        NewPlayer2Turns = Player2Turns;
        do
        {
            if (PlayerTurn == 2)
            {
                int pos {(rand() % 9 + 1)};

                if (NewGameState.at(pos-1) == 'U')
                {
                    if (FirstMove == 1)
                    {
                        FirstMove = 2; 
                        TrialStages.at(0) = pos;
                        TrialStages.at(1) = 0; 
                        Trials.push_back(TrialStages);
                    }
                    NewGameState.at(pos-1) = player2; 
                    NewPlayer2Turns.at(pos-1) = 1;
                    if (PlayerWon(NewPlayer2Turns))
                    {
                        GameOver = true;
                        debug = debug + 1;              // DEBUG LINE
                        Trials.at(i-1).at(1) = 1;
                        break;
                    }
                    int count {0};
                    for (auto x: NewGameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        PlayerTurn = 1;
                    }
                    else
                    {
                        break;
                    }
                }

            }

            if (PlayerTurn = 1)
            {
                int pos {rand() % 9 + 1};

                if (NewGameState.at(pos-1) == 'U')
                {
                    NewGameState.at(pos-1) = player1;
                    NewPlayer1Turns.at(pos-1) = 1; 
                    if (PlayerWon(NewPlayer1Turns))
                    {
                        debug2 = debug2 + 1;            // DEBUG LINE
                        GameOver = true;
                        break;
                    }
                    int count {0};
                    for (auto x: NewGameState)
                    {
                        if (x == 'U')
                        {
                            count = count + 1; 
                        }
                    }
                    if ( count != 0)
                    {
                        PlayerTurn = 2;
                    }
                    else
                    {
                        break;
                    }
                }
            }

        } while (!GameOver);
    }

    cout << "debug: " << debug << endl; 
    cout << "debug2: " << debug2 << endl; 

    // Collect those first moves which led to a win
    vector <int> BestMove {}; 
    for (long long int i {0}; i < Trials.size(); i++)
    {
        if( Trials.at(i).at(1) == 1)
        {
            BestMove.push_back(Trials.at(i).at(0));
        }
    }

    if (BestMove.size() != 0)
    {
        cout << "Number of Best moves: " << BestMove.size() << endl;       // DEBUG LINE
        // Find which first move that lead to a win appeared the most
        vector <int> BestMoveFreq (9); 
        for ( int i {1}; i <= 9; i++)
        {
            int count {0}; 
            for (auto num: BestMove)
            {
                if (num == i)
                {
                    count = count + 1;
                }
            }
            BestMoveFreq.at(i-1) = count;
        } 

        int BestPos {BestMoveFreq.at(0)};
        for (auto num: BestMoveFreq)
        {
            if (num >= BestPos)
            {
                BestPos = num;
            }
        }
        for ( int i {0}; i < 9; ++i)
        {
            if (BestPos == BestMoveFreq.at(i))
            {
                return (i + 1);
            }
        }
    }
        
    return ((rand() % 9) + 1);


}

int GamePlay (const char player1, const char player2, const string name1, const string name2, const int Difficulty)
{
    int PlayerTurn {1}; 
    vector <int> Player1Turns (9); 
    vector <int> Player2Turns (9);
    vector <char> GameState {'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'};
    bool GameOver {false}; 
    int winner {};


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
                GameState.at(pos-1) = player1;
                if(PlayerWon(Player1Turns))
                {
                    GameOver = true;
                    winner = 1;
                    DisplayBoard(GameState);
                    break;
                }

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
                    DisplayBoard(GameState);
                    break;
                }
                
            }
        }

        if (PlayerTurn == 2)
        {
            int pos {};
            if (name2 == "TuRiNg")
            {
                pos = AIDecision(Player1Turns, Player2Turns, GameState, Difficulty, player1, player2);
            }
            else if (name2 != "TuRiNg")
            {
                cout << name2 << ": ";
                cin >> pos; 
            }

            if (Player1Turns.at(pos-1) == 0 && Player2Turns.at(pos-1) == 0)
            {
                Player2Turns.at(pos-1) = 1;
                GameState.at(pos-1) = player2; 
                if(PlayerWon(Player2Turns))
                {
                    GameOver = true;
                    winner = 2;
                    DisplayBoard(GameState);
                    break;
                }
                
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
                    DisplayBoard(GameState);
                    break;
                }
            }
        }

    } while (!GameOver);

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
        cout << "Select Difficulty (1-Easy, 2-Medium, 3-Hard): ";
        int Difficulty {1}; 
        cin >> Difficulty; 

        cout << endl;
        cout << "Let's play!" << endl;
        cout << "=====================" << endl; 

        winner = GamePlay(player1, player2, name, "TuRiNg", Difficulty); 

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

        winner = GamePlay(player1, player2, name1, name2, 1); 

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

