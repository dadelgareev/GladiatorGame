#ifndef SHIELD_H
#define SHIELD_H

#include <string>
#include <SFML/Graphics.hpp>

// ������� ����� ���
class Shield {
public:
    Shield(const std::string& name, int defense);
    virtual ~Shield();

    int getDefense() const;
    std::string getName() const;

    // ��������� �������� ����
    virtual void loadTexture(const std::string& filename);

    // ���������� ���
    virtual void draw(sf::RenderWindow& window);
    virtual void setPosition(const sf::Vector2f& position);

protected:
    std::string m_name;
    int m_defense;
    sf::Sprite sprite;
    sf::Texture shieldTexture;
};

// ����� ���������� ���
class WoodenShield : public Shield {
public:
    WoodenShield(const std::string& name, int defense);
};

// ����� ������� �������� ���
class IronShield : public Shield {
public:
    IronShield(const std::string& name, int defense);
};

// ����� ��� ����
class NoShield : public Shield {
public:
    NoShield(const std::string& name, int defense);
};

#endif // SHIELD_H
