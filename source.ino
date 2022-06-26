#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>  
SoftwareSerial mySerial(10, 11); //SIM800L Tx & Rx kết nối Arduino #10 & #11
int flame_sensor_digital = 2; 
int red_pin = 6;                    // kết nối với đèn màu đỏ
int green_pin = 4;                  // kết nối với đèn màu xanh
int buzzer_pin = 12;                // kết nối với còi hú
Servo myservo;                      // tạo đối tượng myservo

void sendMessage(){
  Serial.println("Sending SMS..."); 
  delay(1000);
  mySerial.println("AT"); // sau khi kiểm tra bắt tay thành công -> ok
  delay(1000);
  mySerial.println("AT+CMGF=1"); // định cấu hình chế độ TEXT
  delay(1000);
  mySerial.println("AT+CMGS=\"+84905012305\"");
  delay(1000);
  mySerial.print("Fire Warning!"); // nội dung văn bản
  mySerial.write(26);
}
void callPhone(){
  Serial.println("Calling..."); 
  mySerial.println("AT"); // sau khi kiểm tra bắt tay thành công -> ok
  
  mySerial.println("ATD+ +84905012305;");
  delay(10000); // đợi 10 giây...
  mySerial.println("ATH"); //hang up 
}

void fireNotice(){
  tone(buzzer_pin, 5000);                             // âm thanh của còi hú ở mức 5000Hz
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, LOW);
  myservo.write(0);                                   // thiết lập góc quay để mở cửa
  Serial.println("Co chay");
  delay(1000);
  callPhone();                                        // gọi điện thoại
  delay(1000);
  sendMessage();
}
void setup()
{
  // bắt đầu giao tiếp nối tiếp với Arduino và Arduino IDE (Serial Monitor)
  myservo.attach(9);              // kết nối với servo
  Serial.begin(9600);
  mySerial.begin(9600);
  myservo.write(120);             // góc quay của servo ở vị trí ban đầu (cửa đang đóng)
  // bắt đầu giao tiếp nối tiếp với Arduino và SIM800L
  pinMode(buzzer_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(flame_sensor_digital ,  INPUT); 
  attachInterrupt(0,fireNotice, LOW);
}

void loop()
{
  int digitalValue = digitalRead(flame_sensor_digital);   // đọc giá trị của Flame Sensor
  Serial.println(digitalValue);
  noTone(buzzer_pin);
  digitalWrite(red_pin, LOW);
  digitalWrite(green_pin, HIGH);
  Serial.println("Khong co chay");
  delay(1000);
}
