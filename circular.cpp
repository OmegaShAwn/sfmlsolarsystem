#include<SFML/Graphics.hpp>
#include<iostream>
#include<cmath>
using namespace sf;

class planets{
	public:
	static int i;
	CircleShape s;
	float x, y, a, n, acc;
	planets(){
		i++;
		n = i;
		acc = rand()%9+1;
		acc = acc/3000;
		s.setRadius(11-n);
		a = 90;
		s.setFillColor(Color(rand()%255, rand()%255, rand()%255));
	}
	void setpos(){
		a = a + acc;
		x = 400-11+n + cos(a)*((9-n)*40+50);
		y = 300-11+n + sin(a)*((9-n)*20+50);
		s.setPosition(x,y);
	}
};
int planets::i = 0;
class stars{
	public:
	CircleShape s;
	float x,y;
	stars(){
		s.setRadius(1);
		x = rand()%800;
		y = rand()%800;
		s.setPosition(x,y);
	}
};

int main(){
	srand(time(0));
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(800, 600), "circular", Style::Default, settings);
	CircleShape s(50);
	s.setFillColor(Color::Yellow);
	s.setPosition(350, 250);
	stars st[50];
	planets pl[8];

	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed)
				window.close();
		}
		window.clear();
		for(int i = 0; i < 50; i++){
			st[i].x -= .02;
			if(st[i].x <= 0)
				st[i].x = 800;
			st[i].s.setPosition(st[i].x,st[i].y);
			window.draw(st[i].s);
		}
		for(int i = 0; i < 8; i++){
			pl[i].setpos();
			window.draw(pl[i].s);
		}
		window.draw(s);
		window.display();
	}
}
