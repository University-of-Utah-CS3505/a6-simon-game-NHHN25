#include "Model.h"
#include <QRandomGenerator>

Model::Model(QObject *parent) : QObject(parent){}

//*** TODO LIST ***
// - Determine whether the speed of the game should be saved on model or view.
//      - Start it and implement it properly in model if that is decided.
// - Implement the increaseGameSpeed Method.

void Model::startGame(){
    //Sets everything to default and adds the initial color to the current pattern
    currentPattern = currentPattern.empty();
    gameSpeed = QTimer::setTimerType(Qt::PreciseTimer);
    currentIteration = 0;
    generateNextLevel();
}
void Model::checkCurrentMove(QColor currentColor){
    //Check if the current iteration of the player matches the current iteration of the current Pattern,
    //sending a gameover signal if it doesnt.
    if (currentIteration < currentPattern.size()){
        if (currentColor == currentPattern[currentIteration])
            currentIteration++;
        else
            emit gameOver();
    }
    else {
        currentIteration = 0;
        generateNextLevel();
    }
}

void Model::generateNextLevel(){
    //Adds a random color to the currentPattern, and sends signal to view to update.
    QColor newColorIteration = randomColorGenerator();
    currentPattern.append(newColorIteration);
    emit UpdateNextLevel(currentPattern);
}

/**
 * @brief randomColorGenerator Helper method that generates a color randomly.
 * @return blue or red as a QColor.
 */
QColor randomColorGenerator(){
    int randomBinary = QRandomGenerator::global()->bounded(0,1);
    if (randomBinary == 0)
        return Qt::red;
    return Qt::blue;
}

void Model::increaseGameSpeed(){
    //Makes the QTimer smaller
}


