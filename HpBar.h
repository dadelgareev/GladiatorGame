#pragma once
#include <SFML/Graphics.hpp>
#include "gladiator.h" // Предполагается, что в этом заголовочном файле объявлен класс GladiatorPerson

class HpBar {
public:
    HpBar(const GladiatorPerson& gladiator) : m_gladiator(gladiator) {
        // Загрузка текстуры для полосы здоровья
        if (!m_texture.loadFromFile("hp_bar.png")) {
            // Обработка ошибки загрузки текстуры
            // Можно использовать стандартную текстуру вместо загруженной
            m_texture.create(100, 10); // Просто пример размера полосы здоровья
            m_texture.setSmooth(true);
        }
        m_sprite.setTexture(m_texture);
    }

    void draw(sf::RenderWindow& window) {
        // Устанавливаем размер полосы здоровья в зависимости от текущего HP
        float hpRatio = static_cast<float>(m_gladiator.getHp()) / m_gladiator.getMaxHp();
        m_sprite.setScale(hpRatio, 1.0f);

        // Отрисовываем полосу здоровья
        window.draw(m_sprite);
    }
    void setPosition(const sf::Vector2f& position) {
        m_sprite.setPosition(position);
    }

private:
    const GladiatorPerson& m_gladiator;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
