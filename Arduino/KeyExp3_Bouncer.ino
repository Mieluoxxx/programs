//通过调用库文件函数来消抖
#include "Bounce2.h"
#define BUTTON 6//按键接到数字通道6
Bounce debouncer = Bounce();//实例化一个抖动对象
int val = 0; //变量val存储按钮的状态,因为是下拉电阻，按键未按下时，默认是LOW(即0)
int old_val = 0; //存储val变量的上一个时间的状态值
int state = 0; //打印到串口的数据，按钮每被按下一次，state自增1
void setup() {
  pinMode(BUTTON, INPUT); //模式设置
  debouncer.attach(BUTTON);//将抖动对象绑定到按钮针脚
  debouncer.interval(5);//间隔是5ms
  Serial.begin(9600);//用于串口输出
}
void loop() {
  debouncer.update();//更新抖动对象
  val = debouncer.read(); //读取输入数值并且存储
  if ((val == HIGH) && (old_val == LOW)) //本次按键的值为高，但上次为低。说明现在有按键按下。
  {
    printState();
  }
  old_val = val; //val现在是旧的了，暂存一下
}
void printState()
{
  state++;
  Serial.println(state);
}
