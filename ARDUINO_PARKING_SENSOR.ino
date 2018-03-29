
int a,b,c,d;
void setup() 
{
Serial.begin(9600);
pinMode(6,OUTPUT);
//pinMode(7,OUTPUT);
//pinMode(8,OUTPUT);
//pinMode(9,OUTPUT);
}

void loop() {
 digitalWrite(6,HIGH);    // Turning ON LED
 //digitalWrite(7,HIGH);    // Turning ON LED
 //digitalWrite(8,HIGH);    // Turning ON LED
 //digitalWrite(9,HIGH);    // Turning ON LED
 //delayMicroseconds(500);  //wait
 a=analogRead(A3);        //take reading from photodiode(pin A3) :noise+signal
 
 digitalWrite(6,LOW);     //turn Off LED
 //digitalWrite(7,LOW);     //turn Off LED
 //digitalWrite(8,LOW);     //turn Off LED
 //digitalWrite(9,LOW);     //turn Off LED
 //delayMicroseconds(500);  //wait
 b=analogRead(A3);        // again take reading from photodiode :noise
c=a-b;                    //taking differnce:[ (noise+signal)-(noise)] just signal
d =-c;
//Serial.print(a);         //noise+signal
//Serial.print("\t");
//Serial.print(b);         //noise
//Serial.print("\t");
if(d>100)
d=1; 
else d=0; 
Serial.println(d);         // denoised signal
// count = distance1 + distance2 + distance3 + distance4;;
// freeSlot = 4 - count;

}
