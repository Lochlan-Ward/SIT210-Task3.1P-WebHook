// import library for DHT22 sensor
#include <Adafruit_DHT.h>

// *** I used a sketch by the user below for basic DHT22 funcionatlity and modified it to do what was required.  
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22		// DHT 22 (AM2302)

int led = D7;  // The on-board LED

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // some serial monitoring I used to set up and test the sensor with Argon, from the DHT file by user ladyada
	Serial.begin(9600); 
	Serial.println("DHT22 test!");
	
	pinMode(led, OUTPUT);

	dht.begin();
}

void loop() {

	digitalWrite(led, HIGH);   // Turn ON the LED
    //get temperature in Celcius
	float temp = dht.getTempCelcius();

    // send data
    Particle.publish("temp", String::format("%.1f", temp));

    // this is printed to serial monitor to check functionality
	Serial.print("Temp: "); 
	Serial.print(temp);
	Serial.print("*C ");
	Serial.println(Time.timeStr());
	
	digitalWrite(led, LOW);  // turn off LED after data sent
	
	delay(30000);  // wait 30 seconds before sending another reading
}

