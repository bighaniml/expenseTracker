//
// Created by hanil on 4/25/2023.
//

#include "Font.h"

std::map<fonts,sf::Font> Font::font;
sf::Font &Font::getFont(fonts f) {
    loadFont(f);
    return font.find(f)->second;
}

std::string Font::getPath(fonts f) {
    switch (f) {
        case(BUTTON):
            return "Font/OpenSans-Bold.ttf";
        case(WIDGET):
            return "Font/Montserrat-ExtraLight.ttf";
        case(WIDGET_BOLD):
            return "Font/Montserrat-Bold.ttf";
        case(WIDGET_SEMI_BOLD):
            return "Font/Montserrat-SemiBold.ttf";
        case(WIDGET_EXTRA_BOLD):
            return "Font/Montserrat-ExtraBold.ttf";
        case(WIDGET_REGULAR):
            return "Font/Montserrat-Regular.ttf";
    }
}

void Font::loadFont(fonts f) {
    sf::Font f1;
    f1.loadFromFile(getPath(f));
    if(font.count(f) == 0){
        font.insert({f, f1});
    }
}
