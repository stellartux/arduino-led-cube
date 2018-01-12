#include <Tasker.h>
#include <Pin.h>

/*
 * LED Cube
 * 64 LEDs on 16 wires
 */

Pin cathodePins[] {3, 2, 14, 15, 16, 17, 18, 19};
Pin anodePins[] {4};
int cSize = sizeof(cathodePins) / sizeof(Pin);
int aSize = sizeof(anodePins) / sizeof(Pin);

class Light {
    int cathode;
    int anode;
  public:
    Light(int c, int a) {
      cathode = c;
      anode = a;
    }
    void setState(int i) {
      cathodePins[cathode].setState(i);
      anodePins[anode].setState(i);
    }
    void setHigh() {
      cathodePins[cathode].setHigh();
      anodePins[anode].setHigh();
    }
    void setLow() {
      cathodePins[cathode].setLow();
      anodePins[anode].setLow();
    }
};

class Frame {
  int number;
  byte data[8];
};

Light lights[4][4][4];

void setup() {
  Pin(13).setLow();
  for (int i = 0; i < cSize; i++) {
    cathodePins[i].setOutput();
  }
  for (int i = 0; i < aSize; i++) {
    anodePins[i].setOutput();
  }
}

void loop() {
  for (int i = 0; i < cSize; i++) {
    for (int j = 0; j < aSize; j++) {
      cathodePins[i].setHigh();
      anodePins[j].setHigh();
      delay(50);
      cathodePins[i].setLow();
      anodePins[j].setLow();
    }
  }
}
