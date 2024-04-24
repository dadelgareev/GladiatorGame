#ifndef GLADIATOR_H
#define GLADIATOR_H

#include <string>
#include <SFML/Graphics.hpp>

class GladiatorPerson {
public:
    GladiatorPerson(const std::string& name, int damage);
    virtual ~GladiatorPerson();

    int getHp() const;
    int getMaxHp() const;
    std::string getName() const;
    // ��������� �������� ������
    virtual void loadTexture(const std::string& filename);

    // ���������� ������
    virtual void draw(sf::RenderWindow& window);

    virtual void setPosition(const sf::Vector2f& position);

protected:
    std::string m_name;
    int m_hp;
    int m_maxhp;
    sf::Sprite sprite;
    sf::Texture gladiatorTexture;
};

// ����� ���
class Warrior : public GladiatorPerson {
public:
    Warrior(const std::string& name, int damage);
};

// ����� ���
class Bower : public GladiatorPerson {
public:
    Bower(const std::string& name, int damage);
};

// ����� ������
class Assasin : public GladiatorPerson {
public:
    Assasin(const std::string& name, int damage);
};

// ����� �����
class Gladiator : public GladiatorPerson {
public:
    Gladiator(const std::string& name, int damage);
};

#endif // GLADIATOR_H
