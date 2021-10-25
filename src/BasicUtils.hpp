#ifndef BASICUTILS_HPP
#define BASICUTILS_HPP

#include "../inc/common.hpp"

class BasicUtils {
private:
    // Required for time util.
	sf::Clock clock;
    sf::Time dt;
	float dtAsSeconds;
public:
    // Init class.
	BasicUtils();
	~BasicUtils();

    // General util functions.
    int getRandomInt(int x, int y);
    sf::Vector2f getRectCenter(sf::RectangleShape);
    void setTime();
    std::vector<std::string> getFileLines(std::string);

    // Required for time util.
    // Getter.
	float getTime();
};

#endif
