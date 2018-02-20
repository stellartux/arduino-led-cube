#include <Tasker.h>
#include <Pin.h>

/*
 * LED Cube
 * 3x3x3
 */

Pin cathodePins[] {16, 19, 2, 15, 18, 4, 14, 17, 7};
Pin anodePins[] {3, 5, 6};
int cSize = sizeof(cathodePins) / sizeof(Pin);
int aSize = sizeof(anodePins) / sizeof(Pin);

class Light {
  private:
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
  bool lit[27];
  int brightness[3];
  int frametime;
};

Frame * currentFrame;

void drawFrame(Frame f) {
  for (int b = 0; b < 3; b++) {
    for (int c = 0; c < 9; c++) {

    }
  }
};

void setup() {

  Pin lbi = Pin(LED_BUILTIN);
  lbi.setOutput();
  lbi.setLow();
  for (int i = 0; i < cSize; i++) {
    cathodePins[i].setOutput();
  }
  for (int i = 0; i < aSize; i++) {
    anodePins[i].setOutput();
  }

  Tasker tasker;
  tasker.run();

};
