//通过本实验观察按键抖动现象：打开软件中的”串口监视器“，发现按键按下时，数值会出现跳跃现象，不只是增1。思考原因。
#define BUTTON  6      //按键接在数字通道6上。
int val = 0;//变量val 存储按钮的状态
int old_val = 0;//暂存val变量的上一个时间状态
int state = 0;//打印到串口的数据，按钮每被按下一次，state自增1
void setup() {
  pinMode(BUTTON, INPUT);//设置输入模式
  Serial.begin(9600);//串口初始化。
}
void loop() {
  val = digitalRead(BUTTON);//读取输入数值并且存储
  if ((val == HIGH) && (old_val == LOW)) //若本次端口读的值为高电平，上次为低电平，则说明有键按下。
  {
    printState();
  }
  old_val = val; //val现在是旧的了，让我们暂存一下
}
void printState()
{
  state++;                    //变量的值加1；
  Serial.println(state);      //值输出到上位机。
}
