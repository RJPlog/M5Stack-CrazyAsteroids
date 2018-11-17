// print start screen
// wait for pushing "B" to start game

void startEntrySection() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(M5.Lcd.color565(255, 131, 250));
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 80);
  M5.Lcd.println(" RJPlog's ");
  M5.Lcd.println(" Crazy Asteroids");
  M5.Lcd.setTextColor(M5.Lcd.color565(139, 0, 139));
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(100, 210);
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
