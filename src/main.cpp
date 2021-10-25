//include classes and headers
#include "../inc/common.hpp"
#include "BasicUtils.hpp"

class Base {
private:
    BasicUtils ut;

    sf::RenderWindow window;
    std::vector<sf::ConvexShape> shapes;
    std::vector<sf::Color> colors = {sf::Color::Black, sf::Color::White,
        sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow,
        sf::Color::Magenta, sf::Color::Cyan
    };

public:
    void createWindow();
    void createShapes();

    bool gameLoop();

    int getRandomInt(int x, int y);
};

void Base::createWindow() {
    window.create(sf::VideoMode(1600 , 900), "SFML works!"/*, sf::Style::Fullscreen*/);
}

void Base::createShapes() {
    int runs = getRandomInt(1, 1);

    for(int i = 0; i < runs; i++) {
        //int radius = getRandomInt(1, 100);
        int pointCount = getRandomInt(3, 30);
        int rotation = getRandomInt(0, 360);
        //int outlineThickness = getRandomInt(0, radius / 2/*1*/);

        sf::Vector2f position = sf::Vector2f(getRandomInt(0, window.getSize().x), getRandomInt(0, window.getSize().y));

        sf::Color fillColor = colors[getRandomInt(0, colors.size() - 1)];
        //sf::Color outlineColor = colors[getRandomInt(0, colors.size() - 1)];

        sf::ConvexShape tmp;
        tmp.setPointCount(pointCount);

        for(int i = 0; i < pointCount; i++) {
            tmp.setPoint(i, sf::Vector2f(getRandomInt(0, window.getSize().x), getRandomInt(0, window.getSize().y)));
        }

        tmp.setRotation(rotation);
        //tmp.setOutlineThickness(outlineThickness);

        tmp.setPosition(position);

        tmp.setFillColor(fillColor);
        //tmp.setOutlineColor(outlineColor);

        shapes.push_back(tmp);

        if(shapes.size() >= 1000000) {
            shapes.erase(shapes.begin());
        }
    }

    /*
    old shapes
    for(int i = 0; i < runs; i++) {
        int radius = getRandomInt(1, 100);
        int pointCount = getRandomInt(3, 30);
        int rotation = getRandomInt(0, 360);
        int outlineThickness = getRandomInt(0, radius / 2/*1*);

        sf::Vector2f position = sf::Vector2f(getRandomInt(0, window.getSize().x), getRandomInt(0, window.getSize().y));

        sf::Color fillColor = colors[getRandomInt(0, colors.size() - 1)];
        sf::Color outlineColor = colors[getRandomInt(0, colors.size() - 1)];

        sf::CircleShape tmp(radius, pointCount);
        tmp.setRotation(rotation);
        tmp.setOutlineThickness(outlineThickness);

        tmp.setPosition(position);

        tmp.setFillColor(fillColor);
        tmp.setOutlineColor(outlineColor);

        shapes.push_back(tmp);

        if(shapes.size() >= 1000000) {
            shapes.erase(shapes.begin());
        }
    }
    */

}

bool Base::gameLoop() {
    ut.setTime();
    //totalTime += ut.getTime();

    //createShapes();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
            return 1;
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                createShapes();
            }
        }
    }

    // Controls.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {createShapes();}
    //if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}

    window.clear(sf::Color::Black);

    for(auto x : shapes) {window.draw(x);}
    //for(auto x : jigSawPieces) {}

    window.display();

    return 0;
}

int Base::getRandomInt(int x, int y) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(x, y);

    return distribution(generator);
}

int main() {

    Base b;
    b.createWindow();

    bool exit = 0;
    while(exit == 0) {
        exit = b.gameLoop();
    }

    // Exit program.
    return 0;
}
