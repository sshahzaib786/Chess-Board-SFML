# Chess-Board-SFML
#include <SFML/Graphics.hpp>
using namespace sf;
int size = 56;
Sprite f[32];
int board[8][8] =
{ -1,-2,-3,-4,-5,-3,-2,-1,
 -6,-6,-6,-6,-6,-6,-6,-6,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  6, 6, 6, 6, 6, 6, 6, 6,
  1, 2, 3, 4, 5, 3, 2, 1 };
void position()
{
    int k = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            int n = board[i][j];
            if (!n) continue;
            int x = abs(n) - 1;
            int y = n > 0 ? 1 : 0;
            f[k].setTextureRect(IntRect(size * x, size * y, size, size));
            f[k].setPosition(size * j, size * i);
            k++;
        }  
}
int main()
{
    RenderWindow window(VideoMode(454, 455), "SFML CHESS BOARD ");
    Texture t1, t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board0.png");
    for (int i = 0; i < 32; i++) f[i].setTexture(t1);
    Sprite sBoard(t2);
    position();
    int n = 0;
    while (window.isOpen())
    {        
        Event e;
        while (window.pollEvent(e))
            if (e.type == Event::Closed)
                window.close();      
        window.draw(sBoard);   
        for (int i = 0; i < 32; i++) window.draw(f[i]); window.draw(f[n]); 
        window.display();
    }
    return 0;
}
