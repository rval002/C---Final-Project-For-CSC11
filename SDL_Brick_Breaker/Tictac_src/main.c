/* 
 * File:   main.cpp
 * Author: Ricardo Valverde 
 *Student ID: 2394483
 * 
 * Tic-Tac-Toe
 * Problem:
 * I Certify This is my own work
 * 
 * Created on June 3, 2015, 5:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


// Global Row And Col
const int  G_ROW = 3;
const int  G_COL = 3;

/*
 @returns: False or true
 @PARAM NUM any number
 @PRAM a string with a number
 * CHECKS IF A String is bigger than 0 
 * but smaller than num 
 */
bool validEntry(int num,string check);

/*
 * 
 *  Determines the game mode
 */
void gameMode(int& gamemode);


/*
 Displays the Current Game Board
 * 
 * @PARAM: Takes a char pointer that stores 
 * What char are currently on the game board
 */
void dGameBoard(string a[][G_ROW]);

void board (string a[][G_ROW],string& pos);



//Place The X or O in the position
void place(string a[][G_ROW],string pos,int player);

string baseAI();




/*
 @PARAM Char Pointer that stores the O & X'S
 
 @PARAM bool That Determies Where It is the player or not  
 
 * @Return Returns bool the Decides if the player has won or lost
 */
bool winCheck(string a[][G_ROW],int player);

/*
 Writes or reads from stats. Depending param
 @PARAM Bool Determines if reading or writing 
 */
void stats(bool display);

/*
 
 
 */



/*
 * 
 */
int main(int argc, char** argv) 
{
    
    //Checks if the game is still going on 
    bool game = false;
    //Declares game mode
    int gamemode;
    //Stores info
    string array[G_COL][G_ROW] = {{"1","2","3"},{"4","5","6"},{"7","8","9"}}; 
    string pos;
    int player;
    bool cool=false;
    do
    {
        gameMode(gamemode);
        
        
        
        dGameBoard(array);
        for (int i=0;i<9;i++)    
        {
            if (i%2 ==0)
            {
                player=1;
            }
            else
            {
                player=2;
            }
            
            board(array,pos);
            place(array,pos,player);
            if (i>=2)
            {
            if(!winCheck(array,player))
            {
                cout<<"PLAYER: "<<player<<" WINS!"<<endl;
                i=9;
                
            }
            
            }
        }
        stats(false);
        stats(true);
        
            
        
    }while (cool);
        
        

    return 0;
}

bool validEntry(int num,string check)
{
    bool valid = true;
    int temp;
    
    if (1>atoi(check.c_str()) || atoi(check.c_str())>= num +1)
    {
        valid = false;
        cout<<"Invalid Entry"<<endl;
    }
    
    
        
    return valid;
}

void gameMode(int& gamemode)
{
    int num=4; // Number of options 
    string pm;
    bool valid;
        
    do 
    {
        
       valid = true;
        
        
        cout<<"Please select a game mode: "<<endl;
        cout<<"Enter 1 for Player Vs Player"<<endl;
        cout<<"Enter 2 for Player Vs Dumb AI"<<endl;
        cout<<"Enter 3 for Dumb AI Vs Dumb AI"<<endl;
        cout<<"Enter 4 for Player Vs Perfect AI"<<endl;
        cin>>pm;
        
        
        
        
        
        
        
    }while(!validEntry(4,pm));
    
    atoi(pm.c_str());
        
}
    

void dGameBoard(string a[][G_ROW])
{
    int r = 19;// num of -
    int w = 3; //Width
    char d = '|'; // Row
    
        
        
        for (int j = 0;j<G_ROW;j++)
        {
            cout<<setfill('-')<<setw(r)<<""<<endl;
            cout<<setfill(' ');
            cout<<d<<setw(w)<<a[0][j]<<setw(w)<<d;
            cout<<setw(w)<<a[1][j]<<setw(w)<<d<<setw(w)<<a[2][j]<<setw(w)
            <<d<<endl;
            
        }
        cout<<setfill('-')<<setw(r)<<""<<endl;
    
    
}

void board (string a[][G_ROW],string& pos)
{
    do
    {
        
    cout<<"Please enter The position You would like to Place in: "<<endl;
    cin>>pos;
           
           
    }while (!validEntry(9,pos));
    
}
string baseAI()
{
    srand(time(0));
    int number = rand()%9+1;
  
    //Magically converts int to a string
    

string s = static_cast<ostringstream*>( &(ostringstream() << number) )->str();
return s;
    
        
    
    
}

void place(string a[][G_ROW],string pos,int player)
{
    
    pos=baseAI();
    
    for (int i =0; i<G_COL;i++)
    {
     
        for (int j = 0; j<G_ROW;j++ )
        {
            if (a[i][j]== pos)
            {
                if (player == 1)
                {
                a[i][j]="X";
                }
                else 
                {
                    a[i][j]="O";
                }
               
            }
           
        }
        
    }
        
    dGameBoard(a);
        
}


bool winCheck(string a[][G_ROW],int player )
{

    if (a[0][0]==a[1][1]&&a[0][0]==a[2][2]||a[2][0]==a[1][1]&&a[2][0]==a[0][2])
   {
       return false;
       
       cout<<"Player "<< player <<" Wins!"<<endl;
   }
   else
   {
    
    for (int i=0;i<3;i++)
    {
        
    
    if (a[i][0]==a[i][1]&&a[i][0]==a[i][2]||a[0][i]==a[1][i]&&a[0][i]==a[2][i])
    {
        return false;
        cout<<"Player "<< player <<" Wins!"<<endl;
    }
    }
   }
    
    return true;
}

void stats(bool display)
{
    
    string fileo="stats.txt";
    
    if (display)
    {
        ofstream file;
        file.open(fileo.c_str());
        
        file<<"win"<<endl;
        file<<"lose"<<endl;
        file<<"tie"<<endl;
        file.close();
    }
    else
    {
        
        ifstream file2;
        file2.open(fileo.c_str());
    
        while(file2)
    {
        string temp;
        file2>>temp;
        cout<<temp<<endl;
        
     
    }
        file2.close();
    }
}