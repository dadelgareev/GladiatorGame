#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <SFML/Graphics.hpp>

// ������� ����� ������
class Weapon {
public:
    Weapon(const std::string& name, int damage);
    virtual ~Weapon();

    int getDamage() const;
    std::string getName() const;
    // ��������� �������� ������
    virtual void loadTexture(const std::string& filename);

    // ���������� ������
    virtual void draw(sf::RenderWindow& window);

    virtual void setPosition(const sf::Vector2f& position);

protected:
    std::string m_name;
    int m_damage;
    sf::Sprite sprite;
    sf::Texture weaponTexture;
};

// ����� ���
class Sword : public Weapon {
public:
    Sword(const std::string& name, int damage);
};

// ����� ���
class Bow : public Weapon {
public:
    Bow(const std::string& name, int damage);
};

// ����� ������
class Dagger : public Weapon {
public:
    Dagger(const std::string& name, int damage);
};

// ����� �����
class Spear : public Weapon {
public:
    Spear(const std::string& name, int damage);
};


#endif // WEAPON_H
