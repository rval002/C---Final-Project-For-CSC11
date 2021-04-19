/* 
 * File:   main.cpp
 * Author: Ricardo Valverde 
 *Student ID: 2394483
 * 
 * Hw:
 * Problem:
 * I Certify This is my own work
 * 
 * Created on March 30, 2015, 11:53 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void pause(int time)//Pauses time
{
    clock_t temp;
    temp = clock() + time;
    while (clock() < temp) {
    }

}

void clear(int time)//Clears the Screen
{
    pause(time);
    for (int i = 0; i < 50; i++) {
        cout << endl;
    }
}

void dchip(int chips)//Displays chips
{
    cout << "The total number of chips is " << chips << endl;

}

void chipcheck(int& chips, int& games)//Gets user input for num of games
//Checks if  game amount is valid
{
    int i = 0;
    int check; //value of chips to be used 
    int gameprice = 10; //Price of game set at 10

    do {
        //Prompts the user gets number of games.
        cout << "How Many Games would you like to play?" << endl;
        cin>>games;



        check = games*gameprice;


        if (chips < check)//Tells the user the he does not have enough chips
        {
            cout << "You do not have enough Chips for this option" << endl;
            i += 1;
        } else//If enough chips subtracts chip amount stops loop
        {

            chips -= check;
            i = 0;
        }
        cout << "There are a total of " << chips << " Chips Remaining" << endl;

    }    while (i != 0);

}

void stats(int wins, int loss, int games)//Displays stats
{
    clear(3000);
    cout << "You won " << wins << " Games" << endl;
    cout << "You lost " << loss << "Games" << endl;
    cout << "Out of " << games << " Games" << endl;
    clear(3000);

}

void plus1c(int& ctot) //Adds one card to total
{

    for (int i = 0; i < 1; i++) {
        int card;
        card = 2 + rand() % (11 - 2); //Range or 2-10  
        cout << "added " << card << " to hand" << endl;
        ctot = ctot + card;
        pause(1000);
    }
}

void ace_c(int& ace, int ctot)//Checks the ace value
{
    int ftot;

    ace = 11;
    ftot = ctot + ace;
    if (ftot > 17 && ace != 1) {
        ace = 1;
        cout << "aces are hard" << endl;

    } else {
        ace = 11;
        cout << "aces are soft" << endl;

    }

    ftot = ctot + ace;

    if (ftot == 21 || ftot > 21) {
        ctot = ftot;
    }
    cout << "total is " << ftot << endl;

}

bool wincheck(int d_tot, int p_tot)//Checks if player won or lost
{

    //if dealer is 21
    //player greater than 21
    //Player hand > dealers
    if (d_tot==21&&p_tot!=21 || p_tot>21|| d_tot>p_tot&&p_tot!=21&&d_tot<21)
    {
        return false;
    } 
    else 
    {
        return true;

    }
}

void blackjack(int& chips)//BlackJack game
{

    int games, win, lose;
    win = lose = 0;
    //Prompts the user
    cout << "Welcome to Black Jack!" << endl;

    chipcheck(chips, games);

    for (int i = 0; i < games; i++)//Plays game while games remain
    {

        int p_ace, d_ace, card;
        int p_tot, d_tot;
        p_tot = d_tot = 0;

        plus1c(p_tot); //Adds first card to player
        cout << "The Players total is " << p_tot << endl;

        cout << "The Dealer drew a card " << endl;
        plus1c(d_tot); //Adds first card to dealer

        cout << "The Player drew a Ace!" << endl;
        ace_c(p_ace, p_tot); //Adds ace 
        pause(1500);

        cout << "The Dealer Drew a card" << endl;
        pause(1500);

       string hit;

        do  
        {
            //Player Hits or Stays

            
            cout << "Would you like to hit or stay ?" << endl; //Prompts
            cin>>hit;
            if(hit=="hit")
            {
            plus1c(p_tot);
            ace_c(p_ace, p_tot);
            }

        }
            while(hit == "hit" && p_tot + p_ace < 21);
            

            pause(2000);
        cout << "The Dealer revealed his cards" << endl;
        pause(1500);
        ace_c(d_ace, d_tot);
        while (d_ace + d_tot <= 17 || d_ace != 1)//Adds Cards to dealer untill req.
        {
            plus1c(d_tot);
            ace_c(d_ace, d_tot);
        }
        d_ace += d_tot; //Adds for total to check win conditions 
        p_ace += p_tot;
        pause(3000);

        if (wincheck(d_ace, p_ace)) {
            clear(3000);
            cout << "winner!" << endl;
            cout << d_ace << " Dealer's Hand " << endl;
            cout << p_ace << " Your hand " << endl;
            win++;
            chips += 30;

        } else if (!wincheck(d_ace, p_ace)) {
            clear(3000);
            cout << d_ace << " Dealer's Hand" << endl;
            cout << p_ace << " Your hand" << endl;
            cout << "You lost" << endl;
            lose++;
        } else {
            clear(3000);
            cout << d_ace << " Dealer's Hand" << endl;
            cout << p_ace << " Your hand" << endl;
            cout << "tie!" << endl;
            chips += 10;
        }

        dchip(chips);

    }

    stats(win, lose, games);
    dchip(chips);
}

void roll(int& sum) {
    int fill;//Does nothing just a place holder
    int die1 = rand() % 6 + 1; //1-6 roll
    int die2 = rand() % 6 + 1;
    sum = die1 + die2; //Total of the roll
    cout<< "Hit enter to Roll!"<<endl;
    fill=cin.get();//Stalls untill user inputs 
    
        
    cout << "You Roll the Dice!" << endl; //Outputs

    pause(1500);


    cout << "die 1: " << die1 << endl;
    pause(1000);
    cout << "die 2: " << die2 << endl;
    pause(500);
    cout << "The roll Total was:" << sum << endl;
    pause(2000);
    


}

bool crabcheck(int sum1, int sum2) {
    if (sum1 == 7 || sum1 == 11) {

        return true;
    } else if (sum1 == 2 || sum1 == 3 || sum1 == 12) {
        return false;
    } else {
        while (sum1 != sum2) {
            roll(sum2);
            if (sum2 == 7) {
                return false;
            }

        }
        return true;

    }
}

void crabs(int& chips)//Crabs game
{
    int games, win, lose;
    win = lose = 0;

    cout << "Welcome to Crabs" << endl; //Prompts User

    chipcheck(chips, games);


    for (int i = 0; i < games; i++)//Plays game while games remain
    {
        int sum1, sum2;

        roll(sum1);

        if (crabcheck(sum1, sum2)) {
            cout << "winner" << endl;
            chips += 30;
            win++;



        } else {
            cout << "Loser" << endl;
            lose++;

        }
        dchip(chips);
    }
    clear(3000);
    stats(win, lose, games);
    dchip(chips);


}

int main(int argc, char** argv) {
    srand(time(0));
    int chips, menu;

    chips = 100;
    //Prompts the user and gives them 100 Chips to start. 
    cout << "Hello Welcome to the Casino, Please enjoy your stay. " << endl;
    cout << "To make your stay even more welcoming we have deposited " << chips <<
            " Chips to your account!" << endl;
    cout << "Each game is 10 chips" << endl;


    do // Loop That allows player into the casino while there are still chips.
    {
        //Prompts user to decide which game will be played .
        cout << "What game would you like to play ? " << endl;
        cout << "Choose 1 for Black Jack" << endl;
        cout << "Choose 2 for Crabs" << endl;
       

        cin>>menu;

        switch (menu) // Menu System to decide game 
        {
            case 1: //Black Jack
            {
                clear(1000);
                blackjack(chips);


                break;
            }
            case 2: //Game 2
            {
                clear(1000);
                crabs(chips);

                break;
            }
            default:
            {
                cout << "ERROR: PLEASE ENTER A VAILD NUMBER " << endl << endl;
                
            }

        }

    }    
    while (chips > 0 );
    pause(5000);

    cout << "You No longer have any Chips, Security will now escort you out Bye!";

    return 0;
}

