#include <iostream>
#include "Bee.h"
#include "Hive.h"
#include "Garden.h"
#include <SFML/Graphics.hpp>

const int MAPSIZE = 1000;  // Largeur de la fenêtre
const int NBHIVES = 10;  // Nombre de ruches
const int BEECAPACITY = 100;  // Nombre maximum d'abeilles par ruche

int main() {
    sf::RenderWindow window(sf::VideoMode(MAPSIZE, MAPSIZE), "Bee Factory");
    sf::Event event{};

    // Creation jardin
    auto *garden = new Garden(BEECAPACITY, MAPSIZE);

    // Creation ruches
    garden->addHives(0, BEECAPACITY);

    // Creation abeilles
    garden->makeHivesFull();

    // Creation fleurs et calcul de la distance ruches
    garden->addFlowers(0, 10);

    // compute nearest flowers
    garden->calculateNearestFlowerForHives();

    // Add targets for bees
    garden->makeBeesFollowNearestFlower();


    // Boucle principale
    while (window.isOpen()) {
        //reset garden state
        garden->cleanSlateForTick();


        // Gestion des événements
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // check if mouse is clicked
            if (event.type == sf::Event::MouseButtonPressed) {
                // check if left mouse is clicked
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // get mouse position
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    // create new hive
                    Hive* newHive = new Hive(mousePos.x, mousePos.y, BEECAPACITY, MAPSIZE);
                    garden->addHive(newHive);
                    newHive->makeFull();
                }
                else {
                    if (event.mouseButton.button == sf::Mouse::Right) {
                        // get mouse position
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                        // create new flower
                        auto* newFlower = new Flower(mousePos.x, mousePos.y, 10);
                        garden->addFlower(newFlower);

                        // Make bees follow mouse
                        //garden->makeGardenFollow(mousePos.x, mousePos.y);
                    }
                }
            }
        }

        // Effacement de la fenêtre
        window.clear();

        //pick and drop pollens
        garden->checkBeesOnFlowerOrHive();

        //reassign bee targets
        garden->assignNewTargets();

        //bouger les abeilles
        garden->updateBeesPositions();

        // Dessin du jardin
        garden->draw(window);

        // Affichage de la fenêtre
        window.display();

        // Pause
        sf::sleep(sf::milliseconds(10));


        // print
        //garden.print();
    }

    // garden->print();
    delete garden;

    return 0;
}