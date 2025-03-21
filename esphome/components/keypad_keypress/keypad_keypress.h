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
    // Loop through all the rows and columns to detect key presses
    if (row1_->state) {
      if (col1_->state) publish_state("Key 1 Pressed");
      if (col2_->state) publish_state("Key 2 Pressed");
      if (col3_->state) publish_state("Key 3 Pressed");
      if (col4_->state) publish_state("Key 4 Pressed");
      if (col5_->state) publish_state("Key 5 Pressed");
      if (col6_->state) publish_state("Key 6 Pressed");
    } else if (row2_->state) {
      if (col1_->state) publish_state("Key 7 Pressed");
      if (col2_->state) publish_state("Key 8 Pressed");
      if (col3_->state) publish_state("Key 9 Pressed");
      if (col4_->state) publish_state("Key 10 Pressed");
      if (col5_->state) publish_state("Key 11 Pressed");
      if (col6_->state) publish_state("Key 12 Pressed");
    } else if (row3_->state) {
      if (col1_->state) publish_state("Key 13 Pressed");
      if (col2_->state) publish_state("Key 14 Pressed");
      if (col3_->state) publish_state("Key 15 Pressed");
      if (col4_->state) publish_state("Key 16 Pressed");
      if (col5_->state) publish_state("Key 17 Pressed");
      if (col6_->state) publish_state("Key 18 Pressed");
    } else if (row4_->state) {
      if (col1_->state) publish_state("Key 19 Pressed");
      if (col2_->state) publish_state("Key 20 Pressed");
      if (col3_->state) publish_state("Key 21 Pressed");
      if (col4_->state) publish_state("Key 22 Pressed");
      if (col5_->state) publish_state("Key 23 Pressed");
      if (col6_->state) publish_state("Key 24 Pressed");
    } else if (row5_->state) {
      if (col1_->state) publish_state("Key 25 Pressed");
      if (col2_->state) publish_state("Key 26 Pressed");
      if (col3_->state) publish_state("Key 27 Pressed");
      if (col4_->state) publish_state("Key 28 Pressed");
      if (col5_->state) publish_state("Key 29 Pressed");
      if (col6_->state) publish_state("Key 30 Pressed");
    } else if (row6_->state) {
      if (col1_->state) publish_state("Key 31 Pressed");
      if (col2_->state) publish_state("Key 32 Pressed");
      if (col3_->state) publish_state("Key 33 Pressed");
      if (col4_->state) publish_state("Key 34 Pressed");
      if (col5_->state) publish_state("Key 35 Pressed");
      if (col6_->state) publish_state("Key 36 Pressed");
    } else if (row7_->state) {
      if (col1_->state) publish_state("Key 37 Pressed");
      if (col2_->state) publish_state("Key 38 Pressed");
      if (col3_->state) publish_state("Key 39 Pressed");
      if (col4_->state) publish_state("Key 40 Pressed");
      if (col5_->state) publish_state("Key 41 Pressed");
      if (col6_->state) publish_state("Key 42 Pressed");
    }
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
