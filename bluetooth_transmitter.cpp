#define joyX A0
#define joyY A1

const int MAX_VAL = 1023;

float rawLeft = 0;
float rawRight = 0;
float RawLeft = 0;
float RawRight = 0;


int x, y;
void setup() {
  
  Serial.begin(9600); //Default communication rate of HC-05 bluetooth module
}

void loop() {
  x = analogRead(joyX);
  y = map(analogRead(joyY), 0, 1023, 1023, 0);

  x = map(x, 0, 1023, 100, -100);
  y = map(y, 0, 1023, 100, -100);

  float z = sqrt(x*x + y*y);
  float rad = acos(abs(x) / z);

  if (isnan(rad)){
    rad = 0;
  }

  float angle = rad * 180 / PI;

  float turnCoeff = -1 + (angle/90) * 2;
  float turn = turnCoeff * abs(abs(y)-abs(x));
  turn = round(turn * 100) / 100;

  float mov = max(abs(y), abs(x));

  if ((x>=0 && y>=0) || (x<0 && y<0)){
    rawLeft = mov;
    rawRight = turn;
  } else {
    rawRight = mov;
    rawLeft = turn;
  }

  if (y > 0){
    rawLeft = - rawLeft;
    rawRight = - rawRight;
  }

  RawLeft = rawLeft;
  RawRight = rawRight;

  //float RawLeftOut = map(RawLeft, -100, 100, 0, 255);

  Serial.write(RawLeft+","+RawRight);

}
