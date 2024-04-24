#include "weapon.h"

// Реализация конструктора базового класса Weapon
Weapon::Weapon(const std::string& name, int damage) : m_name(name), m_damage(damage) {}

// Реализация деструктора базового класса Weapon
Weapon::~Weapon() {}

// Реализация метода getDamage() базового класса Weapon
int Weapon::getDamage() const {
    return m_damage;
}

// Реализация метода getName() базового класса Weapon
std::string Weapon::getName() const {
    return m_name;
}

// Реализация конструктора класса Sword
Sword::Sword(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("sword.png"); // Путь к файлу с текстурой меча
}

// Реализация конструктора класса Bow
Bow::Bow(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("bow.png"); //
}

// Реализация конструктора класса Dagger
Dagger::Dagger(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("dagger.png"); //
}

// Реализация конструктора класса Spear
Spear::Spear(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("spear.png"); //
}

void Weapon::loadTexture(const std::string& filename) {
    if (!weaponTexture.loadFromFile(filename)) {
        throw std::runtime_error("Failed to load weapon texture: " + filename);
    }
    sprite.setTexture(weaponTexture);
}

void Weapon::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void Weapon::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}