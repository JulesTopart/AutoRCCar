int wheelPin[4] = {5,6,7,8}; //PWMR, PWML,DIRR,DIRL
const bool invR = false, invL = false;
const int vMin = 80, vMax = 255;
// duration for output
int time = 50;
// initial command
int command = 0;

void setup() {
  for(int i(0); i < 4; i++) pinMode(wheelPin[i], OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  //receive command
  if (Serial.available() > 0){
    command = Serial.read();
  }
  else{
    reset();
  }
   send_command(command,time);
}

void right(int time){
 digitalWrite(wheelPin[2], HIGH);
 digitalWrite(wheelPin[3], LOW);
 analogWrite(wheelPin[0], vMin);
 analogWrite(wheelPin[1], vMin);
  delay(time);
}

void left(int time){
 digitalWrite(wheelPin[2], LOW);
 digitalWrite(wheelPin[3], HIGH);
 
 analogWrite(wheelPin[0], vMin);
 analogWrite(wheelPin[1], vMin);
  delay(time);
}

void forward(int time){
 digitalWrite(wheelPin[2], HIGH);
 digitalWrite(wheelPin[3], HIGH);
 analogWrite(wheelPin[0], vMax);
 analogWrite(wheelPin[1], vMax);
 delay(time);
}

void reverse(int time){

  digitalWrite(wheelPin[2], LOW);
 digitalWrite(wheelPin[3], LOW);
 analogWrite(wheelPin[0], vMin );
 analogWrite(wheelPin[1], vMin);
 delay(time);
}

void forward_right(int time){
 digitalWrite(wheelPin[2], HIGH);
 digitalWrite(wheelPin[3], HIGH);
 analogWrite(wheelPin[0], vMax);
 analogWrite(wheelPin[1], vMin);
  delay(time);
}

void reverse_right(int time){

  digitalWrite(wheelPin[2], LOW);
 digitalWrite(wheelPin[3], LOW);
 analogWrite(wheelPin[0], vMax);
 analogWrite(wheelPin[1], vMin);
 delay(time);
}

void forward_left(int time){

  digitalWrite(wheelPin[2], HIGH);
 digitalWrite(wheelPin[3], HIGH);
 analogWrite(wheelPin[0], vMin);
 analogWrite(wheelPin[1], vMax);
  delay(time);
}

void reverse_left(int time){

  digitalWrite(wheelPin[2], LOW);
 digitalWrite(wheelPin[3], LOW);
 analogWrite(wheelPin[0], vMin);
 analogWrite(wheelPin[1], vMax);
 delay(time);
}

void reset(){
 digitalWrite(wheelPin[2], HIGH);
 digitalWrite(wheelPin[3], HIGH);
 analogWrite(wheelPin[0], 0);
 analogWrite(wheelPin[1], 0);
}

void send_command(int command, int time){
  switch (command){

     //reset command
     case 0: reset(); break;

     // single command
     case 1: forward(time); break;
     case 2: reverse(time); break;
     case 3: right(time); break;
     case 4: left(time); break;

     //combination command
     case 6: forward_right(time); break;
     case 7: forward_left(time); break;
     case 8: reverse_right(time); break;
     case 9: reverse_left(time); break;

     default: Serial.print("Invalid Command\n");
    }
}
