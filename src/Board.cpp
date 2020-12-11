#include <iostream>
#include "Board.h"

void Board::init()
{
    mark_ = 'x';
    int digit = 1;
    for (auto line = 0; line < SIZE; line++)
    {
        for (auto column = 0; column < SIZE; column++)
        {
            board_[line][column] = DIGITS[digit++];
        }
    }

}

void Board::draw()
{
    std::cout << "-   -   -   -\n";
    for (auto line = 0; line <SIZE; line++)
    {
        for (auto column = 0; column < SIZE; column++)
        {
            std::cout << "| " <<  board_[line][column] << " ";
        }
        std::cout << "| \n";
        std::cout << "-   -   -   -\n"; 
    }
}

bool Board::check()
{
    bool flag = true;
    int i,j;
    i = j = 0;

    // Check lines
    for (i = 0; i < SIZE; i++)
    {
        if (board_[i][j] == board_[i][++j] && board_[i][j] == board_[i][++j])
            return true;
        j = 0;
    }
    i = 0;
    
    // Check Columns
    for (j = 0; j < SIZE; j++)
    {
        if (board_[i][j] ==  board_[++i][j] && board_[i][j] == board_[++i][j])
            return true;
        i = 0;
    }
    j = 0;

    // Check diags
    if (board_[i][j] == board_[++i][++j] && board_[i][j] == board_[++i][++j])
        return true;

    i = 0;
    j = SIZE - 1;
    return board_[i][j] == board_[++i][--j] && board_[i][j] == board_[++i][--j];
}

bool Board::update(int position)
{
    bool updated = false;
    for (auto line = 0; line < SIZE; line++)
    {
        for (auto column = 0; column < SIZE; column++)
        {
            if (board_[line][column] == DIGITS[position])
            {
                board_[line][column] = mark_;
            }
        }
    }

    if (updated)
    {
        mark_ = (mark_ == 'X') ? 'O' : 'X';
    }
    
    return false;
}

