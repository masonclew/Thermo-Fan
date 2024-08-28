#include <Wire.h>
#include <Servo.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//Initializes Temperature Variable
float Temp = 72;
Servo ESC;
int Speed; 

//Runs a startup cycle to initialize the motor
void setup() {
  Serial.begin(9600);
  mlx.begin();
  ESC.attach(9,1000,2000);
  ESC.write(0);
  delay(1000);
  ESC.write(90);
  delay(2000);
  ESC.write(0);
  delay(1000);
}

void loop() {
  //reads temp from infared sensor
  Temp = mlx.readObjectTempF();
  Speed = Temp;
  //maps the speed metrics for the motor
  Speed = map(Speed,40,100,0,180);
  // Adjusts the speed based on the temperature
  ESC.write(Speed);
  delay(2000);

     //prints out temp
  Serial.print("Object(F) = ");
  Serial.println(Temp);
  delay(1000);

  
}