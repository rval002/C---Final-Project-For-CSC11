# C++ Final Project For CSC11
 Projects, Containing a Suite of Games, Contains BrickBreaker, tictac and Blackjack
 

# Brick Breaker 
Note that some of the source code is missing, Executable and the associated files are still acsessible 

Screen Loads Up; X the window to Exit the game. Screen is non Resizeable.
Game initializes SDL_Systems
game Loads all textures onto the Screen.
"Balls: " Shows up but does not update the number of balls left. Stagnant to number of balls

Player can move the Paddle Left and Right by Pressing left key and right key, if the Paddle hits the borders it stops.
Paddle has 3 hit Boxes.

Ball Is suspended mid air above the players paddle. Enter can be pressed to make it move forward. pressing enter will make it go faster.
the Ball Hits the paddle or walls it bounces off, How depends on the hit box it hit.

If Ball Hits any Brick, the brick Disapears by moving it off screen. The Ball then Bounces back.

if The ball passes the paddle it respawns in the starting location.

Once all Bricks are Hit or all or the balls left are 0 The window Shuts down.

ALL if not most Images/Pointes are deallocated (Possible one or two were Forggoten.)

![image](https://user-images.githubusercontent.com/59685316/115220629-a2787b00-a0bd-11eb-80a6-1e4508848f67.png)

Image of game starting screen
