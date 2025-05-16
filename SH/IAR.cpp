#include <stdint.h>

#define GPIO_PORTF_DATA_R (*((volatile uint32_t *)0x400253FC)) 

#define RED_LED_MASK    0x02   
#define YELLOW_LED_MASK 0x04   
#define GREEN_LED_MASK  0x08   

#define WHITE_LED_MASK  0x0E   
void delay(uint32_t time_ms) {
  for(int i=0;i<1000;i++){
      for(int j=0;j<1000;j++){}
    }
}

void setLights(uint8_t south, uint8_t west) {
    GPIO_PORTF_DATA_R &= ~(RED_LED_MASK | YELLOW_LED_MASK | GREEN_LED_MASK);
    GPIO_PORTF_DATA_R |= (south | west);
}

void setWalkLight(uint8_t state) {
    GPIO_PORTF_DATA_R &= ~WHITE_LED_MASK;
    GPIO_PORTF_DATA_R |= state;
}

int main() {
    setLights(RED_LED_MASK, RED_LED_MASK);  
    setWalkLight(WHITE_LED_MASK);           
    delay(5000);                            

    setWalkLight(RED_LED_MASK);
    delay(2000);
    setWalkLight(0);
    delay(2000);
    setWalkLight(RED_LED_MASK);
    delay(2000);
    setWalkLight(0);
    delay(2000);
    
    setWalkLight(RED_LED_MASK);
    delay(0);
}