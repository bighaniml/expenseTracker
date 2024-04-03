//
// Created by hanil on 12/9/2023.
//

#ifndef SFML_PROJECTS_TRANSACTION_H
#define SFML_PROJECTS_TRANSACTION_H
#include "GuiComponent.h"
#include "Font.h"
#include "helper.h"
#include "InputBox.h"


class Transaction: public GuiComponent {
private:
    //box
    sf::RectangleShape box;
    //colors
    sf::Color teal = sf::Color(77, 173, 153);
    sf::Color lightGrey = sf::Color(250, 250, 250);
    sf::Color darkGrey = sf::Color(80, 80, 80);
    sf::Color mediumGrey = sf::Color(237, 237, 237);
    sf::Color darkMediumGrey = sf::Color(200, 200, 200);
    //things
    std::string amount = "0.00";
    std::string date = "01/01/2023";
    std::string category = "Food";
    std::string type = "Expense";
    std::string note = "Mcdonalds Chicken Nuggets";
    InputBox amountLabel;
    InputBox dateLabel;
    InputBox categoryLabel;
    InputBox typeLabel;
    InputBox noteLabel;

public:
    //constructors
    Transaction(const std::string &amount, const std::string &date, const std::string &category,
                const std::string &type, const std::string &note);

    Transaction();

    //setUp
    void setUp();
    void setPosition(const sf::Vector2f& position);
    //setters and getters
    void setAmount(const std::string &amount);

    void setDate(const std::string &date);

    void setCategory(const std::string &category);

    void setType(const std::string &type);

    void setNote(const std::string &note);

    const std::string &getAmount() const;

    const std::string &getDate() const;

    const std::string &getCategory() const;

    const std::string &getType() const;

    const std::string &getNote() const;

    sf::FloatRect getGlobalBounds() const;

    //override functions
    Snapshot &getSnapshot() override;

    void applySnapshot(const Snapshot &snapshot) override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void operator=(const Transaction& rhs);
};


#endif //SFML_PROJECTS_TRANSACTION_H
