/*
 * Project OBD2_Electron
 * Description: Firmware for Particle Electron
 * Author: Danny Campbell, Josh Vidmar, Kale Thompson
 * Date: 7-29-18
 */

#include "CommandHandler.h"
#include "CloudHandler.h"

// Predefined settings for USART
static const long USB_SPEED = 9600;
static const long STN1110_SPEED = 38400;
static const long CONFIG = SERIAL_8N1;

static CommandHandler commandHandler;

// setup() runs once, when the device is first turned on.
void setup()
{
  /*
      Serial is communication over USB with a computer (for debugging)
      Serial1 is communication with the STN1110 device
  */
  Serial.begin(USB_SPEED);
  Serial1.blockOnOverrun(false);
  Serial1.begin(STN1110_SPEED, CONFIG);

  setupSTN1110();
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // Serial1 is the USART input from STN1110
  if(Serial1.available())
  {
    int input = Serial1.read();
    Serial.write("Serial 1 Received");
  }
}

void setupSTN1110()
{
  commandHandler.sendCommand("STBR",{"38400"});
}
