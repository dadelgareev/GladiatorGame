#pragma once
#include <SFML/Graphics.hpp>
#include "weapon.h"
#include "shield.h"
#include "gladiator.h"
#include "HpBar.h"
#include <iostream>

class Player {
public:
    Player(sf::Texture& texture, sf::Vector2f position, Weapon* weapon, Shield* shield, GladiatorPerson* gladiator) 
        : weapon(weapon), shield(shield), gladiator(gladiator) {
        // Создаем объект HpBar на основе переданного гладиатора
        hpBar = new HpBar(*gladiator);
    }
    Player() {}

    void update(float deltaTime) {
        // Пример: перемещение игрока по горизонтали
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            sprite.move(-speed * deltaTime, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            sprite.move(speed * deltaTime, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sprite.move(0, speed * deltaTime);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sprite.move(0, -speed * deltaTime);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            std::cout << sprite.getPosition().x << std::endl;
            std::cout << sprite.getPosition().y << std::endl;

        }

        // Прыжок игрока
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround()) {
            verticalVelocity = -jumpForce;
            isJumping = true;
        }

        // Обновляем позицию игрока на основе вертикальной скорости
        sprite.move(0, verticalVelocity * deltaTime);

        // Применяем гравитацию
        applyGravity(deltaTime);



        // Пример: обновление анимации (можно добавить)
        // animation.update(deltaTime);

        // Пример: прочие обновления (например, проверка коллизий)
        // updateCollisions();


    }

    void draw(sf::RenderWindow& window) {

        if (gladiator != nullptr) {
            gladiator->draw(window);
            gladiator->setPosition(sprite.getPosition());
        }
        // Отрисовка оружия и щита
        if (weapon != nullptr) {
            weapon->setPosition(sprite.getPosition() + weaponOffset);
            weapon->draw(window);
        }
        if (shield != nullptr) {
            shield->setPosition(sprite.getPosition() + shieldOffset);
            shield->draw(window);
        }
        // Отрисовываем HpBar
        if (hpBar != nullptr) {
            hpBar->draw(window);
            hpBar->setPosition(sprite.getPosition() + hpBarOffset);
        }

    }

    sf::FloatRect getGlobalBounds() const {
        return sprite.getGlobalBounds();
    }

    void setPosition(const sf::Vector2f& position) {
        sprite.setPosition(position);
    }

private:
    sf::Sprite sprite;
    sf::Texture playerTexture;

    Weapon* weapon = nullptr; // Указатель на оружие
    Shield* shield = nullptr; // Указатель на щит
    GladiatorPerson* gladiator = nullptr;
    HpBar* hpBar = nullptr; // Указатель на объект HpBar


    sf::Vector2f weaponOffset = sf::Vector2f(90, 45); // Смещение оружия относительно персонажа
    sf::Vector2f shieldOffset = sf::Vector2f(-10, 50); // Смещение щита относительно персонажа
    sf::Vector2f hpBarOffset = sf::Vector2f(20,-40); // Смещение полоски хп

    float speed = 100.0f; // Скорость перемещения игрока

    // Другие переменные и свойства, если нужно
    float jumpSpeed = 500.0f; // Скорость вертикального перемещения во время прыжка
    float jumpForce = 1000.0f; // Сила прыжка
    float gravity = 1200.0f; // Гравитация

    float verticalVelocity = 0.0f; // Вертикальная скорость игрока
    bool isJumping = false; // Флаг, указывающий, выполняется ли прыжок

    bool isOnGround() const {
        // Проверяем, находится ли нижняя граница спрайта на высоте 800 пикселей или выше
        return sprite.getPosition().y >=450;
    }

    void applyGravity(float deltaTime) {
        if (!isOnGround() && isJumping) {
            // Применяем гравитацию, если игрок находится в воздухе и выполняет прыжок
            verticalVelocity += gravity * deltaTime;
        }
        else {
            // Сбрасываем вертикальную скорость, если игрок на земле
            verticalVelocity = 0.0f;
            isJumping = false;
        }
    }
};
