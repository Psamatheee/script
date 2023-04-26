#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Stretch!");
    double window_x = window.getSize().x;
    double window_y = window.getSize().y;

    sf::Color bg_colour{252, 236, 134};
    sf::Color other_colour{247, 88, 100};

    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("STRETCH");
    text.setFillColor(other_colour);
    text.setCharacterSize(150);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(window_x/2, window_y/2);

    sf::RectangleShape rect(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    rect.setFillColor(bg_colour);
    rect.setOrigin(rect.getSize().x /2 , rect.getSize().y/2);
    rect.setPosition(window_x/2.0, window_y/2.0);

    bool change = true;
    sf::Clock clock;

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
        }

        if(change){
            window.clear(other_colour);
        }else{
            window.clear(bg_colour);
        }

        if(clock.getElapsedTime().asSeconds() > 0.2){
            if(change){
                window.clear(bg_colour);
                text.setFillColor(bg_colour);
                rect.setFillColor(other_colour);
                change = false;

            } else{
                window.clear(other_colour);
                text.setFillColor(other_colour);
                rect.setFillColor(bg_colour);
                change = true;
            }

            clock.restart();
        }

        window.draw(rect);
        window.draw(text);
        window.display();
    }
}
