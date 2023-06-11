#include <iostream>
#include "Bee.h"
#include "Hive.h"
#include "Garden.h"
#include <SFML/Graphics.hpp>

const int MAPSIZE = 1000;  // Largeur de la fenêtre


int main() {
    sf::RenderWindow window(sf::VideoMode(MAPSIZE, MAPSIZE), "Simulation");
    sf::Event event;

    // Creation jardin
    Garden *garden = new Garden(10, MAPSIZE);

    // Creation ruche
    garden->addHives(10, 1000);

    // Creation abeilles
    garden->makeHivesFull();


    // Boucle principale
    while (window.isOpen()) {
        // Gestion des événements
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacement de la fenêtre
        window.clear();

        // Dessin du jardin
        garden->draw(window);

        // Affichage de la fenêtre
        window.display();

        // Pause
        sf::sleep(sf::milliseconds(10));

        // Mise à jour du jardin
        garden->update();

        // print
        //garden.print();
    }

    delete garden;

    return 0;
}