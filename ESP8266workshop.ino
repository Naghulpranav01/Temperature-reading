#define BLYNK_TEMPLATE_ID "TMPL35qTgSOK9" //new
#define BLYNK_TEMPLATE_NAME "DHT IoT Sensor" // new
#define BLYNK_AUTH_TOKEN "XnauyV2Z5okxGvufAcm_EHIjRB2tiF61" // new

#include <DHT.h>

#include <BlynkSimpleEsp8266.h> // new

#define DHTPIN 4  //Data pin is connected to D2  on ESP8266 (GPIO4)

#define DHTTYPE DHT11  //Name the sensor as an object


char auth[] = "XnauyV2Z5okxGvufAcm_EHIjRB2tiF61"; // aurth tocken from blynk new
char ssid[] = "Naghul's network"; // personel hotspot name new
char pass[] = "blackbolt"; // personel hotspot password new

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test successful");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected successfuly");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h=dht.readHumidity(); // h Humidity
  float t=dht.readTemperature(); // t Temperature
  float f=dht.readTemperature(true);
  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println("Something is not working as intended");
    return; // void function
  }  // nan=not a number
  Serial.println("HUmidity: ");
  Serial.print(h);
  Serial.print("%");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("Degrees Celsius");
  Blynk.virtualWrite(V0, t); // new
  Blynk.virtualWrite(V1, h); // new
  delay(1000); // new before it was 2000

  }
