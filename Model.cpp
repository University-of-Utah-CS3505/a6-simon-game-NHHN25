#include "Model.h"
#include <QRandomGenerator>
#include <iostream>

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
    gameSpeed = 1000;
    generateNextLevel();
    showNextLevel();
}

// Remove when done with debugging
static std::string colorToString(Model::Color color) {
    switch (color) {
    case Model::Color::Red: return "Red";
    case Model::Color::Blue: return "Blue";
    // Add other colors if necessary
    default: return "Unknown Color";
    }
}

void Model::checkCurrentMove(Color currentColor){
    if (currentIteration < currentPattern.size() - 1){
        if (currentColor == currentPattern[currentIteration]) {
            currentIteration++;
            int progressPercentage = (currentIteration *100) / currentPattern.size();
            emit updateProgressBar(progressPercentage);
        }
        else {
            std::cout << "Game Over emitted" << std::endl;
            emit gameOver();
        }
    }
    else {
        currentIteration = 0;
        generateNextLevel();
        increaseGameSpeed();
        showNextLevel();
    }
}

/**
 * @brief randomColorGenerator Helper method that generates a color randomly.
 * @return blue or red as a QColor.
 */
Model::Color randomColorGenerator(){
    int randomBinary = QRandomGenerator::global()->bounded(0,2);
    if (randomBinary == 0)
        return Model::Color::Red;
    return Model::Color::Blue;
}

void Model::showNextLevel(){
    emit startPatternView();
    int temp = gameSpeed;
    for(int i = 0; i < currentPattern.size(); i++){
        Model::Color color = currentPattern[i];
        std::cout<< "color emitted" << std::endl;
        QTimer::singleShot(temp, this, [this, color, i]() {

            isRedOrBlue(color);

            if(i == currentPattern.size() - 1) emit endPatternView();

        });
        temp += gameSpeed;
    }


}

void Model::isRedOrBlue(Color color){
    if (color == Model::Color::Red){
        std::cout<< "isRed emitted" << std::endl;
        emit isRed();
    }
    else{
        std::cout<< "isBlue emitted" << std::endl;
        emit isBlue();
    }
}


void Model::generateNextLevel(){
    //Adds a random color to the currentPattern, and calls a method to show the next level.
    Model::Color newColorIteration = randomColorGenerator();
    currentPattern.append(newColorIteration);
}


void Model::increaseGameSpeed(){
    gameSpeed = 2000/currentPattern.size();
}


