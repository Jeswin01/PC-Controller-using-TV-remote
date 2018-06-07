/***********************************************************
File name: 10_IRRemoterController.ino
Description: When you click the button on the remote control,
             you can see the serial montiol data.
Website: www.quadstore.in
***********************************************************/
#include <IRremote.h>

int RECV_PIN = 11;//The definition of the infrared receiver pin 11
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600); //Open serial 
  irrecv.enableIRIn(); // Initialization infrared receiver
} 

void loop() 
{
  if (irrecv.decode(&results)) {
   
    if(results.value==586695477)
    {
    //Serial.println("^");
    Serial.write('u');}
    else if(results.value==1510577885)
    {
    //Serial.println("V");
    Serial.write('d');
    }
    else if(results.value==2098123615)
    {//Serial.println("<");
    Serial.write('l');
    }
    else if(results.value==1281010747)
    {//Serial.println(">");
    Serial.write('r');
    }
    else if(results.value==101673465)
    {//Serial.println("O");
    Serial.write('c');
    }

    else if(results.value==3544932091)
    {//Serial.println("y plus");
    Serial.write('y');
    Serial.write('i');
    }
    else if(results.value==2209685721)
    {
      //Serial.println("y minus");
    Serial.write('y');
    Serial.write('d');
    }
    
    else if(results.value==2052774713)
    {//Serial.println("Volume Increase");
    Serial.write('x');
    Serial.write('i');
    }
    else if(results.value==1936932991)
    {Serial.write('x');
    Serial.write('d');
     // Serial.println("Volume Decrease");}
    }

    else if(results.value==985098965)
    {Serial.write('n');
     // Serial.println("Reset/Normal");}
    }
    else 
    {
      //Serial.println("Wrong Input");
    }
    //Serial.println(results.value);//Wrap output in hex receive code
    irrecv.resume(); //Receiving the next valu
    }
   
  }



