




bool init()
{
    //Init flag
    bool success = true;
    
    //Initalize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        std::cout<<"SDL Could not initialize"<<std::endl;
        success=false;
    }
    else
    {
        //Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			 std::cout<<"Warning: Linear texture filtering not enabled!"<<std::endl;
		}
		
		//Create window
		gWindow = SDL_CreateWindow("Brick Breaker!",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            std::cout<<"Window Could not be Created"<<std::endl;
            success=false;
        }
        else
        {
            //Create vsync  renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				std::cout<<"Render could not be created"<<std::endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					std::cout<<"SDL_Image could not initialize"<<std::endl;
					success = false;
				}
			}
            
        }
    }
    return success;
}






bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load Backround
    if(!gBackground.loadFromFile("grass.bmp"))
    {
        std::cout<<"could not load Grass texture"<<std::endl;
        success=false;
    }


    //Load Paddle texture
    if (!gDotTexture.loadFromFile("paddle.bmp"))
    {
        std::cout<<"Failed to load texture"<<std::endl;
        success=false;
    }

    if (!gBallTexture.loadFromFile("dot.bmp"))
    {
        std::cout<<"Failed to load ball"<<std::endl;
    }

    //Load Brick Texture
    if (!gBrickTexture.loadFromFile("brick.bmp"))
    {
        std::cout<<"Failed to load Brick.bmp"<<std::endl;
        success=false;
    }

    return success;
}

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If anay of the sides are From A are ...
    if(bottomA<=topB)
    {
        return false;
    }

    if(topA>=bottomB)
    {
        return false;
    }
    if(rightA<=leftB)
    {
        return false;
    }
    if(leftA>= rightB)
    {
        return false;
    }
    //IF not of the sides
    return true;
}



void close()
{
	//Free loaded images
	gDotTexture.free();
	gBackground.free();
	gBrickTexture.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();


}







