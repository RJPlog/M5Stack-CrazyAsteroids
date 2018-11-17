// CrazyAsteroids by RJPlog
// 21.6.2018

#include <M5Stack.h>

#define TFTH            240    // screen height
#define TFTW            250    // screen width (normal 320, here reduced for sidebar with score)

#define SpaceShipH      20     // screen height SpaceShip
#define SpaceShipW      21     // screen width SpaceShip
#define SpaceShipGap    20     // hight SpaceShip over Ground
#define SpaceShipVel     5     // velocity Spaceship

int z; // Score

int ObjectDistance1 = 100;
int ObjectDistance2 = 100;
int ObjectDistance3 = 100;

int DifferenceAsteroid1to2 = 0;
int DifferenceAsteroid1to3 = 0;
int DifferenceAsteroid2to3 = 0;

int DistanceX = 0;
int DistanceY = 0;
bool CollisionDistance = false;

int help1 = 0;

int CountHit = 0;

#define Asteroid1H      20     // screen height SpaceShip
#define Asteroid1W      11     // screen width SpaceShip
#define Asteroid1Gap    10     // hight SpaceShip over Ground
#define Asteroid1Vel     5     // velocity Spaceship

#define Asteroid2H      20     // screen height SpaceShip
#define Asteroid2W      11     // screen width SpaceShip
#define Asteroid2Gap    10     // hight SpaceShip over Ground
#define Asteroid2Vel   6     // velocity Spaceship

#define Asteroid3H      20     // screen height SpaceShip
#define Asteroid3W      11     // screen width SpaceShip
#define Asteroid3Gap    10     // hight SpaceShip over Ground
#define Asteroid3Vel     4    // velocity Spaceship

int PosSpaceShipOld = 154;
int PosSpaceShip = 154;
int PosAsteroid1 = 40;
int PosAsteroid1Old = 40;
int StartPointAsteroid1 = 0;
int Asteroid1Lockedx = 20;
bool Asteroid1Locked = false;
bool Asteroid1Hit = false;
int iAsteroid1 = 0;
int Asteroid1Beamx0 = 50;
int Asteroid1Beamy0 = 50;
int Asteroid1Beamx1 = 0;
int Asteroid1Beamy1 = 0;
int Asteroid1Beamx2 = 0;
int Asteroid1Beamy2 = 0;
int PosAsteroid2 = 140;
int PosAsteroid2Old = 140;
int StartPointAsteroid2 = 100;
int Asteroid2Lockedx = 20;
bool Asteroid2Locked = false;
bool Asteroid2Hit = false;
int iAsteroid2 = 0;
int Asteroid2Beamx0 = 50;
int Asteroid2Beamy0 = 50;
int Asteroid2Beamx1 = 0;
int Asteroid2Beamy1 = 0;
int Asteroid2Beamx2 = 0;
int Asteroid2Beamy2 = 0;
int PosAsteroid3 = 60;
int PosAsteroid3Old = 60;
int StartPointAsteroid3 = 50;
int Asteroid3Lockedx = 20;
bool Asteroid3Locked = false;
bool Asteroid3Hit = false;
int iAsteroid3 = 0;
int Asteroid3Beamx0 = 50;
int Asteroid3Beamy0 = 50;
int Asteroid3Beamx1 = 0;
int Asteroid3Beamy1 = 0;
int Asteroid3Beamx2 = 0;
int Asteroid3Beamy2 = 0;
int Level = -3;
int Level1 = 0;
int Level2 = 0;
int Level3 = 0;
int LevelPosPlus = 20;
int LevelPosPlusOld = 20;

int i, j; // counter
unsigned long timeframe;

void setup() {
  // put your setup code here, to run once:

  M5.begin();

  pinMode(35, INPUT);                 // initializing random generator
  randomSeed(analogRead(35) * 10);    // initializing random generator

  startEntrySection();  // print start screen
}

void loop() {
  // put your main code here, to run repeatedly:
  timeframe = millis();

  // --------------------------------------------------------------
  // Space Ship Section / Calculate new position / print Space Ship
  // --------------------------------------------------------------

  // check Button, calculate new postition spaceship
  if (M5.BtnA.read()) {
    if (PosSpaceShip > SpaceShipVel) {
      PosSpaceShip = PosSpaceShip - SpaceShipVel;
    }
  }
  if (M5.BtnC.read()) {
    if (PosSpaceShip < TFTW - SpaceShipVel * 2 - SpaceShipW - 1) {
      PosSpaceShip = PosSpaceShip + SpaceShipVel;
    }
  }

  if (M5.BtnB.read()) {
    if (Asteroid1Locked) {
      Asteroid1Hit = true;
    }

    if (Asteroid2Locked) {
      Asteroid2Hit = true;
    }
    if (Asteroid3Locked) {
      Asteroid3Hit = true;
    }
  }

  // print spaceship
  printSpaceShip();

  // print cross hairs  --> Change Form if Astroid is looked!!
  Asteroid1Lockedx = StartPointAsteroid1 - (PosSpaceShip + 12);
  Asteroid2Lockedx = StartPointAsteroid2 - (PosSpaceShip + 12);
  Asteroid3Lockedx = StartPointAsteroid3 - (PosSpaceShip + 12);

  // if ((abs(Asteroid1Lockedx >= 3)) && (abs(Asteroid2Lockedx >= 3)) && (abs(Asteroid3Lockedx >= 3) )) {
  if ((PosSpaceShip != PosSpaceShipOld) || (LevelPosPlus != LevelPosPlusOld)) {
    M5.Lcd.drawLine(PosSpaceShipOld + SpaceShipW, 140 - LevelPosPlusOld, PosSpaceShipOld + SpaceShipW, 160 - LevelPosPlusOld, BLACK);
    M5.Lcd.drawLine(PosSpaceShipOld + 10, 150 - LevelPosPlusOld, PosSpaceShipOld + 2 * SpaceShipW - 10, 150 - LevelPosPlusOld, BLACK);
  }
  M5.Lcd.drawLine(PosSpaceShip + SpaceShipW, 140 - LevelPosPlus, PosSpaceShip + SpaceShipW, 160 - LevelPosPlus, RED);
  M5.Lcd.drawLine(PosSpaceShip + 10, 150 - LevelPosPlus, PosSpaceShip + 2 * SpaceShipW - 10, 150 - LevelPosPlus, RED);
  //  }



  // ----------------------
  // Asteroid Calculation
  // ----------------------

  // generate Asteroids

  // calculate new position asteriods
  Level1 = Level;
  if (Asteroid1Hit) {
    iAsteroid1++;
    if (iAsteroid1 > 6) {
      PosAsteroid1 = PosAsteroid1 + 280;
      Asteroid1Hit = false;
      iAsteroid1 = 0;
      CountHit = CountHit + 5;
    }
  }
  if (Level + Asteroid1Vel > 10) Level1 = 10 - Asteroid1Vel;
  PosAsteroid1 = PosAsteroid1 + Asteroid1Vel + Level1;
  if (PosAsteroid1 > TFTH + Asteroid1H * 2) {
    PosAsteroid1 = 0;
    StartPointAsteroid1 = random(1, TFTW - Asteroid1W - 10);
    DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
    DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
    while ((abs(DifferenceAsteroid1to2) < 22) || (abs(DifferenceAsteroid1to3) < 22)) {
      StartPointAsteroid1 = random(1, TFTW - Asteroid1W - 10);
      DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
      DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
    }
  }

  Level2 = Level;
  if (Asteroid2Hit) {
    iAsteroid2 ++;
    if (iAsteroid2 > 6) {
      PosAsteroid2 = PosAsteroid2 + 280;
      Asteroid2Hit = false;
      iAsteroid2 = 0;
      CountHit = CountHit + 5;
    }
  }
  if (Level + Asteroid2Vel > 10) Level2 = 10 - Asteroid2Vel;
  PosAsteroid2 = PosAsteroid2 + Asteroid2Vel + Level2;
  if (PosAsteroid2 > TFTH + Asteroid2H * 2) {
    PosAsteroid2 = 0;
    StartPointAsteroid2 = random(1, TFTW - Asteroid2W - 10);
    DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
    DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
    while ((abs(DifferenceAsteroid1to2) < 22) || (abs(DifferenceAsteroid2to3) < 22)) {
      StartPointAsteroid2 = random(1, TFTW - Asteroid1W - 10);
      DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
      DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
    }
  }

  Level3 = Level;
  if (Asteroid3Hit) {
    iAsteroid3 ++;
    if (iAsteroid3 > 6) {
      PosAsteroid3 = PosAsteroid3 + 280;
      Asteroid3Hit = false;
      iAsteroid3 = 0;
      CountHit = CountHit + 5;
    }
  }
  if (Level + Asteroid3Vel > 10) Level3 = 10 - Asteroid3Vel;
  PosAsteroid3 = PosAsteroid3 + Asteroid3Vel + Level3;
  if (PosAsteroid3 > TFTH + Asteroid3H * 2) {
    PosAsteroid3 = 0;
    StartPointAsteroid3 = random(1, TFTW - Asteroid3W - 10);
    DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
    DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
    while ((abs(DifferenceAsteroid1to3) < 22) || (abs(DifferenceAsteroid2to3) < 22)) {
      StartPointAsteroid3 = random(1, TFTW - Asteroid1W - 10);
      DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
      DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
    }
  }

  //check collision with spaceship

  DistanceX = (StartPointAsteroid1 + Asteroid1W) - (PosSpaceShip + SpaceShipW);
  DistanceY = ((PosAsteroid1 - Asteroid1H - Asteroid1Gap + 20) - (TFTH - SpaceShipH - LevelPosPlus));
  ObjectDistance1 = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

  DistanceX = (StartPointAsteroid2 + Asteroid2W) - (PosSpaceShip + SpaceShipW);
  DistanceY = ((PosAsteroid2 - Asteroid2H - Asteroid2Gap + 20) - (TFTH - SpaceShipH - LevelPosPlus));
  ObjectDistance2 = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

  DistanceX = (StartPointAsteroid3 + Asteroid3W) - (PosSpaceShip + SpaceShipW);
  DistanceY = ((PosAsteroid3 - Asteroid3H - Asteroid3Gap + 20) - (TFTH - SpaceShipH - LevelPosPlus));
  ObjectDistance3 = sqrt(pow(DistanceX, 2) + pow(DistanceY, 2));

  if ((ObjectDistance1 < 25) || (ObjectDistance2 < 25) || (ObjectDistance3 < 25)) {
    CollisionDistance = true;
  }
  else {
    CollisionDistance = false;
  }

  // draw Asteroids

  printAsteroid1();

  printAsteroid2();

  printAsteroid3();

  PosSpaceShipOld = PosSpaceShip;
  LevelPosPlusOld = LevelPosPlus;
  PosAsteroid1Old = PosAsteroid1;
  PosAsteroid2Old = PosAsteroid2;
  PosAsteroid3Old = PosAsteroid3;

  // ----------------------
  // task handling
  // ----------------------

  //adjustment of task
  while (1) {
    if (millis() - timeframe > 50) {
      if (CollisionDistance) {
        M5.Lcd.setCursor(0, 100);
        M5.Lcd.setTextColor(M5.Lcd.color565(255, 131, 250));
        M5.Lcd.setTextSize(3);
        M5.Lcd.println("  GAME OVER ");
        M5.Lcd.setCursor(100, 210);
        M5.Lcd.setTextColor(M5.Lcd.color565(139, 0, 139));
        M5.Lcd.setTextSize(2);
        M5.Lcd.println("  play again? ");
        while (1) {
          // wait for push button
          if (M5.BtnB.read()) {
            while (1) {
              if (!M5.BtnB.read()) {
                break;
              }
            }
            M5.Lcd.setCursor(0, 100);
            M5.Lcd.setTextColor(BLACK);
            M5.Lcd.setTextSize(3);
            M5.Lcd.println("  GAME OVER ");
            M5.Lcd.setCursor(80, 210);
            M5.Lcd.setTextColor(BLACK);
            M5.Lcd.setTextSize(2);
            M5.Lcd.println("play again? ");
            CollisionDistance = false;
            PosAsteroid1 = 0;
            StartPointAsteroid1 = random(1, TFTW - 2 * Asteroid1W);
            PosAsteroid2 = 50;
            StartPointAsteroid2 = random(1, TFTW - Asteroid2W - 10);
            DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
            while ((abs(DifferenceAsteroid1to2) < 22) ) {
              StartPointAsteroid2 = random(1, TFTW - Asteroid1W - 10);
              DifferenceAsteroid1to2 = StartPointAsteroid1 - StartPointAsteroid2;
            }
            PosAsteroid3 = 90;
            StartPointAsteroid3 = random(1, TFTW - Asteroid3W - 10);
            DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
            DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
            while ((abs(DifferenceAsteroid1to3) < 22) || (abs(DifferenceAsteroid2to3) < 22)) {
              StartPointAsteroid3 = random(1, TFTW - Asteroid1W - 10);
              DifferenceAsteroid1to3 = StartPointAsteroid1 - StartPointAsteroid3;
              DifferenceAsteroid2to3 = StartPointAsteroid2 - StartPointAsteroid3;
            }
            LevelPosPlus = 20;
            Level = -3;
            M5.Lcd.fillRect(1, 1, 264, 240, BLACK);
            M5.Lcd.setRotation(0);
            M5.Lcd.setTextSize(3);
            M5.Lcd.setCursor(10, 290);
            M5.Lcd.setTextColor(RED);
            M5.Lcd.print("Score: ");
            M5.Lcd.setTextColor(M5.Lcd.color565(117, 117, 117));
            M5.Lcd.print(z / 20);
            z = 0;
            break;
          }
        }
      }
      if (z == 3000) {
        startExitSection();
      }
      
      M5.Lcd.setRotation(0);
      M5.Lcd.setTextSize(3);
      M5.Lcd.setCursor(10, 290);
      M5.Lcd.setTextColor(RED);
      M5.Lcd.print("Score: ");
      M5.Lcd.setTextColor(M5.Lcd.color565(117, 117, 117));
      M5.Lcd.print(z / 20);
      M5.Lcd.setTextColor(RED);
      M5.Lcd.setCursor(10, 290);
      M5.Lcd.print("Score: ");
      z = z + 1;


      // spaceship will move forward every 100 cycles, calculation of y offset depending on time

      if (z % 100 == 0 && z < 2900) {
        LevelPosPlus = 20 + (z / 100) * 5;
      }

      M5.Lcd.print(z / 20);
      M5.Lcd.setRotation(1);
      break;
    }
  }
}






