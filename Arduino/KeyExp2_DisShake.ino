//通过延时来消除按键抖动
#define BUTTON   6           //按键接数字通道6
int val = 0;//变量val 存储按钮的状态
int old_val = 0;//暂存val变量的上一个时间状态
int state = 0;//打印到串口的数据，按钮每被按下一次，state自增1
void setup() {
  pinMode(BUTTON, INPUT);//设置输入
  Serial.begin(9600);//初始化串口
}
void loop() {
  val = digitalRead(BUTTON);//读取输入数值并且存储
  if ((val == HIGH) && (old_val == LOW)) //本次读入的值为高电平，上次为低电平，则表明有按键按下。
  {
    printState();//调用函数
    delay(10);//延时；
  }
  old_val = val; //将当前的值保存
}

void printState()
{
  state++;
  Serial.println(state);
}
