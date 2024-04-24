#include "gladiator.h"

// Конструктор класса GladiatorPerson
GladiatorPerson::GladiatorPerson(const std::string& name, int damage)
    : m_name(name), m_hp(100), m_maxhp(m_hp)
{
}

// Деструктор класса GladiatorPerson
GladiatorPerson::~GladiatorPerson()
{
    // Нет необходимости в явном удалении текстуры, так как SFML управляет памятью за нас
}

// Метод для получения текущего здоровья
int GladiatorPerson::getHp() const
{
    return m_hp;
}
int GladiatorPerson::getMaxHp() const
{
    return m_maxhp;
}

// Метод для получения имени
std::string GladiatorPerson::getName() const
{
    return m_name;
}

// Метод для загрузки текстуры оружия
void GladiatorPerson::loadTexture(const std::string& filename)
{
    gladiatorTexture.loadFromFile(filename);
    sprite.setTexture(gladiatorTexture);
}

// Метод для отрисовки оружия
void GladiatorPerson::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

// Метод для установки позиции оружия
void GladiatorPerson::setPosition(const sf::Vector2f& position)
{
    sprite.setPosition(position);
}

// Конструктор класса Warrior
Warrior::Warrior(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    // Дополнительная инициализация для класса Warrior, если необходимо
    loadTexture("warrior.png"); //
}

// Конструктор класса Bower
Bower::Bower(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("bower.png");
    // Дополнительная инициализация для класса Bower, если необходимо
}

// Конструктор класса Assasin
Assasin::Assasin(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("assasin.png");
    // Дополнительная инициализация для класса Assasin, если необходимо
}

// Конструктор класса Gladiator
Gladiator::Gladiator(const std::string& name, int damage)
    : GladiatorPerson(name, damage)
{
    loadTexture("gladiator.png");
    // Дополнительная инициализация для класса Gladiator, если необходимо
}
