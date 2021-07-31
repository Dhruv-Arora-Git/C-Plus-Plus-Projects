#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = (width / 2) + 9;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("clear");
    for (int i = 0; i <= width; i++)
    {
        cout << "# ";
    }

    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= 2 * width; j++)
        {
            if (j == 0 || j == 2 * width)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "@";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {

                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i <= width; i++)
    {
        cout << "# ";
    }
    cout << endl;
    cout << "Score: " << score << endl;
}

void Input()
{

    if (kbhit())
    {

        switch (getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    // if you want that hitting with walls will over the game
    // if (x > ((2 * width) - 1) || x < 0 || y > height - 1 || y < 0)
    // {
    //     gameOver = true;
    // }
    if (x > ((2 * width) - 1))
        x = 0;
    else if (x < 0)
        x = (2 * width) - 1;

    if (y > height - 1)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    if (x == fruitX && y == fruitY)
    {
        nTail++;
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        // to slow it down (for linux)
        system("sleep 0.2");
    }

    return 0;
}
