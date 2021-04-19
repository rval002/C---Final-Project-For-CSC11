class Brick
{
public:
    //Dimensions of brick
     const int BRICK_WIDTH = 40;
     const int BRICK_HEIGHT = 20;

    //Initialize the Variables
    Brick();

    //Displays on Screen
    void render();
	
	//Gets the rectangle for it.
    SDL_Rect* getRect();

    //Sets Position on screen
    void set_BrickPos(int x,int y);

	
private:
    //Bricks collision Box
    SDL_Rect brick_hit_box;
};



Brick::Brick()
{

     //Set collision box dimension
     brick_hit_box.w = BRICK_WIDTH;
     brick_hit_box.h = BRICK_HEIGHT;
     brick_hit_box.x = 0;
     brick_hit_box.y = 0;
}


void Brick::set_BrickPos(int X,int Y)
{
    this->brick_hit_box.x=X;
    this->brick_hit_box.y=Y;
}

SDL_Rect* Brick::getRect();
{
	return &brick_hit_box;
}

void Brick::render()
{
    //Show the Brick
    gBrickTexture.render(brick_hit_box.x,brick_hit_box.y);

}