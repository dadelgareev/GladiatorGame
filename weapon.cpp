#include "weapon.h"

// ���������� ������������ �������� ������ Weapon
Weapon::Weapon(const std::string& name, int damage) : m_name(name), m_damage(damage) {}

// ���������� ����������� �������� ������ Weapon
Weapon::~Weapon() {}

// ���������� ������ getDamage() �������� ������ Weapon
int Weapon::getDamage() const {
    return m_damage;
}

// ���������� ������ getName() �������� ������ Weapon
std::string Weapon::getName() const {
    return m_name;
}

// ���������� ������������ ������ Sword
Sword::Sword(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("sword.png"); // ���� � ����� � ��������� ����
}

// ���������� ������������ ������ Bow
Bow::Bow(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("bow.png"); //
}

// ���������� ������������ ������ Dagger
Dagger::Dagger(const std::string& name, int damage) : Weapon(name, damage) {
    loadTexture("dagger.png"); //
}

// ���������� ������������ ������ Spear
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