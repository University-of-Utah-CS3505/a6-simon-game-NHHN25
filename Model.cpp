#include "Model.h"
#include <QRandomGenerator>

Model::Model(QObject *parent) : QObject(parent){

}

//*** TODO LIST ***
// - Determine whether the speed of the game should be saved on model or view.
//      - Start it and implement it properly in model if that is decided.
// - Implement the increaseGameSpeed Method.

void Model::startGame(){
    //Sets everything to default and adds the initial color to the current pattern
    currentPattern.clear();
    currentIteration = 0;
    generateNextLevel();
}
void Model::checkCurrentMove(Color currentColor){
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
        QTimer::singleShot(1000, this, &Model::generateNextLevel);
    }
}

/**
 * @brief randomColorGenerator Helper method that generates a color randomly.
 * @return blue or red as a QColor.
 */
Model::Color randomColorGenerator(){
    int randomBinary = QRandomGenerator::global()->bounded(0,1);
    if (randomBinary == 0)
        return Model::Color::Red;
    return Model::Color::Blue;
}

void Model::generateNextLevel(){
    //Adds a random color to the currentPattern, and sends signal to view to update.
    Model::Color newColorIteration = randomColorGenerator();
    currentPattern.append(newColorIteration);
    emit UpdateNextLevel(currentPattern);
}


void Model::increaseGameSpeed(){
    //Makes the QTimer smaller
}


