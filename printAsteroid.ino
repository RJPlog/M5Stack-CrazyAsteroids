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
