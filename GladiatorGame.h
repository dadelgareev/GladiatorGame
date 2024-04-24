#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "weapon.h"
#include "shield.h"
#include "gladiator.h"
#include <iostream>


class GladiatorGame {
public:
    GladiatorGame() : window(sf::VideoMode(800, 600), "Gladiator Game"), weapon(nullptr), shield(nullptr) {
        // Загрузка текстуры фона
        if (!backgroundTexture.loadFromFile("background.png")) {
            // Обработка ошибки загрузки текстуры фона
            std::cerr << "Failed to load background texture!" << std::endl;
            // Можно добавить логику в случае неудачной загрузки текстуры
        }
        background.setTexture(backgroundTexture);
        //background.setScale(window.getSize().x / backgroundTexture.getSize().x, window.getSize().y / backgroundTexture.getSize().y);


        // Создание оружия и щита
        weapon = new Sword("Excalibur", 20);
        shield = new WoodenShield("Oak Shield", 15);
        gladiator = new Assasin("Assasin", 75);

        player = Player(playerTexture, sf::Vector2f(100, 100), weapon, shield, gladiator);
        
        player.setPosition(sf::Vector2f(0, 450));
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    sf::Texture playerTexture; // Текстура спрайта игрока
    Player player; // Объект игрока
    sf::Clock clock;
    Weapon* weapon;
    Shield* shield;
    GladiatorPerson* gladiator;
    sf::Texture backgroundTexture; // Текстура фона
    sf::Sprite background;

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    void update() {
        // Здесь можно обновлять все состояния игры, например, позиции объектов и проверки коллизий
        sf::Time deltaTime = clock.restart(); // Получаем время, прошедшее с предыдущего кадра
        float deltaTimeSeconds = deltaTime.asSeconds(); // Преобразуем время в секунды
        player.update(deltaTimeSeconds);
    }

    void render() {
        
        window.clear(sf::Color::White);
        window.draw(background);
        player.draw(window);

        window.display();

    }
};
