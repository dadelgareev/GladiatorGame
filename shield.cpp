#include "shield.h"

// Реализация конструктора базового класса Shield
Shield::Shield(const std::string& name, int defense) : m_name(name), m_defense(defense) {}

// Реализация деструктора базового класса Shield
Shield::~Shield() {}

// Реализация метода getDefense() базового класса Shield
int Shield::getDefense() const {
    return m_defense;
}

// Реализация метода getName() базового класса Shield
std::string Shield::getName() const {
    return m_name;
}

// Реализация конструктора класса WoodenShield
WoodenShield::WoodenShield(const std::string& name, int defense) : Shield(name, defense) {
    loadTexture("woodenShield.png"); //
}

// Реализация конструктора класса IronShield
IronShield::IronShield(const std::string& name, int defense) : Shield(name, defense) {
    loadTexture("ironShield.png"); //
}

// Реализация конструктора класса NoShield
NoShield::NoShield(const std::string& name, int defense) : Shield(name, defense) {}

void Shield::loadTexture(const std::string& filename) {
    if (!shieldTexture.loadFromFile(filename)) {
        throw std::runtime_error("Failed to load shield texture: " + filename);
    }
    sprite.setTexture(shieldTexture);
}

void Shield::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void Shield::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}