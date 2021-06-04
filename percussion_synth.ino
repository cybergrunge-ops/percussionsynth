int mode1 = 13;
int mode2 = 12;
int mode3 = 11;
int mode4 = 10;
int mode5 = 9;
int mode6 = 7;
int mode7 = 6;
int mode8 = 5;
int mode9 = 4;
int mode0 = 3;


int out = 2; 
int z; int r=1; int i=1; 

int knob1; 
int knob2; 
int knob3; 
int knob4; 
int knob5;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(mode0, INPUT_PULLUP);  pinMode(mode1, INPUT_PULLUP);
  pinMode(mode2, INPUT_PULLUP);  pinMode(mode3, INPUT_PULLUP);
  pinMode(mode4, INPUT_PULLUP);  pinMode(mode5, INPUT_PULLUP);
  pinMode(mode6, INPUT_PULLUP);  pinMode(mode7, INPUT_PULLUP);
  pinMode(mode8, INPUT_PULLUP);  pinMode(mode9, INPUT_PULLUP);
  pinMode(out, OUTPUT);
}

int halfduty(int a){digitalWrite(out, HIGH); delayMicroseconds(a);digitalWrite(out, LOW);  delayMicroseconds(a);}

void loop() {
  
  knob1 = analogRead(A0);
  knob2 = analogRead(A1);
  knob3 = analogRead(A2);
  knob4 = analogRead(A3);
  knob5 = analogRead(A4);

if(digitalRead(mode0)==LOW){r++;halfduty(20+r*90);if(digitalRead(mode0)==HIGH){r=1;}}
if(digitalRead(mode1)==LOW){halfduty(random(10+knob1/2));}
if(digitalRead(mode2)==LOW){z++;if(z<50){halfduty(2+knob4/2);} if(z>100){halfduty(1+knob4/3);} if(z>240){z=0;}}
if(digitalRead(mode3)==LOW){i++;halfduty(random(40)+i*(random(5)+5));if(digitalRead(mode3)==HIGH){i=1;}}
if(digitalRead(mode4)==LOW){halfduty(50+knob4*15);}
if(digitalRead(mode5)==LOW){halfduty(random(100+knob1));}
if(digitalRead(mode6)==LOW){halfduty(100+knob5);}
if(digitalRead(mode7)==LOW){i++;halfduty(50+i*45);if(digitalRead(mode3)==HIGH){i=1;}}
if(digitalRead(mode8)==LOW){halfduty(5+knob3*15);}
//if(digitalRead(mode9)==LOW){r++;halfduty(320+(sin(r/45*r)*knob1/3));if(digitalRead(mode9)==HIGH){r=1;}}
if(digitalRead(mode9)==LOW){r++;halfduty(knob1/2+(sin(r/45*r)*200));if(digitalRead(mode9)==HIGH){r=1;}}

  
}
