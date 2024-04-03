//
// Created by hanil on 12/5/2023.
//

#include "RoundedRectangleShape.h"
////////////////////////////////////////////////////////////
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "RoundedRectangleShape.h"
#include <cmath>


////////////////////////////////////////////////////////////
    RoundedRectangleShape::RoundedRectangleShape(const sf::Vector2f& size, float radius, unsigned int cornerPointCount)
    {
        mySize = size;
        myRadius = radius;
        myCornerPointCount = cornerPointCount;
        sf::Shape::update();
    }

////////////////////////////////////////////////////////////
    void RoundedRectangleShape::setSize(const sf::Vector2f& size)
    {
        mySize = size;
        sf::Shape::update();
    }

////////////////////////////////////////////////////////////
    const sf::Vector2f& RoundedRectangleShape::getSize() const
    {
        return mySize;
    }

////////////////////////////////////////////////////////////
    void RoundedRectangleShape::setCornersRadius(float radius)
    {
        myRadius = radius;
        sf::Shape::update();
    }

////////////////////////////////////////////////////////////
    float RoundedRectangleShape::getCornersRadius() const
    {
        return myRadius;
    }

////////////////////////////////////////////////////////////
    void RoundedRectangleShape::setCornerPointCount(unsigned int count)
    {
        myCornerPointCount = count;
        sf::Shape::update();
    }

////////////////////////////////////////////////////////////
    std::size_t RoundedRectangleShape::getPointCount() const
    {
        return myCornerPointCount*4;
    }

////////////////////////////////////////////////////////////
    sf::Vector2f RoundedRectangleShape::getPoint(std::size_t index) const
    {
        if(index >= myCornerPointCount*4)
            return sf::Vector2f(0,0);

        float deltaAngle = 90.0f/(myCornerPointCount-1);
        sf::Vector2f center;
        unsigned int centerIndex = index/myCornerPointCount;
        static const float pi = 3.141592654f;

        switch(centerIndex)
        {
            case 0: center.x = mySize.x - myRadius; center.y = myRadius; break;
            case 1: center.x = myRadius; center.y = myRadius; break;
            case 2: center.x = myRadius; center.y = mySize.y - myRadius; break;
            case 3: center.x = mySize.x - myRadius; center.y = mySize.y - myRadius; break;
        }

        return sf::Vector2f(myRadius*cos(deltaAngle*(index-centerIndex)*pi/180)+center.x,
                            -myRadius*sin(deltaAngle*(index-centerIndex)*pi/180)+center.y);
    }

//RoundedRectangleShape::RoundedRectangleShape() {
//    mySize = sf::Vector2f{100,100};
//    myRadius = 5;
//    myCornerPointCount = 20;
//    sf::Shape::update();
//}
