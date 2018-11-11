// Crazy Asteroids by RJPlog
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
int help2 = 0;
int CountHit = 0;

int BoostColor = 0;

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

  startEntrySequence();  // print Startbildschirm
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

  help1 = CollisionDistance;

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
        M5.Lcd.setCursor(0, 100);
        M5.Lcd.setTextColor(M5.Lcd.color565(255, 131, 250));
        M5.Lcd.setTextSize(3);
        M5.Lcd.println("  VICTORY! ");
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
            M5.Lcd.println("  VICTORY! ");
            M5.Lcd.setCursor(80, 210);
            M5.Lcd.setTextColor(BLACK);
            M5.Lcd.setTextSize(2);
            M5.Lcd.println("play again? ");
            CollisionDistance = false;
            PosAsteroid1 = 40;
            StartPointAsteroid1 = 0;
            PosAsteroid2 = 140;
            StartPointAsteroid2 = 100;
            PosAsteroid3 = 60;
            StartPointAsteroid3 = 50;
            LevelPosPlus = 20;
            Level = -3;
            CountHit = 0;
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
      M5.Lcd.setRotation(0);
      M5.Lcd.setTextSize(3);
      M5.Lcd.setCursor(10, 290);
      M5.Lcd.setTextColor(RED);
      M5.Lcd.print("Score: ");
      M5.Lcd.setTextColor(M5.Lcd.color565(117, 117, 117));
      M5.Lcd.print(z / 20);
      // M5.Lcd.print(help2); // nur debugging
      M5.Lcd.setTextColor(RED);
      M5.Lcd.setCursor(10, 290);
      M5.Lcd.print("Score: ");
      z = z + 1;
      if (z == 100) {
        LevelPosPlus = 25;
      }
      if (z == 200) {
        LevelPosPlus = 30;
      }
      if (z == 300) {
        LevelPosPlus = 35;
        Level = -2;
      }
      if (z == 400) {
        LevelPosPlus = 40;
      }
      if (z == 500) {
        LevelPosPlus = 45;
      }
      if (z == 600) {
        LevelPosPlus = 50;
        Level = -1;
      }
      if (z == 700) {
        LevelPosPlus = 55;
      }
      if (z == 800) {
        LevelPosPlus = 60;
      }
      if (z == 900) {
        LevelPosPlus = 65;
        Level = 0;
      }
      if (z == 1000) {
        LevelPosPlus = 70;
      }
      if (z == 1100) {
        LevelPosPlus = 75;
      }
      if (z == 1200) {
        LevelPosPlus = 80;
        Level = 1;
      }
      if (z == 1300) {
        LevelPosPlus = 85;
      }
      if (z == 1400) {
        LevelPosPlus = 90;
      }
      if (z == 1500) {
        LevelPosPlus = 95;
        Level = 2;
      }
      if (z == 1600) {
        LevelPosPlus = 100;
      }
      if (z == 1700) {
        LevelPosPlus = 105;
      }
      if (z == 1800) {
        LevelPosPlus = 115;
        Level = 3;
      }
      if (z == 1900) {
        LevelPosPlus = 120;
      }
      if (z == 2000) {
        LevelPosPlus = 125;
      }
      if (z == 2100) {
        LevelPosPlus = 130;
        Level = 4;
      }
      if (z == 2200) {
        LevelPosPlus = 135;
      }
      if (z == 2300) {
        LevelPosPlus = 140;
      }
      if (z == 2400) {
        LevelPosPlus = 145;
        Level = 5;
      }
      if (z == 2500) {
        LevelPosPlus = 155;
      }
      if (z == 2600) {
        LevelPosPlus = 160;
      }
      if (z == 2700) {
        LevelPosPlus = 165;
        Level = 6;
      }
      if (z == 2800) {
        LevelPosPlus = 170;
      }
      M5.Lcd.print(z / 20);
      M5.Lcd.setRotation(1);
      break;
    }
  }
}


void startEntrySequence() { // print Startbildschirm
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 80);
  M5.Lcd.setTextColor(M5.Lcd.color565(255, 131, 250));
  M5.Lcd.setTextSize(3);
  M5.Lcd.println(" RJPlog's ");
  M5.Lcd.println(" Crazy Asteroids");
  M5.Lcd.setCursor(100, 210);
  M5.Lcd.setTextColor(M5.Lcd.color565(139, 0, 139));
  M5.Lcd.setTextSize(2);
  M5.Lcd.println("  press B ");
  while (1) {
    // wait for push button
    if (M5.BtnB.read()) {
      while (1) {
        if (!M5.BtnB.read()) {
          M5.Lcd.fillScreen(BLACK);
          M5.Lcd.fillRect(265, 1, 55, 240, M5.Lcd.color565(117, 117, 117));
          M5.Lcd.setRotation(0);
          M5.Lcd.setTextSize(3);
          M5.Lcd.setCursor(10, 290);
          M5.Lcd.setTextColor(RED);
          //M5.Lcd.print("Score: ");
          M5.Lcd.setRotation(1);
          break;
        }
      }
      break;
    }
  }
}

void printSpaceShip()  {
  int SpaceShip [][SpaceShipW] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1, 1, 3, 3, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 1, 2, 3, 3, 2, 1, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 1, 0, 2, 1, 1, 1, 1, 2, 0, 1, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 2, 0, 0, 2, 1, 1, 1, 1, 2, 0, 0, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  for (i = 0; i < SpaceShipH; i = i + 1) {
    for (j = 0; j < SpaceShipW; j = j + 1) {
      if (SpaceShip[i][j] != 0) {
        if (SpaceShip[i][j] == 1) {
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(238, 213, 183));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(238, 213, 183));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(238, 213, 183));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(238, 213, 183));
        }
        if (SpaceShip[i][j] == 2) {
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(105, 105, 105));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(105, 105, 105));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(105, 105, 105));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(105, 105, 105));
        }
        if (SpaceShip[i][j] == 3) {
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(198, 226, 255));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(198, 226, 225));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(198, 226, 225));
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(198, 226, 225));
        }
        if (SpaceShip[i][j] == 5) {
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, RED);
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, RED);
          M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, RED);
          M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, RED);
        }
        if (SpaceShip[i][j] == 4) {
          if (BoostColor < 5) {
            /*  M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2, M5.Lcd.color565(255, 131, 250));
              M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2, M5.Lcd.color565(255, 131, 250));
              M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2 + 1, M5.Lcd.color565(255, 131, 250));
              M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2 + 1, M5.Lcd.color565(255, 131, 250));*/
            M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(255, 165, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(255, 165, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(255, 165, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(255, 165, 0));
          }
          if (BoostColor > 4) {
            /*       M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2, M5.Lcd.color565(139, 0, 139));
                   M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2, M5.Lcd.color565(139, 0, 139));
                   M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2 + 1, M5.Lcd.color565(139, 0, 139));
                   M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 - SpaceShipGap + i * 2 + 1, M5.Lcd.color565(139, 0, 139)); */
            M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(255, 0, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, M5.Lcd.color565(255, 0, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(255, 0, 0));
            M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, M5.Lcd.color565(255, 0, 0));
          }
          if (BoostColor == 10) {
            BoostColor = 0;
          }
          else {
            BoostColor ++;
          }
        }
      }
      else {
        M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, BLACK);
        M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 - LevelPosPlus, BLACK);
        M5.Lcd.drawPixel(PosSpaceShip + j * 2, TFTH - SpaceShipH * 2  + i * 2 + 1 - LevelPosPlus, BLACK);
        M5.Lcd.drawPixel(PosSpaceShip + j * 2 + 1, TFTH - SpaceShipH * 2 + i * 2 + 1 - LevelPosPlus, BLACK);

      }
    }
  }
}

void printAsteroid1() {
  int Asteroid1 [][Asteroid1W] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0},
    {0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9},
    {9, 9, 6, 6, 6, 6, 6, 6, 6, 9, 9},
    {9, 9, 9, 9, 6, 6, 6, 9, 9, 9, 9}
  };

  Asteroid1Lockedx = StartPointAsteroid1 - (PosSpaceShip + 12);

  if ((abs(Asteroid1Lockedx) < 11) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap)) > 50 ) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap)) < 120 )) {
    Asteroid1Locked  = true;
    Asteroid1[12][2] = 1;
    Asteroid1[12][3] = 1;
    Asteroid1[13][2] = 1;
    Asteroid1[14][2] = 1;
    Asteroid1[15][2] = 1;
    Asteroid1[16][2] = 1;
    Asteroid1[17][2] = 1;
    Asteroid1[17][3] = 1;
    Asteroid1[12][7] = 1;
    Asteroid1[12][8] = 1;
    Asteroid1[13][8] = 1;
    Asteroid1[14][8] = 1;
    Asteroid1[15][8] = 1;
    Asteroid1[16][8] = 1;
    Asteroid1[17][8] = 1;
    Asteroid1[17][7] = 1;
  }
  else {
    Asteroid1Locked  = false;
    Asteroid1[13][2] = 6;
    Asteroid1[13][3] = 6;
    Asteroid1[14][2] = 6;
    Asteroid1[15][2] = 6;
    Asteroid1[16][2] = 6;
    Asteroid1[17][2] = 6;
    Asteroid1[18][2] = 6;
    Asteroid1[18][3] = 6;
    Asteroid1[13][7] = 6;
    Asteroid1[13][8] = 6;
    Asteroid1[14][8] = 6;
    Asteroid1[15][8] = 6;
    Asteroid1[16][8] = 6;
    Asteroid1[17][8] = 6;
    Asteroid1[18][8] = 6;
    Asteroid1[18][7] = 6;
  }

  if (Asteroid1Hit) {
    if (iAsteroid1  == 1) {
      Asteroid1Beamx0 = PosSpaceShip + SpaceShipW - 2;
      Asteroid1Beamy0 = TFTH - SpaceShipH * 2 - LevelPosPlus;
      Asteroid1Beamx1 = StartPointAsteroid1 + Asteroid1W - 5;
      Asteroid1Beamy1 = PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap;
      Asteroid1Beamx2 = StartPointAsteroid1 + Asteroid1W + 5;
      Asteroid1Beamy2 = PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap;
      M5.Lcd.fillTriangle(Asteroid1Beamx0, Asteroid1Beamy0, Asteroid1Beamx1, Asteroid1Beamy1, Asteroid1Beamx2, Asteroid1Beamy2, M5.Lcd.color565(255, 165, 0));
      //     M5.Lcd.fillRect(StartPointAsteroid1 + Asteroid1W - 1, PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap), M5.Lcd.color565(255, 165, 0));
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][3] = 1;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 1;

      Asteroid1[17][2] = 1;
      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 1;

      Asteroid1[16][4] = 1;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 1;

      Asteroid1[15][5] = 1;


      Asteroid1[14][4] = 1;
    }
    if (iAsteroid1  == 2) {
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][3] = 1;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 1;


      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 1;
      Asteroid1[17][8] = 1;
      Asteroid1[17][9] = 1;

      Asteroid1[16][2] = 1;
      Asteroid1[16][3] = 0;
      Asteroid1[16][4] = 0;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 0;
      Asteroid1[16][7] = 0;
      Asteroid1[16][8] = 0;

      Asteroid1[15][2] = 1;
      Asteroid1[15][3] = 0;
      Asteroid1[15][4] = 0;
      Asteroid1[15][5] = 1;
      Asteroid1[15][6] = 0;
      Asteroid1[15][7] = 0;
      Asteroid1[15][8] = 0;
      Asteroid1[15][9] = 1;

      Asteroid1[14][1] = 1;
      Asteroid1[14][3] = 1;
      Asteroid1[14][4] = 0;
      Asteroid1[14][6] = 1;
      Asteroid1[14][7] = 1;

      Asteroid1[13][4] = 0;
      Asteroid1[13][5] = 1;
      Asteroid1[13][8] = 1;

      Asteroid1[12][6] = 1;
    }
    if (iAsteroid1  == 3) {
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][2] = 6;
      Asteroid1[18][3] = 1;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 1;
      Asteroid1[18][8] = 1;

      Asteroid1[17][1] = 6;
      Asteroid1[17][2] = 1;
      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 1;
      Asteroid1[17][8] = 1;
      Asteroid1[17][9] = 6;

      Asteroid1[16][0] = 6;
      Asteroid1[16][1] = 1;
      Asteroid1[16][2] = 1;
      Asteroid1[16][3] = 0;
      Asteroid1[16][4] = 0;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 0;
      Asteroid1[16][7] = 0;
      Asteroid1[16][8] = 0;
      Asteroid1[16][9] = 1;
      Asteroid1[16][10] = 6;

      Asteroid1[15][0] = 6;
      Asteroid1[15][1] = 1;
      Asteroid1[15][2] = 0;
      Asteroid1[15][3] = 0;
      Asteroid1[15][4] = 0;
      Asteroid1[15][5] = 1;
      Asteroid1[15][6] = 0;
      Asteroid1[15][7] = 0;
      Asteroid1[15][8] = 0;
      Asteroid1[15][9] = 0;
      Asteroid1[15][10] = 6;


      Asteroid1[14][0] = 1;
      Asteroid1[14][1] = 0;
      Asteroid1[14][2] = 0;
      Asteroid1[14][3] = 1;
      Asteroid1[14][4] = 0;
      Asteroid1[14][5] = 0;
      Asteroid1[14][6] = 1;
      Asteroid1[14][7] = 0;
      Asteroid1[14][8] = 0;
      Asteroid1[14][9] = 1;
      Asteroid1[14][10] = 6;

      Asteroid1[13][0] = 6;
      Asteroid1[13][1] = 1;
      Asteroid1[13][2] = 1;
      Asteroid1[13][3] = 6;
      Asteroid1[13][4] = 0;
      Asteroid1[13][5] = 0;
      Asteroid1[13][6] = 1;
      Asteroid1[13][7] = 0;
      Asteroid1[13][8] = 1;
      Asteroid1[13][9] = 6;
      Asteroid1[13][10] = 6;

      Asteroid1[12][1] = 6;
      Asteroid1[12][2] = 6;
      Asteroid1[12][3] = 6;
      Asteroid1[12][4] = 1;
      Asteroid1[12][5] = 1;
      Asteroid1[12][6] = 1;
      Asteroid1[12][7] = 1;
      Asteroid1[12][8] = 6;
      Asteroid1[12][9] = 6;

      Asteroid1[11][2] = 6;
      Asteroid1[11][3] = 6;
      Asteroid1[11][4] = 6;
      Asteroid1[11][5] = 6;
      Asteroid1[11][6] = 1;
      Asteroid1[11][7] = 6;
      Asteroid1[11][8] = 6;

      Asteroid1[10][4] = 6;
      Asteroid1[10][5] = 1;
      Asteroid1[10][6] = 6;
    }
    if (iAsteroid1  == 4) {
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][2] = 1;
      Asteroid1[18][3] = 1;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 0;
      Asteroid1[18][8] = 0;

      Asteroid1[17][1] = 1;
      Asteroid1[17][2] = 0;
      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 0;
      Asteroid1[17][8] = 0;
      Asteroid1[17][9] = 1;

      Asteroid1[16][0] = 6;
      Asteroid1[16][1] = 6;
      Asteroid1[16][2] = 1;
      Asteroid1[16][3] = 0;
      Asteroid1[16][4] = 0;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 0;
      Asteroid1[16][7] = 0;
      Asteroid1[16][8] = 0;
      Asteroid1[16][9] = 6;
      Asteroid1[16][10] = 1;

      Asteroid1[15][0] = 6;
      Asteroid1[15][1] = 1;
      Asteroid1[15][2] = 0;
      Asteroid1[15][3] = 0;
      Asteroid1[15][4] = 0;
      Asteroid1[15][5] = 0;
      Asteroid1[15][6] = 0;
      Asteroid1[15][7] = 0;
      Asteroid1[15][8] = 0;
      Asteroid1[15][9] = 0;
      Asteroid1[15][10] = 1;

      Asteroid1[14][0] = 1;
      Asteroid1[14][1] = 0;
      Asteroid1[14][2] = 0;
      Asteroid1[14][3] = 6;
      Asteroid1[14][4] = 0;
      Asteroid1[14][5] = 0;
      Asteroid1[14][6] = 1;
      Asteroid1[14][7] = 0;
      Asteroid1[14][8] = 0;
      Asteroid1[14][9] = 1;
      Asteroid1[14][10] = 6;

      Asteroid1[13][0] = 6;
      Asteroid1[13][1] = 1;
      Asteroid1[13][2] = 6;
      Asteroid1[13][3] = 6;
      Asteroid1[13][4] = 0;
      Asteroid1[13][5] = 0;
      Asteroid1[13][6] = 1;
      Asteroid1[13][7] = 0;
      Asteroid1[13][8] = 1;
      Asteroid1[13][9] = 0;
      Asteroid1[13][10] = 6;

      Asteroid1[12][1] = 6;
      Asteroid1[12][2] = 0;
      Asteroid1[12][3] = 1;
      Asteroid1[12][4] = 6;
      Asteroid1[12][5] = 0;
      Asteroid1[12][6] = 1;
      Asteroid1[12][7] = 1;
      Asteroid1[12][8] = 6;
      Asteroid1[12][9] = 6;

      Asteroid1[11][2] = 6;
      Asteroid1[11][3] = 6;
      Asteroid1[11][4] = 1;
      Asteroid1[11][5] = 0;
      Asteroid1[11][6] = 1;
      Asteroid1[11][7] = 6;
      Asteroid1[11][8] = 1;

      Asteroid1[10][4] = 1;
      Asteroid1[10][5] = 1;
      Asteroid1[10][6] = 6;
    }
    if (iAsteroid1  == 5) {
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][2] = 0;
      Asteroid1[18][3] = 0;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 0;
      Asteroid1[18][8] = 0;

      Asteroid1[17][1] = 1;
      Asteroid1[17][2] = 0;
      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 0;
      Asteroid1[17][8] = 0;
      Asteroid1[17][9] = 1;

      Asteroid1[16][0] = 1;
      Asteroid1[16][1] = 6;
      Asteroid1[16][2] = 0;
      Asteroid1[16][3] = 0;
      Asteroid1[16][4] = 0;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 0;
      Asteroid1[16][7] = 0;
      Asteroid1[16][8] = 0;
      Asteroid1[16][9] = 0;
      Asteroid1[16][10] = 1;

      Asteroid1[15][0] = 1;
      Asteroid1[15][1] = 0;
      Asteroid1[15][2] = 0;
      Asteroid1[15][3] = 0;
      Asteroid1[15][4] = 0;
      Asteroid1[15][5] = 0;
      Asteroid1[15][6] = 0;
      Asteroid1[15][7] = 0;
      Asteroid1[15][8] = 0;
      Asteroid1[15][9] = 0;
      Asteroid1[15][10] = 1;

      Asteroid1[14][0] = 0;
      Asteroid1[14][1] = 0;
      Asteroid1[14][2] = 0;
      Asteroid1[14][3] = 0;
      Asteroid1[14][4] = 0;
      Asteroid1[14][5] = 0;
      Asteroid1[14][6] = 0;
      Asteroid1[14][7] = 0;
      Asteroid1[14][8] = 0;
      Asteroid1[14][9] = 0;
      Asteroid1[14][10] = 1;

      Asteroid1[13][0] = 1;
      Asteroid1[13][1] = 1;
      Asteroid1[13][2] = 0;
      Asteroid1[13][3] = 0;
      Asteroid1[13][4] = 0;
      Asteroid1[13][5] = 0;
      Asteroid1[13][6] = 0;
      Asteroid1[13][7] = 0;
      Asteroid1[13][8] = 0;
      Asteroid1[13][9] = 0;
      Asteroid1[13][10] = 6;

      Asteroid1[12][1] = 6;
      Asteroid1[12][2] = 1;
      Asteroid1[12][3] = 0;
      Asteroid1[12][4] = 0;
      Asteroid1[12][5] = 0;
      Asteroid1[12][6] = 0;
      Asteroid1[12][7] = 0;
      Asteroid1[12][8] = 0;
      Asteroid1[12][9] = 1;

      Asteroid1[11][2] = 0;
      Asteroid1[11][3] = 6;
      Asteroid1[11][4] = 1;
      Asteroid1[11][5] = 0;
      Asteroid1[11][6] = 1;
      Asteroid1[11][7] = 1;
      Asteroid1[11][8] = 1;

      Asteroid1[10][4] = 1;
      Asteroid1[10][5] = 0;
      Asteroid1[10][6] = 6;
    }
    if (iAsteroid1  > 5) {
      M5.Lcd.fillTriangle(Asteroid1Beamx0, Asteroid1Beamy0, Asteroid1Beamx1, Asteroid1Beamy1, Asteroid1Beamx2, Asteroid1Beamy2, BLACK);
      //M5.Lcd.fillRect(StartPointAsteroid1 + Asteroid1W - 1, PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid1 - Asteroid1H * 2 - Asteroid1Gap), BLACK);
      Asteroid1[19][4] = 0;
      Asteroid1[19][5] = 0;
      Asteroid1[19][6] = 0;

      Asteroid1[18][2] = 0;
      Asteroid1[18][3] = 0;
      Asteroid1[18][4] = 0;
      Asteroid1[18][5] = 0;
      Asteroid1[18][6] = 0;
      Asteroid1[18][7] = 0;
      Asteroid1[18][8] = 0;

      Asteroid1[17][1] = 0;
      Asteroid1[17][2] = 0;
      Asteroid1[17][3] = 0;
      Asteroid1[17][4] = 0;
      Asteroid1[17][5] = 0;
      Asteroid1[17][6] = 0;
      Asteroid1[17][7] = 0;
      Asteroid1[17][8] = 0;
      Asteroid1[17][9] = 0;

      Asteroid1[16][0] = 0;
      Asteroid1[16][1] = 0;
      Asteroid1[16][2] = 0;
      Asteroid1[16][3] = 0;
      Asteroid1[16][4] = 0;
      Asteroid1[16][5] = 0;
      Asteroid1[16][6] = 0;
      Asteroid1[16][7] = 0;
      Asteroid1[16][8] = 0;
      Asteroid1[16][9] = 0;
      Asteroid1[16][10] = 0;

      Asteroid1[15][0] = 0;
      Asteroid1[15][1] = 0;
      Asteroid1[15][2] = 0;
      Asteroid1[15][3] = 0;
      Asteroid1[15][4] = 0;
      Asteroid1[15][5] = 0;
      Asteroid1[15][6] = 0;
      Asteroid1[15][7] = 0;
      Asteroid1[15][8] = 0;
      Asteroid1[15][9] = 0;
      Asteroid1[15][10] = 0;

      Asteroid1[14][0] = 0;
      Asteroid1[14][1] = 0;
      Asteroid1[14][2] = 0;
      Asteroid1[14][3] = 0;
      Asteroid1[14][4] = 0;
      Asteroid1[14][5] = 0;
      Asteroid1[14][6] = 0;
      Asteroid1[14][7] = 0;
      Asteroid1[14][8] = 0;
      Asteroid1[14][9] = 0;
      Asteroid1[14][10] = 0;

      Asteroid1[13][0] = 0;
      Asteroid1[13][1] = 0;
      Asteroid1[13][2] = 0;
      Asteroid1[13][3] = 0;
      Asteroid1[13][4] = 0;
      Asteroid1[13][5] = 0;
      Asteroid1[13][6] = 0;
      Asteroid1[13][7] = 0;
      Asteroid1[13][8] = 0;
      Asteroid1[13][9] = 0;
      Asteroid1[13][10] = 0;

      Asteroid1[12][1] = 0;
      Asteroid1[12][2] = 0;
      Asteroid1[12][3] = 0;
      Asteroid1[12][4] = 0;
      Asteroid1[12][5] = 0;
      Asteroid1[12][6] = 0;
      Asteroid1[12][7] = 0;
      Asteroid1[12][8] = 0;
      Asteroid1[12][9] = 0;

      Asteroid1[11][2] = 0;
      Asteroid1[11][3] = 0;
      Asteroid1[11][4] = 0;
      Asteroid1[11][5] = 0;
      Asteroid1[11][6] = 0;
      Asteroid1[11][7] = 0;
      Asteroid1[11][8] = 0;

      Asteroid1[10][4] = 0;
      Asteroid1[10][5] = 0;
      Asteroid1[10][6] = 0;
    }
  }



  for (i = 0; i < Asteroid1H; i = i + 1) {
    for (j = 0; j < Asteroid1W; j = j + 1) {
      if (Asteroid1[i][j] != 0) {
        if (Asteroid1[i][j] == 6) {
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, M5.Lcd.color565(139, 115, 85));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, M5.Lcd.color565(139, 115, 85));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, M5.Lcd.color565(139, 115, 85));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, M5.Lcd.color565(139, 115, 85));
        }
        if (Asteroid1[i][j] == 1) {
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, RED);
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, RED);
        }
        if (Asteroid1[i][j] == 8) {
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, M5.Lcd.color565(255, 165, 0));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, M5.Lcd.color565(255, 165, 0));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, M5.Lcd.color565(255, 165, 0));
          M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, M5.Lcd.color565(255, 165, 0));
        }
      }
      else {
        M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid1 + j * 2 + 1, PosAsteroid1  - Asteroid1H * 2 - Asteroid1Gap + i * 2 + 1, BLACK);

      }
    }
  }
}


void printAsteroid2() {
  int Asteroid2 [][Asteroid2W] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0},
    {0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9},
    {9, 9, 6, 6, 6, 6, 6, 6, 6, 9, 9},
    {9, 9, 9, 9, 6, 6, 6, 9, 9, 9, 9}
  };
  Asteroid2Lockedx = StartPointAsteroid2 - (PosSpaceShip + 12);

  if ((abs(Asteroid2Lockedx) < 11) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid2 - Asteroid1H * 2 - Asteroid2Gap)) > 50 ) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap)) < 120 )) {
    Asteroid2Locked = true;
    Asteroid2[12][2] = 1;
    Asteroid2[12][3] = 1;
    Asteroid2[13][2] = 1;
    Asteroid2[14][2] = 1;
    Asteroid2[15][2] = 1;
    Asteroid2[16][2] = 1;
    Asteroid2[17][2] = 1;
    Asteroid2[17][3] = 1;
    Asteroid2[12][7] = 1;
    Asteroid2[12][8] = 1;
    Asteroid2[13][8] = 1;
    Asteroid2[14][8] = 1;
    Asteroid2[15][8] = 1;
    Asteroid2[16][8] = 1;
    Asteroid2[17][8] = 1;
    Asteroid2[17][7] = 1;
  }
  else {
    Asteroid2Locked = false;
    Asteroid2[13][2] = 6;
    Asteroid2[13][3] = 6;
    Asteroid2[14][2] = 6;
    Asteroid2[15][2] = 6;
    Asteroid2[16][2] = 6;
    Asteroid2[17][2] = 6;
    Asteroid2[18][2] = 6;
    Asteroid2[18][3] = 6;
    Asteroid2[13][7] = 6;
    Asteroid2[13][8] = 6;
    Asteroid2[14][8] = 6;
    Asteroid2[15][8] = 6;
    Asteroid2[16][8] = 6;
    Asteroid2[17][8] = 6;
    Asteroid2[18][8] = 6;
    Asteroid2[18][7] = 6;
  }

  if (Asteroid2Hit) {
    if (iAsteroid2  == 1) {
      Asteroid2Beamx0 = PosSpaceShip + SpaceShipW - 2;
      Asteroid2Beamy0 = TFTH - SpaceShipH * 2 - LevelPosPlus;
      Asteroid2Beamx1 = StartPointAsteroid2 + Asteroid2W - 5;
      Asteroid2Beamy1 = PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap;
      Asteroid2Beamx2 = StartPointAsteroid2 + Asteroid2W + 5;
      Asteroid2Beamy2 = PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap;
      M5.Lcd.fillTriangle(Asteroid2Beamx0, Asteroid2Beamy0, Asteroid2Beamx1, Asteroid2Beamy1, Asteroid2Beamx2, Asteroid2Beamy2, M5.Lcd.color565(255, 165, 0));
      //     M5.Lcd.fillRect(StartPointAsteroid2 + Asteroid2W - 1, PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap), M5.Lcd.color565(255, 165, 0));
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][3] = 1;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 1;

      Asteroid2[17][2] = 1;
      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 1;

      Asteroid2[16][4] = 1;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 1;

      Asteroid2[15][5] = 1;


      Asteroid2[14][4] = 1;
    }
    if (iAsteroid2  == 2) {
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][3] = 1;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 1;


      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 1;
      Asteroid2[17][8] = 1;
      Asteroid2[17][9] = 1;

      Asteroid2[16][2] = 1;
      Asteroid2[16][3] = 0;
      Asteroid2[16][4] = 0;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 0;
      Asteroid2[16][7] = 0;
      Asteroid2[16][8] = 0;

      Asteroid2[15][2] = 1;
      Asteroid2[15][3] = 0;
      Asteroid2[15][4] = 0;
      Asteroid2[15][5] = 1;
      Asteroid2[15][6] = 0;
      Asteroid2[15][7] = 0;
      Asteroid2[15][8] = 0;
      Asteroid2[15][9] = 1;

      Asteroid2[14][1] = 1;
      Asteroid2[14][3] = 1;
      Asteroid2[14][4] = 0;
      Asteroid2[14][6] = 1;
      Asteroid2[14][7] = 1;

      Asteroid2[13][4] = 0;
      Asteroid2[13][5] = 1;
      Asteroid2[13][8] = 1;

      Asteroid2[12][6] = 1;
    }
    if (iAsteroid2  == 3) {
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][2] = 6;
      Asteroid2[18][3] = 1;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 1;
      Asteroid2[18][8] = 1;

      Asteroid2[17][1] = 6;
      Asteroid2[17][2] = 1;
      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 1;
      Asteroid2[17][8] = 1;
      Asteroid2[17][9] = 6;

      Asteroid2[16][0] = 6;
      Asteroid2[16][1] = 1;
      Asteroid2[16][2] = 1;
      Asteroid2[16][3] = 0;
      Asteroid2[16][4] = 0;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 0;
      Asteroid2[16][7] = 0;
      Asteroid2[16][8] = 0;
      Asteroid2[16][9] = 1;
      Asteroid2[16][10] = 6;

      Asteroid2[15][0] = 6;
      Asteroid2[15][1] = 1;
      Asteroid2[15][2] = 0;
      Asteroid2[15][3] = 0;
      Asteroid2[15][4] = 0;
      Asteroid2[15][5] = 1;
      Asteroid2[15][6] = 0;
      Asteroid2[15][7] = 0;
      Asteroid2[15][8] = 0;
      Asteroid2[15][9] = 0;
      Asteroid2[15][10] = 6;


      Asteroid2[14][0] = 1;
      Asteroid2[14][1] = 0;
      Asteroid2[14][2] = 0;
      Asteroid2[14][3] = 1;
      Asteroid2[14][4] = 0;
      Asteroid2[14][5] = 0;
      Asteroid2[14][6] = 1;
      Asteroid2[14][7] = 0;
      Asteroid2[14][8] = 0;
      Asteroid2[14][9] = 1;
      Asteroid2[14][10] = 6;

      Asteroid2[13][0] = 6;
      Asteroid2[13][1] = 1;
      Asteroid2[13][2] = 1;
      Asteroid2[13][3] = 6;
      Asteroid2[13][4] = 0;
      Asteroid2[13][5] = 0;
      Asteroid2[13][6] = 1;
      Asteroid2[13][7] = 0;
      Asteroid2[13][8] = 1;
      Asteroid2[13][9] = 6;
      Asteroid2[13][10] = 6;

      Asteroid2[12][1] = 6;
      Asteroid2[12][2] = 6;
      Asteroid2[12][3] = 6;
      Asteroid2[12][4] = 1;
      Asteroid2[12][5] = 1;
      Asteroid2[12][6] = 1;
      Asteroid2[12][7] = 1;
      Asteroid2[12][8] = 6;
      Asteroid2[12][9] = 6;

      Asteroid2[11][2] = 6;
      Asteroid2[11][3] = 6;
      Asteroid2[11][4] = 6;
      Asteroid2[11][5] = 6;
      Asteroid2[11][6] = 1;
      Asteroid2[11][7] = 6;
      Asteroid2[11][8] = 6;

      Asteroid2[10][4] = 6;
      Asteroid2[10][5] = 1;
      Asteroid2[10][6] = 6;
    }
    if (iAsteroid2  == 4) {
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][2] = 1;
      Asteroid2[18][3] = 1;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 0;
      Asteroid2[18][8] = 0;

      Asteroid2[17][1] = 1;
      Asteroid2[17][2] = 0;
      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 0;
      Asteroid2[17][8] = 0;
      Asteroid2[17][9] = 1;

      Asteroid2[16][0] = 6;
      Asteroid2[16][1] = 6;
      Asteroid2[16][2] = 1;
      Asteroid2[16][3] = 0;
      Asteroid2[16][4] = 0;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 0;
      Asteroid2[16][7] = 0;
      Asteroid2[16][8] = 0;
      Asteroid2[16][9] = 6;
      Asteroid2[16][10] = 1;

      Asteroid2[15][0] = 6;
      Asteroid2[15][1] = 1;
      Asteroid2[15][2] = 0;
      Asteroid2[15][3] = 0;
      Asteroid2[15][4] = 0;
      Asteroid2[15][5] = 0;
      Asteroid2[15][6] = 0;
      Asteroid2[15][7] = 0;
      Asteroid2[15][8] = 0;
      Asteroid2[15][9] = 0;
      Asteroid2[15][10] = 1;

      Asteroid2[14][0] = 1;
      Asteroid2[14][1] = 0;
      Asteroid2[14][2] = 0;
      Asteroid2[14][3] = 6;
      Asteroid2[14][4] = 0;
      Asteroid2[14][5] = 0;
      Asteroid2[14][6] = 1;
      Asteroid2[14][7] = 0;
      Asteroid2[14][8] = 0;
      Asteroid2[14][9] = 1;
      Asteroid2[14][10] = 6;

      Asteroid2[13][0] = 6;
      Asteroid2[13][1] = 1;
      Asteroid2[13][2] = 6;
      Asteroid2[13][3] = 6;
      Asteroid2[13][4] = 0;
      Asteroid2[13][5] = 0;
      Asteroid2[13][6] = 1;
      Asteroid2[13][7] = 0;
      Asteroid2[13][8] = 1;
      Asteroid2[13][9] = 0;
      Asteroid2[13][10] = 6;

      Asteroid2[12][1] = 6;
      Asteroid2[12][2] = 0;
      Asteroid2[12][3] = 1;
      Asteroid2[12][4] = 6;
      Asteroid2[12][5] = 0;
      Asteroid2[12][6] = 1;
      Asteroid2[12][7] = 1;
      Asteroid2[12][8] = 6;
      Asteroid2[12][9] = 6;

      Asteroid2[11][2] = 6;
      Asteroid2[11][3] = 6;
      Asteroid2[11][4] = 1;
      Asteroid2[11][5] = 0;
      Asteroid2[11][6] = 1;
      Asteroid2[11][7] = 6;
      Asteroid2[11][8] = 1;

      Asteroid2[10][4] = 1;
      Asteroid2[10][5] = 1;
      Asteroid2[10][6] = 6;
    }
    if (iAsteroid2  == 5) {
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][2] = 0;
      Asteroid2[18][3] = 0;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 0;
      Asteroid2[18][8] = 0;

      Asteroid2[17][1] = 1;
      Asteroid2[17][2] = 0;
      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 0;
      Asteroid2[17][8] = 0;
      Asteroid2[17][9] = 1;

      Asteroid2[16][0] = 1;
      Asteroid2[16][1] = 6;
      Asteroid2[16][2] = 0;
      Asteroid2[16][3] = 0;
      Asteroid2[16][4] = 0;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 0;
      Asteroid2[16][7] = 0;
      Asteroid2[16][8] = 0;
      Asteroid2[16][9] = 0;
      Asteroid2[16][10] = 1;

      Asteroid2[15][0] = 1;
      Asteroid2[15][1] = 0;
      Asteroid2[15][2] = 0;
      Asteroid2[15][3] = 0;
      Asteroid2[15][4] = 0;
      Asteroid2[15][5] = 0;
      Asteroid2[15][6] = 0;
      Asteroid2[15][7] = 0;
      Asteroid2[15][8] = 0;
      Asteroid2[15][9] = 0;
      Asteroid2[15][10] = 1;

      Asteroid2[14][0] = 0;
      Asteroid2[14][1] = 0;
      Asteroid2[14][2] = 0;
      Asteroid2[14][3] = 0;
      Asteroid2[14][4] = 0;
      Asteroid2[14][5] = 0;
      Asteroid2[14][6] = 0;
      Asteroid2[14][7] = 0;
      Asteroid2[14][8] = 0;
      Asteroid2[14][9] = 0;
      Asteroid2[14][10] = 1;

      Asteroid2[13][0] = 1;
      Asteroid2[13][1] = 1;
      Asteroid2[13][2] = 0;
      Asteroid2[13][3] = 0;
      Asteroid2[13][4] = 0;
      Asteroid2[13][5] = 0;
      Asteroid2[13][6] = 0;
      Asteroid2[13][7] = 0;
      Asteroid2[13][8] = 0;
      Asteroid2[13][9] = 0;
      Asteroid2[13][10] = 6;

      Asteroid2[12][1] = 6;
      Asteroid2[12][2] = 1;
      Asteroid2[12][3] = 0;
      Asteroid2[12][4] = 0;
      Asteroid2[12][5] = 0;
      Asteroid2[12][6] = 0;
      Asteroid2[12][7] = 0;
      Asteroid2[12][8] = 0;
      Asteroid2[12][9] = 1;

      Asteroid2[11][2] = 0;
      Asteroid2[11][3] = 6;
      Asteroid2[11][4] = 1;
      Asteroid2[11][5] = 0;
      Asteroid2[11][6] = 1;
      Asteroid2[11][7] = 1;
      Asteroid2[11][8] = 1;

      Asteroid2[10][4] = 1;
      Asteroid2[10][5] = 0;
      Asteroid2[10][6] = 6;
    }
    if (iAsteroid2  > 5) {
      M5.Lcd.fillTriangle(Asteroid2Beamx0, Asteroid2Beamy0, Asteroid2Beamx1, Asteroid2Beamy1, Asteroid2Beamx2, Asteroid2Beamy2, BLACK);
      //  M5.Lcd.fillRect(StartPointAsteroid2 + Asteroid2W - 1, PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid2 - Asteroid2H * 2 - Asteroid2Gap), BLACK);
      Asteroid2[19][4] = 0;
      Asteroid2[19][5] = 0;
      Asteroid2[19][6] = 0;

      Asteroid2[18][2] = 0;
      Asteroid2[18][3] = 0;
      Asteroid2[18][4] = 0;
      Asteroid2[18][5] = 0;
      Asteroid2[18][6] = 0;
      Asteroid2[18][7] = 0;
      Asteroid2[18][8] = 0;

      Asteroid2[17][1] = 0;
      Asteroid2[17][2] = 0;
      Asteroid2[17][3] = 0;
      Asteroid2[17][4] = 0;
      Asteroid2[17][5] = 0;
      Asteroid2[17][6] = 0;
      Asteroid2[17][7] = 0;
      Asteroid2[17][8] = 0;
      Asteroid2[17][9] = 0;

      Asteroid2[16][0] = 0;
      Asteroid2[16][1] = 0;
      Asteroid2[16][2] = 0;
      Asteroid2[16][3] = 0;
      Asteroid2[16][4] = 0;
      Asteroid2[16][5] = 0;
      Asteroid2[16][6] = 0;
      Asteroid2[16][7] = 0;
      Asteroid2[16][8] = 0;
      Asteroid2[16][9] = 0;
      Asteroid2[16][10] = 0;

      Asteroid2[15][0] = 0;
      Asteroid2[15][1] = 0;
      Asteroid2[15][2] = 0;
      Asteroid2[15][3] = 0;
      Asteroid2[15][4] = 0;
      Asteroid2[15][5] = 0;
      Asteroid2[15][6] = 0;
      Asteroid2[15][7] = 0;
      Asteroid2[15][8] = 0;
      Asteroid2[15][9] = 0;
      Asteroid2[15][10] = 0;

      Asteroid2[14][0] = 0;
      Asteroid2[14][1] = 0;
      Asteroid2[14][2] = 0;
      Asteroid2[14][3] = 0;
      Asteroid2[14][4] = 0;
      Asteroid2[14][5] = 0;
      Asteroid2[14][6] = 0;
      Asteroid2[14][7] = 0;
      Asteroid2[14][8] = 0;
      Asteroid2[14][9] = 0;
      Asteroid2[14][10] = 0;

      Asteroid2[13][0] = 0;
      Asteroid2[13][1] = 0;
      Asteroid2[13][2] = 0;
      Asteroid2[13][3] = 0;
      Asteroid2[13][4] = 0;
      Asteroid2[13][5] = 0;
      Asteroid2[13][6] = 0;
      Asteroid2[13][7] = 0;
      Asteroid2[13][8] = 0;
      Asteroid2[13][9] = 0;
      Asteroid2[13][10] = 0;

      Asteroid2[12][1] = 0;
      Asteroid2[12][2] = 0;
      Asteroid2[12][3] = 0;
      Asteroid2[12][4] = 0;
      Asteroid2[12][5] = 0;
      Asteroid2[12][6] = 0;
      Asteroid2[12][7] = 0;
      Asteroid2[12][8] = 0;
      Asteroid2[12][9] = 0;

      Asteroid2[11][2] = 0;
      Asteroid2[11][3] = 0;
      Asteroid2[11][4] = 0;
      Asteroid2[11][5] = 0;
      Asteroid2[11][6] = 0;
      Asteroid2[11][7] = 0;
      Asteroid2[11][8] = 0;

      Asteroid2[10][4] = 0;
      Asteroid2[10][5] = 0;
      Asteroid2[10][6] = 0;
    }
  }


  for (i = 0; i < Asteroid2H; i = i + 1) {
    for (j = 0; j < Asteroid2W; j = j + 1) {
      if (Asteroid2[i][j] != 0) {
        if (Asteroid2[i][j] == 6) {
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, M5.Lcd.color565(238, 197, 145));
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, M5.Lcd.color565(238, 197, 145));
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, M5.Lcd.color565(238, 197, 145));
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, M5.Lcd.color565(238, 197, 145));
        }
        if (Asteroid2[i][j] == 1) {
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, RED);
          M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, RED);
        }
      }
      else {
        M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid2 + j * 2 + 1, PosAsteroid2  - Asteroid2H * 2 - Asteroid2Gap + i * 2 + 1, BLACK);

      }
    }
  }
}

void printAsteroid3() {
  int Asteroid3 [][Asteroid3W] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 6, 6, 6, 0, 0, 0, 0},
    {0, 0, 6, 6, 6, 6, 6, 6, 6, 0, 0},
    {0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {9, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9},
    {9, 9, 6, 6, 6, 6, 6, 6, 6, 9, 9},
    {9, 9, 9, 9, 6, 6, 6, 9, 9, 9, 9}
  };
  Asteroid3Lockedx = StartPointAsteroid3 - (PosSpaceShip + 12);
  if ((abs(Asteroid3Lockedx) < 11) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap)) > 50 ) && (((TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap)) < 120 )) {
    Asteroid3Locked = true;
    Asteroid3[12][2] = 1;
    Asteroid3[12][3] = 1;
    Asteroid3[13][2] = 1;
    Asteroid3[14][2] = 1;
    Asteroid3[15][2] = 1;
    Asteroid3[16][2] = 1;
    Asteroid3[17][2] = 1;
    Asteroid3[17][3] = 1;
    Asteroid3[12][7] = 1;
    Asteroid3[12][8] = 1;
    Asteroid3[13][8] = 1;
    Asteroid3[14][8] = 1;
    Asteroid3[15][8] = 1;
    Asteroid3[16][8] = 1;
    Asteroid3[17][8] = 1;
    Asteroid3[17][7] = 1;
  }
  else {
    Asteroid3Locked = false;
    Asteroid3[13][2] = 6;
    Asteroid3[13][3] = 6;
    Asteroid3[14][2] = 6;
    Asteroid3[15][2] = 6;
    Asteroid3[16][2] = 6;
    Asteroid3[17][2] = 6;
    Asteroid3[18][2] = 6;
    Asteroid3[18][3] = 6;
    Asteroid3[13][7] = 6;
    Asteroid3[13][8] = 6;
    Asteroid3[14][8] = 6;
    Asteroid3[15][8] = 6;
    Asteroid3[16][8] = 6;
    Asteroid3[17][8] = 6;
    Asteroid3[18][8] = 6;
    Asteroid3[18][7] = 6;
  }

  if (Asteroid3Hit) {
    if (iAsteroid3  == 1) {
      Asteroid3Beamx0 = PosSpaceShip + SpaceShipW - 2;
      Asteroid3Beamy0 = TFTH - SpaceShipH * 2 - LevelPosPlus;
      Asteroid3Beamx1 = StartPointAsteroid3 + Asteroid3W - 5;
      Asteroid3Beamy1 = PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap;
      Asteroid3Beamx2 = StartPointAsteroid3 + Asteroid3W + 5;
      Asteroid3Beamy2 = PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap;
      M5.Lcd.fillTriangle(Asteroid3Beamx0, Asteroid3Beamy0, Asteroid3Beamx1, Asteroid3Beamy1, Asteroid3Beamx2, Asteroid3Beamy2, M5.Lcd.color565(255, 165, 0));
      //     M5.Lcd.fillRect(StartPointAsteroid3 + Asteroid3W - 1, PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap), M5.Lcd.color565(255, 165, 0));
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][3] = 1;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 1;

      Asteroid3[17][2] = 1;
      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 1;

      Asteroid3[16][4] = 1;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 1;

      Asteroid3[15][5] = 1;


      Asteroid3[14][4] = 1;
    }
    if (iAsteroid3  == 2) {
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][3] = 1;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 1;


      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 1;
      Asteroid3[17][8] = 1;
      Asteroid3[17][9] = 1;

      Asteroid3[16][2] = 1;
      Asteroid3[16][3] = 0;
      Asteroid3[16][4] = 0;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 0;
      Asteroid3[16][7] = 0;
      Asteroid3[16][8] = 0;

      Asteroid3[15][2] = 1;
      Asteroid3[15][3] = 0;
      Asteroid3[15][4] = 0;
      Asteroid3[15][5] = 1;
      Asteroid3[15][6] = 0;
      Asteroid3[15][7] = 0;
      Asteroid3[15][8] = 0;
      Asteroid3[15][9] = 1;

      Asteroid3[14][1] = 1;
      Asteroid3[14][3] = 1;
      Asteroid3[14][4] = 0;
      Asteroid3[14][6] = 1;
      Asteroid3[14][7] = 1;

      Asteroid3[13][4] = 0;
      Asteroid3[13][5] = 1;
      Asteroid3[13][8] = 1;

      Asteroid3[12][6] = 1;
    }
    if (iAsteroid3  == 3) {
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][2] = 6;
      Asteroid3[18][3] = 1;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 1;
      Asteroid3[18][8] = 1;

      Asteroid3[17][1] = 6;
      Asteroid3[17][2] = 1;
      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 1;
      Asteroid3[17][8] = 1;
      Asteroid3[17][9] = 6;

      Asteroid3[16][0] = 6;
      Asteroid3[16][1] = 1;
      Asteroid3[16][2] = 1;
      Asteroid3[16][3] = 0;
      Asteroid3[16][4] = 0;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 0;
      Asteroid3[16][7] = 0;
      Asteroid3[16][8] = 0;
      Asteroid3[16][9] = 1;
      Asteroid3[16][10] = 6;

      Asteroid3[15][0] = 6;
      Asteroid3[15][1] = 1;
      Asteroid3[15][2] = 0;
      Asteroid3[15][3] = 0;
      Asteroid3[15][4] = 0;
      Asteroid3[15][5] = 1;
      Asteroid3[15][6] = 0;
      Asteroid3[15][7] = 0;
      Asteroid3[15][8] = 0;
      Asteroid3[15][9] = 0;
      Asteroid3[15][10] = 6;


      Asteroid3[14][0] = 1;
      Asteroid3[14][1] = 0;
      Asteroid3[14][2] = 0;
      Asteroid3[14][3] = 1;
      Asteroid3[14][4] = 0;
      Asteroid3[14][5] = 0;
      Asteroid3[14][6] = 1;
      Asteroid3[14][7] = 0;
      Asteroid3[14][8] = 0;
      Asteroid3[14][9] = 1;
      Asteroid3[14][10] = 6;

      Asteroid3[13][0] = 6;
      Asteroid3[13][1] = 1;
      Asteroid3[13][2] = 1;
      Asteroid3[13][3] = 6;
      Asteroid3[13][4] = 0;
      Asteroid3[13][5] = 0;
      Asteroid3[13][6] = 1;
      Asteroid3[13][7] = 0;
      Asteroid3[13][8] = 1;
      Asteroid3[13][9] = 6;
      Asteroid3[13][10] = 6;

      Asteroid3[12][1] = 6;
      Asteroid3[12][2] = 6;
      Asteroid3[12][3] = 6;
      Asteroid3[12][4] = 1;
      Asteroid3[12][5] = 1;
      Asteroid3[12][6] = 1;
      Asteroid3[12][7] = 1;
      Asteroid3[12][8] = 6;
      Asteroid3[12][9] = 6;

      Asteroid3[11][2] = 6;
      Asteroid3[11][3] = 6;
      Asteroid3[11][4] = 6;
      Asteroid3[11][5] = 6;
      Asteroid3[11][6] = 1;
      Asteroid3[11][7] = 6;
      Asteroid3[11][8] = 6;

      Asteroid3[10][4] = 6;
      Asteroid3[10][5] = 1;
      Asteroid3[10][6] = 6;
    }
    if (iAsteroid3  == 4) {
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][2] = 1;
      Asteroid3[18][3] = 1;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 0;
      Asteroid3[18][8] = 0;

      Asteroid3[17][1] = 1;
      Asteroid3[17][2] = 0;
      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 0;
      Asteroid3[17][8] = 0;
      Asteroid3[17][9] = 1;

      Asteroid3[16][0] = 6;
      Asteroid3[16][1] = 6;
      Asteroid3[16][2] = 1;
      Asteroid3[16][3] = 0;
      Asteroid3[16][4] = 0;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 0;
      Asteroid3[16][7] = 0;
      Asteroid3[16][8] = 0;
      Asteroid3[16][9] = 6;
      Asteroid3[16][10] = 1;

      Asteroid3[15][0] = 6;
      Asteroid3[15][1] = 1;
      Asteroid3[15][2] = 0;
      Asteroid3[15][3] = 0;
      Asteroid3[15][4] = 0;
      Asteroid3[15][5] = 0;
      Asteroid3[15][6] = 0;
      Asteroid3[15][7] = 0;
      Asteroid3[15][8] = 0;
      Asteroid3[15][9] = 0;
      Asteroid3[15][10] = 1;

      Asteroid3[14][0] = 1;
      Asteroid3[14][1] = 0;
      Asteroid3[14][2] = 0;
      Asteroid3[14][3] = 6;
      Asteroid3[14][4] = 0;
      Asteroid3[14][5] = 0;
      Asteroid3[14][6] = 1;
      Asteroid3[14][7] = 0;
      Asteroid3[14][8] = 0;
      Asteroid3[14][9] = 1;
      Asteroid3[14][10] = 6;

      Asteroid3[13][0] = 6;
      Asteroid3[13][1] = 1;
      Asteroid3[13][2] = 6;
      Asteroid3[13][3] = 6;
      Asteroid3[13][4] = 0;
      Asteroid3[13][5] = 0;
      Asteroid3[13][6] = 1;
      Asteroid3[13][7] = 0;
      Asteroid3[13][8] = 1;
      Asteroid3[13][9] = 0;
      Asteroid3[13][10] = 6;

      Asteroid3[12][1] = 6;
      Asteroid3[12][2] = 0;
      Asteroid3[12][3] = 1;
      Asteroid3[12][4] = 6;
      Asteroid3[12][5] = 0;
      Asteroid3[12][6] = 1;
      Asteroid3[12][7] = 1;
      Asteroid3[12][8] = 6;
      Asteroid3[12][9] = 6;

      Asteroid3[11][2] = 6;
      Asteroid3[11][3] = 6;
      Asteroid3[11][4] = 1;
      Asteroid3[11][5] = 0;
      Asteroid3[11][6] = 1;
      Asteroid3[11][7] = 6;
      Asteroid3[11][8] = 1;

      Asteroid3[10][4] = 1;
      Asteroid3[10][5] = 1;
      Asteroid3[10][6] = 6;
    }
    if (iAsteroid3  == 5) {
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][2] = 0;
      Asteroid3[18][3] = 0;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 0;
      Asteroid3[18][8] = 0;

      Asteroid3[17][1] = 1;
      Asteroid3[17][2] = 0;
      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 0;
      Asteroid3[17][8] = 0;
      Asteroid3[17][9] = 1;

      Asteroid3[16][0] = 1;
      Asteroid3[16][1] = 6;
      Asteroid3[16][2] = 0;
      Asteroid3[16][3] = 0;
      Asteroid3[16][4] = 0;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 0;
      Asteroid3[16][7] = 0;
      Asteroid3[16][8] = 0;
      Asteroid3[16][9] = 0;
      Asteroid3[16][10] = 1;

      Asteroid3[15][0] = 1;
      Asteroid3[15][1] = 0;
      Asteroid3[15][2] = 0;
      Asteroid3[15][3] = 0;
      Asteroid3[15][4] = 0;
      Asteroid3[15][5] = 0;
      Asteroid3[15][6] = 0;
      Asteroid3[15][7] = 0;
      Asteroid3[15][8] = 0;
      Asteroid3[15][9] = 0;
      Asteroid3[15][10] = 1;

      Asteroid3[14][0] = 0;
      Asteroid3[14][1] = 0;
      Asteroid3[14][2] = 0;
      Asteroid3[14][3] = 0;
      Asteroid3[14][4] = 0;
      Asteroid3[14][5] = 0;
      Asteroid3[14][6] = 0;
      Asteroid3[14][7] = 0;
      Asteroid3[14][8] = 0;
      Asteroid3[14][9] = 0;
      Asteroid3[14][10] = 1;

      Asteroid3[13][0] = 1;
      Asteroid3[13][1] = 1;
      Asteroid3[13][2] = 0;
      Asteroid3[13][3] = 0;
      Asteroid3[13][4] = 0;
      Asteroid3[13][5] = 0;
      Asteroid3[13][6] = 0;
      Asteroid3[13][7] = 0;
      Asteroid3[13][8] = 0;
      Asteroid3[13][9] = 0;
      Asteroid3[13][10] = 6;

      Asteroid3[12][1] = 6;
      Asteroid3[12][2] = 1;
      Asteroid3[12][3] = 0;
      Asteroid3[12][4] = 0;
      Asteroid3[12][5] = 0;
      Asteroid3[12][6] = 0;
      Asteroid3[12][7] = 0;
      Asteroid3[12][8] = 0;
      Asteroid3[12][9] = 1;

      Asteroid3[11][2] = 0;
      Asteroid3[11][3] = 6;
      Asteroid3[11][4] = 1;
      Asteroid3[11][5] = 0;
      Asteroid3[11][6] = 1;
      Asteroid3[11][7] = 1;
      Asteroid3[11][8] = 1;

      Asteroid3[10][4] = 1;
      Asteroid3[10][5] = 0;
      Asteroid3[10][6] = 6;
    }
    if (iAsteroid3  > 5) {
      M5.Lcd.fillTriangle(Asteroid3Beamx0, Asteroid3Beamy0, Asteroid3Beamx1, Asteroid3Beamy1, Asteroid3Beamx2, Asteroid3Beamy2, BLACK);
      //M5.Lcd.fillRect(StartPointAsteroid3 + Asteroid3W - 1, PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap, 3, (TFTH - SpaceShipH * 2 - LevelPosPlus) - (PosAsteroid3 - Asteroid3H * 2 - Asteroid3Gap), BLACK);
      Asteroid3[19][4] = 0;
      Asteroid3[19][5] = 0;
      Asteroid3[19][6] = 0;

      Asteroid3[18][2] = 0;
      Asteroid3[18][3] = 0;
      Asteroid3[18][4] = 0;
      Asteroid3[18][5] = 0;
      Asteroid3[18][6] = 0;
      Asteroid3[18][7] = 0;
      Asteroid3[18][8] = 0;

      Asteroid3[17][1] = 0;
      Asteroid3[17][2] = 0;
      Asteroid3[17][3] = 0;
      Asteroid3[17][4] = 0;
      Asteroid3[17][5] = 0;
      Asteroid3[17][6] = 0;
      Asteroid3[17][7] = 0;
      Asteroid3[17][8] = 0;
      Asteroid3[17][9] = 0;

      Asteroid3[16][0] = 0;
      Asteroid3[16][1] = 0;
      Asteroid3[16][2] = 0;
      Asteroid3[16][3] = 0;
      Asteroid3[16][4] = 0;
      Asteroid3[16][5] = 0;
      Asteroid3[16][6] = 0;
      Asteroid3[16][7] = 0;
      Asteroid3[16][8] = 0;
      Asteroid3[16][9] = 0;
      Asteroid3[16][10] = 0;

      Asteroid3[15][0] = 0;
      Asteroid3[15][1] = 0;
      Asteroid3[15][2] = 0;
      Asteroid3[15][3] = 0;
      Asteroid3[15][4] = 0;
      Asteroid3[15][5] = 0;
      Asteroid3[15][6] = 0;
      Asteroid3[15][7] = 0;
      Asteroid3[15][8] = 0;
      Asteroid3[15][9] = 0;
      Asteroid3[15][10] = 0;

      Asteroid3[14][0] = 0;
      Asteroid3[14][1] = 0;
      Asteroid3[14][2] = 0;
      Asteroid3[14][3] = 0;
      Asteroid3[14][4] = 0;
      Asteroid3[14][5] = 0;
      Asteroid3[14][6] = 0;
      Asteroid3[14][7] = 0;
      Asteroid3[14][8] = 0;
      Asteroid3[14][9] = 0;
      Asteroid3[14][10] = 0;

      Asteroid3[13][0] = 0;
      Asteroid3[13][1] = 0;
      Asteroid3[13][2] = 0;
      Asteroid3[13][3] = 0;
      Asteroid3[13][4] = 0;
      Asteroid3[13][5] = 0;
      Asteroid3[13][6] = 0;
      Asteroid3[13][7] = 0;
      Asteroid3[13][8] = 0;
      Asteroid3[13][9] = 0;
      Asteroid3[13][10] = 0;

      Asteroid3[12][1] = 0;
      Asteroid3[12][2] = 0;
      Asteroid3[12][3] = 0;
      Asteroid3[12][4] = 0;
      Asteroid3[12][5] = 0;
      Asteroid3[12][6] = 0;
      Asteroid3[12][7] = 0;
      Asteroid3[12][8] = 0;
      Asteroid3[12][9] = 0;

      Asteroid3[11][2] = 0;
      Asteroid3[11][3] = 0;
      Asteroid3[11][4] = 0;
      Asteroid3[11][5] = 0;
      Asteroid3[11][6] = 0;
      Asteroid3[11][7] = 0;
      Asteroid3[11][8] = 0;

      Asteroid3[10][4] = 0;
      Asteroid3[10][5] = 0;
      Asteroid3[10][6] = 0;
    }
  }


  for (i = 0; i < Asteroid3H; i = i + 1) {
    for (j = 0; j < Asteroid3W; j = j + 1) {
      if (Asteroid3[i][j] != 0) {
        if (Asteroid3[i][j] == 6) {
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, M5.Lcd.color565(238, 197, 145));
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, M5.Lcd.color565(238, 213, 183));
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, M5.Lcd.color565(238, 197, 145));
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, M5.Lcd.color565(238, 213, 183));
        }
        if (Asteroid3[i][j] == 1) {
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, RED);
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, RED);
          M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, RED);
        }
      }
      else {
        M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, BLACK);
        M5.Lcd.drawPixel(StartPointAsteroid3 + j * 2 + 1, PosAsteroid3  - Asteroid3H * 2 - Asteroid3Gap + i * 2 + 1, BLACK);

      }
    }
  }
}
