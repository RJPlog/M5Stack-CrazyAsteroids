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

