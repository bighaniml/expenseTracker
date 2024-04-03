//
// Created by hanil on 11/16/2023.
//

#ifndef SFML_PROJECTS_TEXTINPUT_H
#define SFML_PROJECTS_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include "GuiComponent.h"
#include "States.h"
#include "MouseEvents.h"
#include "helper.h"
#include "MultiText.h"
#include "KeyShortcuts.h"
#include "Position.h"
class TextInput: public GuiComponent{
public:
    //allows you to set label position above, left-beside, or below inputbox
    void orientLabel(const Position& position);
    //virtual void snapShotInterface functions
    Snapshot &getSnapshot();
    void applySnapshot(const Snapshot &snapshot);
    //virtual void EventHandler functions
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    //drawable virtual void functions
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);
    void setLabel(const std::string& label);
    void setLabelSize(int size);
    void setLabelColor(const sf::Color& color);
    void clear();
    std::string getLabel();
    void setCursorY(int y);
    int getCursorHeight();
    sf::FloatRect boxGetGlobalBounds() const;
    sf::FloatRect labelGlobalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    TextInput();
    std::string listToString();

private:
    Position orientation = LEFT;
    sf::Clock clock;
    States cursorState;
    sf::RectangleShape cursor;
    sf::RectangleShape textBox;
    sf::Text label;
    std::string labelString = "INPUT: ";
    MultiText text;
    int labelMargin = 20;

    //make cursor blink
    void blinkCursor();
    void hideCursor();
    //move cursor when type
    void moveCursor();
    int findInt(const std::string& string);
    int findDouble(const std::string& string);
    int findChar(const std::string& string);
    int findFloat(const std::string& string);
    void turnBlue(int start, int length);
    void turnIntBlue();
    void turnDoubleBlue();
    void turnCharBlue();
    void turnFloatBlue();
    void turnNumGreen();
    void turnOpRed();





    bool isOp(char letter);
};


#endif //SFML_PROJECTS_TEXTINPUT_H
