class Ball
{
public:

    //Sets Dimensions
     const int BALL_WIDTH =20;
     const int BALL_HEIGHT=20;

    //Maximum axis velocity of the BALL
    const int BALL_VEL = 5;

    //Takes key presses and adjusts the dot's velocity
    void handleEvent( SDL_Event& e );

    //gets the SDLRECT
    SDL_Rect* getRect();


    //Moves the dot and checks collision
     void move();


    //Initialize Variables
    Ball();

  


    //Displays On Screen
    void render();

    //s velocity
    int getVX();

    int getVY();

    void setVX(int x);

    void setVY(int y);


private:
  
    //The velocity of the Ball
    int mVelX, mVelY;

    //Ball's collision box
    SDL_Rect ball_hit_box;

};

Ball::Ball()
{
     //Ball lives
    int bRemaining ;

    //Postion of Ball
    ball_hit_box.x = SCREEN_WIDTH/2;
    ball_hit_box.y = 900;

    //The velocity of the Ball
    mVelX =0;
    mVelY =0;

    //Ball's collision box
   ball_hit_box.w =BALL_WIDTH;
   ball_hit_box.h =BALL_HEIGHT;
}

void Ball::handleEvent( SDL_Event& e )
{

	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {

            case SDLK_RETURN: mVelY -= BALL_VEL;
             mVelX += BALL_VEL; break;
        }
    }
}

void Ball::move( )
{
        //Move the dot left or right
    ball_hit_box.x += mVelX;

    //If the dot went too far to the left or right
    if( ( ball_hit_box.x < 22) || ( ball_hit_box.x + BALL_WIDTH +22> SCREEN_WIDTH ) ||checkCollision(ball_hit_box,wall) )
    {
        //Move back
        mVelX *= -1;

    }

    //Move the dot up or down
    ball_hit_box.y += mVelY;

    //If the dot went too far up or down
    if( ( ball_hit_box.y < 25 ) || ( ball_hit_box.y + BALL_HEIGHT> SCREEN_HEIGHT )||checkCollision(ball_hit_box,wall) )
    {
        //Move back
        mVelY *=-1;

        if ( ball_hit_box.y + BALL_HEIGHT> SCREEN_HEIGHT )
        {
            mVelY =0;
            gBallTexture.~LTexture();
        }
    }
}



    void Ball::setVX(int x)
    {
        mVelX=x;

    }

    void Ball::setVY(int y)
    {
        mVelY=y;

    }

    int Ball::getVX()
    {
        return mVelX;
    }

    int Ball::getVY()
    {
        return mVelY;
    }
	
	SDL_Rect* Ball::getRect
	{
		return ball_hit_box;
	}



void Ball::render()
{
    gBallTexture.render(ball_hit_box.x,ball_hit_box.y);
}




