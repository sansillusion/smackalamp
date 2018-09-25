///////////////////////////////////////////////////////////////////////////////////////////
//
// Based on ALA library
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
AlaColor crazyb_[29] = { 0x000011, 0x000022, 0x000033, 0x000044, 0x000055, 0x000066, 0x000077, 0x000088, 0x000099, 0x0000AA, 0x0000BB, 0x0000CC, 0x0000DD, 0x0000EE, 0x0000FF, 0x0000EE, 0x0000DD, 0x0000CC, 0x0000BB, 0x0000AA, 0x000099, 0x000088, 0x000077, 0x000066, 0x000055, 0x000044, 0x000033, 0x000022, 0x000011 };
AlaPalette crazyb = { 29, crazyb_ };
AlaColor crazyr_[29] = { 0x001100, 0x002200, 0x003300, 0x004400, 0x005500, 0x006600, 0x007700, 0x008800, 0x009900, 0x00AA00, 0x00BB00, 0x00CC00, 0x00DD00, 0x00EE00, 0x00FF00, 0x00EE00, 0x00DD00, 0x00CC00, 0x00BB00, 0x00AA00, 0x009900, 0x008800, 0x007700, 0x006600, 0x005500, 0x004400, 0x003300, 0x002200, 0x001100 };
AlaPalette crazyr = { 29, crazyr_ };
AlaColor crazyg_[29] = { 0x110000, 0x220000, 0x330000, 0x440000, 0x550000, 0x660000, 0x770000, 0x880000, 0x990000, 0xAA0000, 0xBB0000, 0xCC0000, 0xDD0000, 0xEE0000, 0xFF0000, 0xEE0000, 0xDD0000, 0xCC0000, 0xBB0000, 0xAA0000, 0x990000, 0x880000, 0x770000, 0x660000, 0x550000, 0x440000, 0x330000, 0x220000, 0x110000 };
AlaPalette crazyg = { 29, crazyg_ };
AlaColor crazy_[32] = { 0x110000, 0x220000, 0x330000, 0x440000, 0x550000, 0x660000, 0x770000, 0x880000, 0x990000, 0xAA0000, 0xBB0000, 0xCC0000, 0xDD0000, 0xEE0000, 0xFF0000, 0x0000FF, 0x00FF00, 0xFF00FF, 0xEE0000, 0xDD0000, 0xCC0000, 0xBB0000, 0xAA0000, 0x990000, 0x880000, 0x770000, 0x660000, 0x550000, 0x440000, 0x330000, 0x220000, 0x110000 };
AlaPalette crazy = { 32, crazy_ };
AlaColor randcol_[2] = { random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF) };
AlaPalette randcol = { 2, randcol_ };
AlaColor randcoll_[4] = { random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF) };
AlaPalette randcoll = { 4, randcoll_ };
AlaColor randcool_[16] = { random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF) };
AlaPalette randcool = { 16, randcool_ };


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

AlaPalette paletteList[18] = {
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
  mauves,
  crazyb,
  crazyr,
  crazy,
  randcol,
  randcoll,
  randcool,
  crazyg
};

long int durationList[6] = {
  1000,
  10000,
  3000,
  6000,
  4000,
  random(500, 10000)
};


void setup()
{
  //delay(4000);
  rgbStrip.initWS2812(16, 6);
  pinMode(tiltSensorPin, INPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, 1);
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
      AlaColor randcool_[16] = { random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF), random(0x000000, 0xFFFFFF) };
      AlaPalette randcool = { 16, randcool_ };
      AlaPalette paletteList[18] = {
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
        mauves,
        crazyb,
        crazyr,
        crazy,
        randcol,
        randcoll,
        randcool,
        crazyg
      };
      long int durationList[6] = {
        1000,
        10000,
        3000,
        6000,
        4000,
        random(500, 10000)
      };
    }
    if (tiltSensorState != LOW) {
      faite = 0;
    }
  }
  rgbStrip.runAnimation();
}

void updateAnimation()
{
  rgbStrip.setAnimation(animList[animation % 33], durationList[duration % 6], paletteList[palette % 18]);
}
