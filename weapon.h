#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <SFML/Graphics.hpp>

// Базовый класс Оружие
class Weapon {
public:
    Weapon(const std::string& name, int damage);
    virtual ~Weapon();

    int getDamage() const;
    std::string getName() const;
    // Загрузить текстуру оружия
    virtual void loadTexture(const std::string& filename);

    // Отрисовать оружие
    virtual void draw(sf::RenderWindow& window);

    virtual void setPosition(const sf::Vector2f& position);

protected:
    std::string m_name;
    int m_damage;
    sf::Sprite sprite;
    sf::Texture weaponTexture;
};

// Класс Меч
class Sword : public Weapon {
public:
    Sword(const std::string& name, int damage);
};

// Класс Лук
class Bow : public Weapon {
public:
    Bow(const std::string& name, int damage);
};

// Класс Кинжал
class Dagger : public Weapon {
public:
    Dagger(const std::string& name, int damage);
};

// Класс Копье
class Spear : public Weapon {
public:
    Spear(const std::string& name, int damage);
};


#endif // WEAPON_H
