#include "Game.h"
#include <iostream>

Game::Game(Board* board): board_(board) {}

void Game::run()
{
    board_->init();
    
    int moves = 0;
    while(moves < 9)
    {
        std::cout << "\n TicTacGame ! \n";
        board_->draw();
        std::cout << "\n Player " << (moves % 2 ? "2" : "1") << "\'s turn:\n";
        int position = 0;
        std::cin >> position;
        while (position > 9 || position < 1)
        {
            std::cout << "\nInvalid Input. Try agin with a valid postion!\n";
            std::cin >> position;
        }

        // Check if somebody won only if more than 3 moves a already made
        if (moves > 3)
        {
            if (board_->check())
            {
                board_->draw();
                std::cout << "\n Plater " << (moves % 2 ? "2" : "1") << " won!\n";
                break;
            }
            else if (moves == 8)
            {
                std::cout << "\nIt's a draw!\n";
            }
        }
        moves++;
    }
}