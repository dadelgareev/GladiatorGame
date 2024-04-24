#pragma once
#include <SFML/Graphics.hpp>
#include "gladiator.h" // ��������������, ��� � ���� ������������ ����� �������� ����� GladiatorPerson

class HpBar {
public:
    HpBar(const GladiatorPerson& gladiator) : m_gladiator(gladiator) {
        // �������� �������� ��� ������ ��������
        if (!m_texture.loadFromFile("hp_bar.png")) {
            // ��������� ������ �������� ��������
            // ����� ������������ ����������� �������� ������ �����������
            m_texture.create(100, 10); // ������ ������ ������� ������ ��������
            m_texture.setSmooth(true);
        }
        m_sprite.setTexture(m_texture);
    }

    void draw(sf::RenderWindow& window) {
        // ������������� ������ ������ �������� � ����������� �� �������� HP
        float hpRatio = static_cast<float>(m_gladiator.getHp()) / m_gladiator.getMaxHp();
        m_sprite.setScale(hpRatio, 1.0f);

        // ������������ ������ ��������
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
