#pragma once

#include "esphome.h"

class KeypadKeypress : public Component, public TextSensor {
 public:
  KeypadKeypress(BinarySensor *row1, BinarySensor *row2, BinarySensor *row3, BinarySensor *row4,
                 BinarySensor *row5, BinarySensor *row6, BinarySensor *row7,
                 BinarySensor *col1, BinarySensor *col2, BinarySensor *col3, BinarySensor *col4,
                 BinarySensor *col5, BinarySensor *col6) {
    this->row1_ = row1;
    this->row2_ = row2;
    this->row3_ = row3;
    this->row4_ = row4;
    this->row5_ = row5;
    this->row6_ = row6;
    this->row7_ = row7;
    this->col1_ = col1;
    this->col2_ = col2;
    this->col3_ = col3;
    this->col4_ = col4;
    this->col5_ = col5;
    this->col6_ = col6;
  }

  void update() override {
    if (row1_->state && col1_->state) {
      publish_state("Key 1 Pressed");
    } else if (row1_->state && col2_->state) {
      publish_state("Key 2 Pressed");
    } else if (row2_->state && col1_->state) {
      publish_state("Key 3 Pressed");
    }
    // Add more logic for additional keys
  }

 protected:
  BinarySensor *row1_;
  BinarySensor *row2_;
  BinarySensor *row3_;
  BinarySensor *row4_;
  BinarySensor *row5_;
  BinarySensor *row6_;
  BinarySensor *row7_;
  BinarySensor *col1_;
  BinarySensor *col2_;
  BinarySensor *col3_;
  BinarySensor *col4_;
  BinarySensor *col5_;
  BinarySensor *col6_;
};
