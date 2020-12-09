#include "TM1637.h"     //添加数码管模块头文件（预先把TM1637库函数文件拷贝进arduino安装目录下的libraries文件夹里）
#include "waveData.h"


#define CLK 13        //数码管模块接口
#define DIO 12          //数码管模块接口
TM1637 tm1637(CLK,DIO); //定义数码管对象



unsigned int signalOutPWM = 6;                  //信号输出端口
unsigned int delaytime = 1950;                  //每个数据由970Hz的PWM波形滤波产生，约1.9ms延迟+其他语句延迟 约等于 2ms，足以产生两个完整PWM波形
unsigned int wholePeriodNum = 512;
unsigned int i, freqStep;

unsigned int freKeyPort=1;//频率调制
unsigned int ampKeyPort=2;//幅度调制
unsigned int ampGain;//幅度增益


int8_t displayData[] = {0x01, 0x00, 0x00, 0x00};  //四个数码管待显示的数据




void setup() {  
  tm1637.set();       //数码管对象设置
  tm1637.init();      //数码管对象初始化
  pinMode(signalOutPWM, OUTPUT);
  pinMode(freKeyPort,INPUT_PULLUP);
  pinMode(ampKeyPort,INPUT_PULLUP);
  freqStep = 1;        
  ampGain=1;  
  tm1637.display(displayData);
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
  if(freqStep>20)freqStep=1;
  if(ampGain>4)ampGain=1;

  displayData[1]=ampGain;
  displayData[2]=freqStep/10;
  displayData[3]=freqStep%10;
  tm1637.display(displayData);

  i %= wholePeriodNum;
  analogWrite(signalOutPWM, sinData[i]*ampGain/4);
  
  i += freqStep;
  delayMicroseconds(delaytime);

}