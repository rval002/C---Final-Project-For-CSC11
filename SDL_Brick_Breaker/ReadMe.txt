//Read Me






//Tic-Tac-Toe
Game Prompts Player For game mode 1-4, all gamemodes Revert to vs dub AI

The Board is dispayed, the User  can enter 1-9 , the players char replaces the corresponding position

The AI then Responds by putting it in a random place and so on

Each time this happens after 3 turns has passed, The positions of the board are checked to find any "wins"

if a win Happens Stats are displayed, and then the user is kicked out to the main menu.

 










//Brick Breaker

Screen Loads Up; X the window to Exit the game. Screen is non Resizeable.
Game initializes SDL_Systems
game Loads all textures onto the Screen.
"Balls: " Shows up but does not update the number of balls left. Stagnant to number of balls

Player can move the Paddle Left and Right by Pressing left key and right key, if the Paddle hits the borders it stops.
Paddle has 3 hit Boxes.

Ball Is suspended mid air above the players paddle. Enter can be pressed to make it move forward. pressing enter will make it go faster.
If  the Ball Hits the paddle or walls it bounces off, How depends on the hit box it hit.

If Ball Hits any Brick, the brick Disapears by moving it off screen. The Ball then Bounces back.

if The ball passes the paddle it respawns in the starting location.

Once all Bricks are Hit or all or the balls left are 0 The window Shuts down.

ALL if not most Images/Pointes are deallocated (Possible one or two were Forggoten.)

 



