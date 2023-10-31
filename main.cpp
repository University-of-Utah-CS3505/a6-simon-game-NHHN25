#include "mainwindow.h"

#include <QApplication>
/**
 * @authors Names: Nam Nguyen and Thomas Kuhrke Limia
 * @authors GitHubs: NHHN25 and T-K-L
 *
 * @title Assignment 6: Qt Simon Game
 *
 * @brief main the creative element is a "nightmare mode", which swaps the positions between the red and blue buttons on each button click. It also
 * shows the professor's face when the player loses instead of a "Game Over" message.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    MainWindow w(&model);
    w.show();
    return a.exec();
}
