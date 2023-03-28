#include "mbed.h"

PwmOut PWM1(D6);
AnalogIn Ain(A0);
AnalogIn Ain2(A2);
Thread thread1;

int sample = 1000;
int i;

float ADCdata[1000];


void PWM_generator() {
    while (1)
  {
    PWM1.period_ms(5);
    PWM1.pulsewidth_us(double(Ain)*3.3*5000);
    //printf("%f\n\r", PWM1.read());
    ThisThread::sleep_for(50ms);
  }
}

int main()
{
  thread1.start(PWM_generator);
  for (i = 0; i < sample; i++)
    {
        ADCdata[i] = Ain2;
        ThisThread::sleep_for(1ms);
    }
  for (i = 0; i < sample; i++)
    {
        printf("%f\n", ADCdata[i]);
        ThisThread::sleep_for(1ms);
    }
  
}