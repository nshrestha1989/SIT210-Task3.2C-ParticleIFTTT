#include <BH1750Lib.h>


BH1750Lib lightSensor;
 double timeInSunlight=0;

void setup(){
 
        lightSensor.begin(BH1750LIB_MODE_CONTINUOUSHIGHRES);

}


void loop() {
int data=lightSensor.lightLevel();
 Particle.publish("data",String(data),PRIVATE);

 int count=0;
 
 if(data<1000 ){
     Particle.publish("data","Under the Shade",PRIVATE);
    
     
 }
 else{
       Particle.publish("data","getting sunlight",PRIVATE);
         count++;
       
 }
 
 timeInSunlight=timeInSunlight+count;

  Particle.publish("Total sunlight minutes",String(timeInSunlight),PRIVATE);
  


  delay(3000);
}