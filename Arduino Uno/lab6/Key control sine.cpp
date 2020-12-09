//1Hz正弦波发生器
//采用DDS方法产生波形：将一个完整正弦波离散化为512个数据，存储为数组，以一个固定频率顺序读取数组的值，即可复制波形，通过改变读取的步进量，改变输出波形频率
//采用PWM进行模拟输出，约2ms的模拟转换时间，当采用频率步长为1时，一个完整波形需要512个数据，刚好是1s左右，即1Hz

#include "waveData.h"

unsigned int signalOutPWM = 6;                  //信号输出端口
unsigned int delaytime = 1950;                  //每个数据由970Hz的PWM波形滤波产生，约1.9ms延迟+其他语句延迟 约等于 2ms，足以产生两个完整PWM波形
unsigned int wholePeriodNum = 512;
unsigned int i, freqStep;

unsigned int freKeyPort=1;//频率调制
unsigned int ampKeyPort=2;//幅度调制
unsigned int ampGain=0;//幅度增益



void setup() {  
  pinMode(signalOutPWM, OUTPUT);
  pinMode(freKeyPort,INPUT_PULLUP);
  pinMode(ampKeyPort,INPUT_PULLUP);
  freqStep = 0;          
}

void loop() {
  if (digitalRead(freKeyPort)==LOW){
      freqStep+=1;
      delay(300);
  }
  if (digitalRead(ampKeyPort)==LOW){
      ampGain+=1;
      delay(300);
  }
  freqStep=freqStep%20+1;
  ampGain=ampGain%20+1;

  i %= wholePeriodNum;
  analogWrite(signalOutPWM, sinData[i]*ampGain/4);
  
  i += freqStep;
  delayMicroseconds(delaytime);

}