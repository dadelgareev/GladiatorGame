#include "gladiator.h"

// ����������� ������ GladiatorPerson
GladiatorPerson::GladiatorPerson(const std::string& name, int damage)
    : m_name(name), m_hp(100), m_maxhp(m_hp)
{
}

// ���������� ������ GladiatorPerson
GladiatorPerson::~GladiatorPerson()
{
    // ��� ������������� � ����� �������� ��������, ��� ��� SFML ��������� ������� �� ���
}

// ����� ��� ��������� �������� ��������
int GladiatorPerson::getHp() const
{
    return m_hp;
}
int GladiatorPerson::getMaxHp() const
{
    return m_maxhp;
}

// ����� ��� ��������� �����
std::string GladiatorPerson::getName() const
{
    return m_name;
}

// ����� ��� �������� �������� ������
void GladiatorPerson::loadTexture(const std::string& filename)
{
    gladiatorTexture.loadFromFile(filename);
    sprite.setTexture(gladiatorTexture);
}

// ����� ��� ��������� ������
void GladiatorPerson::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// ����� ��� ��������� ������� ������
void GladiatorPerson::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

// ����������� ������ Warrior
Warrior::Warrior(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    // �������������� ������������� ��� ������ Warrior, ���� ����������
    loadTexture("warrior.png"); //
}

// ����������� ������ Bower
Bower::Bower(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("bower.png");
    // �������������� ������������� ��� ������ Bower, ���� ����������
}

// ����������� ������ Assasin
Assasin::Assasin(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("assasin.png");
    // �������������� ������������� ��� ������ Assasin, ���� ����������
}

// ����������� ������ Gladiator
Gladiator::Gladiator(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("gladiator.png");
    // �������������� ������������� ��� ������ Gladiator, ���� ����������
}
