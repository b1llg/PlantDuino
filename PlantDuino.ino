// sensor definition
int s0 = A0; // Sensor #0


// limit definition
int rs[1]; // Initialize array of sensor result


// misc definition
int MAX_PLOT = 1000;
int MIN_PLOT = 700;

int DRY = 895;

int UPPER_LIMIT = 890;  
int LOWER_LIMIT = 850;

int WET = 830;

void setup()
{
  pinMode(s0, OUTPUT);            // Set pin mode
  Serial.begin(9600);             // set baud rate
}

void loop()
{

rs[0] = analogRead(s0);

Serial.print(MIN_PLOT); // To freeze the lower limit
Serial.print(" ");
Serial.print(MAX_PLOT); // To freeze the upper limit
Serial.print(" ");

if (rs[0] >= DRY)
{
  Serial.print("Moisture sensor is reading DRY condition  ");
}
else if (rs[0] < DRY && rs[0] >= UPPER_LIMIT)
{
  Serial.print("Add Water  ");
}
else if (rs[0] < UPPER_LIMIT && rs[0] >= LOWER_LIMIT)
{
  Serial.print("Ideal Condition  ");
}
else if (rs[0] < LOWER_LIMIT && rs[0] >= WET)
{
  Serial.print("Too much water  ");
}
else if (rs[0] < WET)
{
  Serial.print("Moisture sensor is reading WET condition  ");
}

Serial.println(rs[0]); 

delay(1000);
}