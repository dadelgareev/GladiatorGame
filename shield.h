#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include <SFML/Graphics.hpp>

// Базовый класс Щит
class Shield {
public:
    Shield(const std::string& name, int defense);
    virtual ~Shield();

    int getDefense() const;
    std::string getName() const;

    // Загрузить текстуру щита
    virtual void loadTexture(const std::string& filename);

    // Отрисовать щит
    virtual void draw(sf::RenderWindow& window);
    virtual void setPosition(const sf::Vector2f& position);

protected:
    std::string m_name;
    int m_defense;
    sf::Sprite sprite;
    sf::Texture shieldTexture;
};

// Класс Деревянный Щит
class WoodenShield : public Shield {
public:
    WoodenShield(const std::string& name, int defense);
};

// Класс Большой Железный Щит
class IronShield : public Shield {
public:
    IronShield(const std::string& name, int defense);
};

// Класс Без Щита
class NoShield : public Shield {
public:
    NoShield(const std::string& name, int defense);
};

#endif // SHIELD_H
