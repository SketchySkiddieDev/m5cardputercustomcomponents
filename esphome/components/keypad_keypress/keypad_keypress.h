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
    // Loop through all rows and columns to detect key presses
    for (int row = 0; row < 7; ++row) {
      setRow(row);  // Activate the current row via the multiplexer

      // Check each column for key press
      for (int col = 0; col < 6; ++col) {
        if (getColumnState(col)) {
          // Publish key press event based on the row and column
          String key = "Key " + String(row * 6 + col + 1) + " Pressed";
          publish_state(key);
        }
      }

      // Small debounce delay to avoid multiple triggers for the same key
      delay(50);  // Adjust this delay as needed for stability

      deactivateRow(row);  // Deactivate the current row after checking
    }
  }

 protected:
  // Row and column binary sensors
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

  // Method to set the correct row using the 74hc138 multiplexer logic
  void setRow(int row) {
    // Set the appropriate multiplexer address lines (A0, A1, A2) based on the row
    // Implement the logic to select the correct row using the GPIO pins controlling A0, A1, A2 of the 74hc138
    // Example (adjust as necessary):
    digitalWrite(A0, (row & 0x01) ? HIGH : LOW);
    digitalWrite(A1, (row & 0x02) ? HIGH : LOW);
    digitalWrite(A2, (row & 0x04) ? HIGH : LOW);
  }

  // Method to deactivate the current row
  void deactivateRow(int row) {
    // Implement logic to disable the current row by setting the appropriate address lines low
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  // Method to read the state of a column binary sensor
  bool getColumnState(int col) {
    switch (col) {
      case 0: return col1_->state;
      case 1: return col2_->state;
      case 2: return col3_->state;
      case 3: return col4_->state;
      case 4: return col5_->state;
      case 5: return col6_->state;
      default: return false;
    }
  }
};
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
    // Loop through all rows and columns to detect key presses
    for (int row = 0; row < 7; ++row) {
      setRow(row);  // Activate the current row via the multiplexer

      // Check each column for key press
      for (int col = 0; col < 6; ++col) {
        if (getColumnState(col)) {
          // Publish key press event based on the row and column
          String key = "Key " + String(row * 6 + col + 1) + " Pressed";
          publish_state(key);
        }
      }

      // Small debounce delay to avoid multiple triggers for the same key
      delay(50);  // Adjust this delay as needed for stability

      deactivateRow(row);  // Deactivate the current row after checking
    }
  }

 protected:
  // Row and column binary sensors
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

  // Method to set the correct row using the 74hc138 multiplexer logic
  void setRow(int row) {
    // Set the appropriate multiplexer address lines (A0, A1, A2) based on the row
    // Implement the logic to select the correct row using the GPIO pins controlling A0, A1, A2 of the 74hc138
    // Example (adjust as necessary):
    digitalWrite(A0, (row & 0x01) ? HIGH : LOW);
    digitalWrite(A1, (row & 0x02) ? HIGH : LOW);
    digitalWrite(A2, (row & 0x04) ? HIGH : LOW);
  }

  // Method to deactivate the current row
  void deactivateRow(int row) {
    // Implement logic to disable the current row by setting the appropriate address lines low
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
  }

  // Method to read the state of a column binary sensor
  bool getColumnState(int col) {
    switch (col) {
      case 0: return col1_->state;
      case 1: return col2_->state;
      case 2: return col3_->state;
      case 3: return col4_->state;
      case 4: return col5_->state;
      case 5: return col6_->state;
      default: return false;
    }
  }
};
