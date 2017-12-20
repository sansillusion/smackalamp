///////////////////////////////////////////////////////////////////////////////////////////
//
// Based on ALA library e
//
// Web page: http://yaab-arduino.blogspot.com
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>

AlaLedRgb rgbStrip;

const int tiltSensorPin = 2;
int tiltSensorState = 1, originalTiltSensorState, faite = 0;

int animation = 0;
int duration = 0;
int palette = 0;

AlaColor mycolors_[6] = { 0x000000, 0xFFFFFF, 0x000000, 0xFF0000, 0x00FF00, 0x0000FF };
AlaPalette mycolors = { 6, mycolors_ };
AlaColor blancs_[2] = { 0xFFFFFF, 0xFFFFFF };
AlaPalette blancs = { 2, blancs_ };
AlaColor bleus_[2] = { 0x0000FF, 0x0000FF };
AlaPalette bleus = { 2, bleus_ };
AlaColor verts_[2] = { 0x00FF00, 0x00FF00 };
AlaPalette verts = { 2, verts_ };
AlaColor mauves_[2] = { 0xFF00FF, 0xFF00FF };
AlaPalette mauves = { 2, mauves_ };


int animList[33] = {
  ALA_OFF,
  ALA_SPARKLE,
  ALA_SPARKLE2,
  ALA_PIXELSHIFTRIGHT,
  ALA_PIXELSMOOTHSHIFTRIGHT,
  ALA_ON,
  ALA_MOVINGBARS,
  ALA_COMET,
  ALA_COMETCOL,
  ALA_GLOW,
  ALA_CYCLECOLORS,
  ALA_FADECOLORS,
  ALA_FIRE,
  ALA_BOUNCINGBALLS,
  ALA_BUBBLES,
  ALA_ON,
  ALA_BLINK,
  ALA_BLINKALT,
  ALA_STROBO,
  ALA_PIXELSHIFTLEFT,
  ALA_PIXELBOUNCE,
  ALA_PIXELSMOOTHSHIFTLEFT,
  ALA_ON,
  ALA_PIXELSMOOTHBOUNCE,
  ALA_BARSHIFTRIGHT,
  ALA_BARSHIFTLEFT,
  ALA_LARSONSCANNER,
  ALA_LARSONSCANNER2,
  ALA_MOVINGGRADIENT,
  ALA_ON,
  ALA_FADEINOUT,
  ALA_PIXELSFADECOLORS,
  ALA_FADECOLORSLOOP
};

AlaPalette paletteList[11] = {
  alaPalRgb,
  alaPalRainbow,
  alaPalFire,
  alaPalRainbowStripe,
  alaPalParty,
  alaPalHeat,
  mycolors,
  blancs,
  bleus,
  verts,
  mauves
};

int durationList[5] = {
  1000,
  10000,
  3000,
  6000,
  4000
};


void setup()
{
  //delay(4000);
  rgbStrip.initWS2812(18, 6);
  pinMode(tiltSensorPin, INPUT);
  updateAnimation();
}

void loop()
{
  tiltSensorState = digitalRead(tiltSensorPin);
  if (tiltSensorState != originalTiltSensorState) {
    originalTiltSensorState = tiltSensorState;
    if (faite != 1) {
      animation = random(0, 200);
      palette = random(0, 200);
      duration = random (0, 200);
      updateAnimation();
      faite = 1;
    }
    if (tiltSensorState != LOW){
      faite = 0;
    }
  }
  rgbStrip.runAnimation();
}

void updateAnimation()
{
  rgbStrip.setAnimation(animList[animation % 33], durationList[duration % 5], paletteList[palette % 11]);
}
