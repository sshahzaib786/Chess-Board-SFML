# Chess-Board-SFML
#include &lt;SFML/Graphics.hpp&gt;
using namespace sf;
int size = 56;
Sprite f[32];
std::string position = &quot;&quot;;
int board[8][8] =
{ -1,-2,-3,-4,-5,-3,-2,-1,
-6,-6,-6,-6,-6,-6,-6,-6,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,

6, 6, 6, 6, 6, 6, 6, 6,
1, 2, 3, 4, 5, 3, 2, 1 };
std::string toChessNote(Vector2f p)
{
std::string s = &quot;&quot;;
s += char(p.x / size + 97);
s += char(7 - p.y / size + 49);
return s;
}
void loadPosition()
{
int k = 0;
for (int i = 0; i &lt; 8; i++)
for (int j = 0; j &lt; 8; j++)
{
int n = board[i][j];
if (!n) continue;
int x = abs(n) - 1;
int y = n &gt; 0 ? 1 : 0;
f[k].setTextureRect(IntRect(size * x, size * y, size, size));
f[k].setPosition(size * j, size * i);
k++;
}
}
int main()
{
RenderWindow window(VideoMode(454, 455), &quot;SFML CHESS BOARD &quot;);
Texture t1, t2;
t1.loadFromFile(&quot;images/figures.png&quot;);
t2.loadFromFile(&quot;images/board0.png&quot;);
for (int i = 0; i &lt; 32; i++) f[i].setTexture(t1);
Sprite sBoard(t2);
loadPosition();
int n = 0;
while (window.isOpen())
{
Event e;
while (window.pollEvent(e))
if (e.type == Event::Closed)
window.close();
window.clear();
window.draw(sBoard);
for (int i = 0; i &lt; 32; i++) window.draw(f[i]); window.draw(f[n]);
window.display();
}
return 0;
}
