// traffic_light.cpp

#include "traffic_light.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent) {

  // Add the red traffic light
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();   // initialize the red light to be ON
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}" "QRadioButton::indicator { width: 20px; height: 20px; border-radius: 10px; }");
  
    yellowlight = new QRadioButton;
    yellowlight->setEnabled(false);
    yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}" "QRadioButton::indicator { width: 20px; height: 20px; border-radius: 10px; }");
      
    greenlight = new QRadioButton;
    greenlight->setEnabled(false);
    greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}" "QRadioButton::indicator { width: 20px; height: 20px; border-radius: 10px; }");
    
    auto layout = new QVBoxLayout;
    layout->addWidget(redlight);
    layout->addWidget(yellowlight);
    layout->addWidget(greenlight);

    setLayout(layout);
}

// TO DO: build the light_update() slot function here

void TrafficLight::light_update() {
    switch(currentState) {
        case 0:
        greenlight->toggle();
        currentState = 1;
        break;
    case 1:
        yellowlight->toggle();
        currentState = 2;
        break;
    case 2:
        redlight->toggle();
        currentState = 0;
        break;
    }
}