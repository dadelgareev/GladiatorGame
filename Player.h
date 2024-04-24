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
        // ������� ������ HpBar �� ������ ����������� ����������
        hpBar = new HpBar(*gladiator);
    }
    Player() {}

    void update(float deltaTime) {
        // ������: ����������� ������ �� �����������
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

        // ������ ������
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround()) {
            verticalVelocity = -jumpForce;
            isJumping = true;
        }

        // ��������� ������� ������ �� ������ ������������ ��������
        sprite.move(0, verticalVelocity * deltaTime);

        // ��������� ����������
        applyGravity(deltaTime);



        // ������: ���������� �������� (����� ��������)
        // animation.update(deltaTime);

        // ������: ������ ���������� (��������, �������� ��������)
        // updateCollisions();


    }

    void draw(sf::RenderWindow& window) {

        if (gladiator != nullptr) {
            gladiator->draw(window);
            gladiator->setPosition(sprite.getPosition());
        }
        // ��������� ������ � ����
        if (weapon != nullptr) {
            weapon->setPosition(sprite.getPosition() + weaponOffset);
            weapon->draw(window);
        }
        if (shield != nullptr) {
            shield->setPosition(sprite.getPosition() + shieldOffset);
            shield->draw(window);
        }
        // ������������ HpBar
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

    Weapon* weapon = nullptr; // ��������� �� ������
    Shield* shield = nullptr; // ��������� �� ���
    GladiatorPerson* gladiator = nullptr;
    HpBar* hpBar = nullptr; // ��������� �� ������ HpBar


    sf::Vector2f weaponOffset = sf::Vector2f(90, 45); // �������� ������ ������������ ���������
    sf::Vector2f shieldOffset = sf::Vector2f(-10, 50); // �������� ���� ������������ ���������
    sf::Vector2f hpBarOffset = sf::Vector2f(20,-40); // �������� ������� ��

    float speed = 100.0f; // �������� ����������� ������

    // ������ ���������� � ��������, ���� �����
    float jumpSpeed = 500.0f; // �������� ������������� ����������� �� ����� ������
    float jumpForce = 1000.0f; // ���� ������
    float gravity = 1200.0f; // ����������

    float verticalVelocity = 0.0f; // ������������ �������� ������
    bool isJumping = false; // ����, �����������, ����������� �� ������

    bool isOnGround() const {
        // ���������, ��������� �� ������ ������� ������� �� ������ 800 �������� ��� ����
        return sprite.getPosition().y >=450;
    }

    void applyGravity(float deltaTime) {
        if (!isOnGround() && isJumping) {
            // ��������� ����������, ���� ����� ��������� � ������� � ��������� ������
            verticalVelocity += gravity * deltaTime;
        }
        else {
            // ���������� ������������ ��������, ���� ����� �� �����
            verticalVelocity = 0.0f;
            isJumping = false;
        }
    }
};
