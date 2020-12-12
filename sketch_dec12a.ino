#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[ ] = "h12OT_OiBvAId-AAbbNtj_wCk1zhdDil";
char ssid[ ] = "Freebox-AAD1EE";
char pass[ ] = "carente2-fabellis@-exarmata6!-deglutiat#8";

WidgetLED led1(V1);
BlynkTimer timer;

void blinkLedWidget() 
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}
