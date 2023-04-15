#include<SFML/Graphics.hpp>
#include<vector>
#include<thread>
#include<windows.h>
#include<iostream>

using namespace sf;
using namespace std;

int main() {

	RenderWindow window(VideoMode(1280,720),"SFML works!");

	int pos[300];

	vector<CircleShape> stars;

	Color color;

	float shapePos[300][2];

	for (int i = 0; i < 300; i++) {
		shapePos[i][0] = rand() % 1280 + 1;
		shapePos[i][1] = rand() % 720 + 1;

		CircleShape shape(2);
		shape.setFillColor(Color::White);
		shape.setPosition(shapePos[i][0],shapePos[i][1]);
		stars.push_back(shape);

	}

	while (window.isOpen()) {
		
		Event event;

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}

		}
			window.clear();

			for (int i = 0; i < 300; i++) {
			
				pos[i] = rand() % 250 + 1;

				if ((i%2==0)) {
					stars[pos[i]].setFillColor(Color::Black);
				}
				else {
					stars[pos[i]].setFillColor(Color::White);
				}

				window.draw(stars[i]);
			}

			window.display();
		
		}
	
	

	return 0;
}