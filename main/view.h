#include <SFML/Graphics.hpp>

using namespace sf;

sf::View view;

void ChangeRotate_0(int k, int x, int y, int i)
{
	if (k != 1)
	{
		view.setCenter(x, y);
		view.setRotation(180-i);
	}
	else
	{
	view.setRotation(i);
	}
}