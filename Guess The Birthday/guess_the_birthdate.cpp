#include <bits/stdc++.h>
using namespace std;

void printCard(int arr[4][4], string num);

//  "Guess the Birthdate"
//  "It will display 5 cards to the user, user have to tell me whether your birth date is present in it or not ?"
// "y" or "Y" for yes and "n" or "N" for no.

int main()
{
    char first, second, third, fourth, fifth;
    int birthDate = 0;
    // 1 2 4 8 16
    // first bit is set always
    int firstCard[4][4] = {
        {1, 3, 5, 7},     // 100,110,101,111,1001
        {9, 11, 13, 15},  // 1001,1101,1011,1111
        {17, 19, 21, 23}, // 10001,11001,10101,11101
        {25, 27, 29, 31}, // 10011,11011,10111,1111
    };
    // second bit is set always
    int secondCard[4][4] = {
        {2, 3, 6, 7},     // 01,11,011,111
        {10, 11, 14, 15}, // 0101,1101,0111,1111
        {18, 19, 22, 23}, // 01001,11001,01101,11101
        {26, 27, 30, 31}, // 01011,11011,01111,11111
    };

    // third bit is set always
    int thirdCard[4][4] = {
        {4, 5, 6, 7},     // 001,101,011,111
        {12, 13, 14, 15}, // 0011,1011,0111,1111
        {20, 21, 22, 23}, // 00101,10101,01101,11101
        {28, 29, 30, 31}, // 00111,10111,01111,11111
    };

    // fourth bit is set always
    int fourthCard[4][4] = {
        {8, 9, 10, 11},   // 0001,1001,0101,1101
        {12, 13, 14, 15}, // 0011,1011,0111,1111
        {24, 25, 26, 26}, // 00011,10011,01011,11011
        {28, 29, 30, 31}, // 00111,10111,01111,11111
    };
    // fifth bit is set always
    int fifthCard[4][4] = {
        {16, 17, 18, 19}, // 00001,10001,01001,11001
        {20, 21, 22, 23}, // 00101, 10101,01101,11101
        {24, 25, 26, 27}, // 00011,10011,01011,11011
        {28, 29, 30, 31}  // 00111,10111,01111,1111
    };

    cout << "Guess the Birthdate" << '\n';
    cout << "I will show you 5 cards, you have to tell me whether your birth date is present in it or not ?" << '\n';
    cout << "\'y\' for yes and \'n\' for no.\n\n";

    printCard(firstCard, "First");
    cin >> first;
    if (first == 'Y' || first == 'y')
        birthDate += firstCard[0][0]; //birthDate +=1

    printCard(secondCard, "Second");
    cin >> second;
    if (second == 'Y' || second == 'y')
        birthDate += secondCard[0][0]; //birthDate +=2

    printCard(thirdCard, "Third");
    cin >> third;
    if (third == 'Y' || third == 'y')
        birthDate += thirdCard[0][0]; //birthDate +=4

    printCard(fourthCard, "Fourth");
    cin >> fourth;
    if (fourth == 'Y' || fourth == 'y')
        birthDate += fourthCard[0][0]; //birthDate +=8

    printCard(fifthCard, "Fifth");
    cin >> fifth;
    if (fifth == 'Y' || fifth == 'y')
        birthDate += fifthCard[0][0]; //birthDate +=16

    //system("clear");// to clear the console (in Linux)
    cout << "\nYour birthdate is " << birthDate << " 🥳🥳🥳"
         << "\n\n\n";

    return 0;
}
// will print the cards(matrices)
void printCard(int arr[4][4], string num)
{
    cout << num << " card :" << '\n';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "Is your birth date present in this card ?" << '\n';
}
