// game lost
// wait for pushing "B" to restart game

void startExitSection () {
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
}

