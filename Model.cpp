#include "Model.h"
#include <QRandomGenerator>

Model::Model(QObject *parent) : QObject(parent){}

void Model::startGame(){
    currentPattern.clear();
    currentIteration = 0;
    gameSpeed = 1000;
    generateNextLevel();
    showNextLevel();
}

void Model::checkCurrentMove(Color currentColor){
    //Edge-Case
    if (currentPattern.size() == 1){
        if (currentColor != currentPattern[0]){
            emit gameOver();
            return;
        }
    }

    if (currentIteration < currentPattern.size() - 1){
        if (currentColor == currentPattern[currentIteration]){
            currentIteration++;
            int progressPercentage = (currentIteration *100) / currentPattern.size();
            emit updateProgressBar(progressPercentage);
        }
        else{
            emit gameOver();
            return;
        }
    }
    else{
        currentIteration = 0;
        generateNextLevel();
        increaseGameSpeed();
        showNextLevel();
    }
}

Model::Color Model::randomColorGenerator(){
    int randomBinary = QRandomGenerator::global()->bounded(0,2);
    if (randomBinary == 0)
        return Model::Color::Red;
    return Model::Color::Blue;
}

void Model::showNextLevel(){
    emit startPatternView();
    int temp = gameSpeed;
    for(int i = 0; i < currentPattern.size(); i++) {
        Model::Color color = currentPattern[i];
        QTimer::singleShot(temp, this, [this, color, i]() {
            isRedOrBlue(color);
            if(i == currentPattern.size() - 1)
                emit endPatternView();
        });
        temp += gameSpeed;
    }
}

void Model::isRedOrBlue(Color color){
    if (color == Model::Color::Red){
        emit isRed();
    }
    else{
        emit isBlue();
    }
}


void Model::generateNextLevel(){
    Model::Color newColorIteration = randomColorGenerator();
    currentPattern.append(newColorIteration);
}


void Model::increaseGameSpeed(){
    gameSpeed = 2000/currentPattern.size();
}


