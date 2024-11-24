//------------------------라이브러리------------------------------
#include <SoftwareSerial.h>  // 블루투스 통신을 위한 라이브러리
#include <OneWire.h> // 방수 프로스센서 라이브러리
 
 
//------------------------핀 설정--------------------------------
SoftwareSerial soft(2,3);
int ph_sensor_pin1 = A0;
int ph_sensor_pin2 = A1;
const int warm_water_level_sensor_pin = A2;    // 수위센서를 A2번 핀으로 연결
const int cool_water_level_sensor_pin = A3;    // 수위센서를 A3번 핀으로 연결
int warm_water_temperature_sensor_pin1 = A4;  // 온도센서를 A4번 핀으로 연결
int cool_water_temperature_sensor_pin2 = A5;  // 온도센서를 A5번 핀으로 연결 

int warm_solenoid_pump_pin1 = 4;  //1, 3 수조에서 수조로
int warm_solenoid_pump_pin2 = 5;  //2, 4 수조에서 물탱크로
int cool_solenoid_pump_pin3 = 6;
int cool_solenoid_pump_pin4 = 7;
int watertank_solenoid_pump_pin5 = 8; // 물탱크에서 온수조로
int watertank_solenoid_pump_pin6 = 9; // 물탱크에서 냉수조로
int coolingpan = 10;
int heater = 11;

int warm_water_level_value;  // 수위 센서1의 값을 저장할 변수
int cool_water_level_value;  // 수위 센서2의 값을 저장할 변수


//Onewire(온도센서) 객체 생성
OneWire ds(warm_water_temperature_sensor_pin1);  
OneWire ds_1(cool_water_temperature_sensor_pin2); 


// 릴레이 모듈의 출력 상태 저장 변수
bool warm_solenoid_pump_state1 = false;
bool warm_solenoid_pump_state2 = false;
bool cool_solenoid_pump_state3 = false;
bool cool_solenoid_pump_state4 = false;
bool watertank_solenoid_pump_state5 = false;
bool watertank_solenoid_pump_state6 = false;



void setup() {
   
  Serial.begin(9600); // 시리얼 통신, 속도 9600
  soft.begin(9600);
  // 릴레이 모듈 초기화
  pinMode(warm_solenoid_pump_pin1, OUTPUT);
  pinMode(warm_solenoid_pump_pin2, OUTPUT);
  pinMode(cool_solenoid_pump_pin3, OUTPUT);
  pinMode(cool_solenoid_pump_pin4, OUTPUT);
  pinMode(watertank_solenoid_pump_pin5, OUTPUT);
  pinMode(watertank_solenoid_pump_pin6, OUTPUT);
  pinMode(coolingpan, OUTPUT);
  pinMode(heater, OUTPUT);

  // 모든 동작 초기상태 OFF
  digitalWrite(warm_solenoid_pump_pin1, HIGH); 
  digitalWrite(warm_solenoid_pump_pin2, HIGH); 
  digitalWrite(cool_solenoid_pump_pin3, HIGH); 
  digitalWrite(cool_solenoid_pump_pin4, HIGH); 
  digitalWrite(watertank_solenoid_pump_pin5, HIGH); 
  digitalWrite(watertank_solenoid_pump_pin6, HIGH);
  digitalWrite(coolingpan, HIGH);
  digitalWrite(heater, HIGH);

  //analogReference(EXTERNAL);  // 외부 참조 전압 사용
}


void loop()
{
  
  //****릴레이

char data;
  //릴레이
   if(soft.available()){
   data=soft.read();
    
//Serial.println(data);
}

if(data=='1'){
      digitalWrite (watertank_solenoid_pump_pin5, HIGH);
  }
    if(data=='0'){
     digitalWrite (watertank_solenoid_pump_pin5, LOW);
  }
delay(500);
  Serial.println(data);
//****릴레이끝
  //수위 측정 후 변수에 저장
  warm_water_level_value=analogRead(warm_water_level_sensor_pin); 
  //cool_water_level_value=analogRead(cool_water_level_sensor_pin);

  //온도 측정 후 변수에 저장
  float warm_water_temperature = getTemp();
  float cool_water_temperature = getTemp_1();  
  

 
 //Serial.print(warm_water_level_value);
soft.print("999");

    soft.print(",");

    soft.print(warm_water_level_value);

    soft.print(",");

    soft.print(100);

    soft.print(","); 

    soft.print(100);

    soft.print(","); 

    soft.print(100);

    soft.print(",");
    
    soft.print(100);

    soft.print(",");

    soft.print(100);

    soft.print(",");

    soft.println("888");





   //--------------------------------------------수위조절-----------------------
   //if(warm_water_level_value>150) //온수조 수위가 일정수치 이상 높아진다면
    //digitalWrite(warm_solenoid_pump_pin2,LOW); //온수조에서 물탱크로 물 공급
    //else // 온수조 수위가 높아지지 않는다면 
    //digitalWrite(warm_solenoid_pump_pin2,HIGH); // 정지

   // if(cool_water_level_value>150) //냉수조 수위가 일정수치 이상 높아진다면
    //digitalWrite(cool_solenoid_pump_pin4,LOW); //냉수조에서 물탱크로 물 공급
    //else // 냉수조 수위가 높아지지 않는다면
    //digitalWrite(cool_solenoid_pump_pin4,HIGH); // 정지

    // 접촉식 수위센서의 문제점 : 표면에 물방울이 많이 남아있다면 실제로 수위가 낮더라도 높게 판단할 가능성.
    // 따라서 수위센서에 물이 닿자마자 물이 빠지게 설계함으로서(접촉식 수위센서의 가장 하단부에만 물이 접촉하도록) 오류가능성 줄임
    // 이는 물탱크의 물이 많아지고 수조의 물이 적어질 경우의 수 발생
    // 만약 비접촉식 수위센서가 존재한다면 각 수조의 수위가 낮아질 때(접촉식 수위센서의 판단값이 0일 때) 물탱크에서 각 수조로 물 주수 : 위 기술한 문제점 해결
    // 결론 : 접촉식 수위센서는 수위가 높아짐을 판단. 비접촉식 수위센서는 수위가 낮아짐을 판단한다.

//-------------------------------------온수조----적정온도 24~26-------------------------
  //온도가 24도 미만일 때
  if(warm_water_temperature < 24) 
  {                          
   digitalWrite(heater, LOW);
  }
  else digitalWrite(heater, HIGH);

 //온도가 26 초과일 때
  if(warm_water_temperature > 26) 
  {                                          
    digitalWrite(cool_solenoid_pump_pin3, LOW);  //필수 (냉수조에서 온수조로)
    digitalWrite(watertank_solenoid_pump_pin6, LOW); // 냉수조 물 빠진만큼 공급
  }
  else
  {
    digitalWrite(cool_solenoid_pump_pin3, HIGH);
    digitalWrite(watertank_solenoid_pump_pin6, HIGH);
  }
  /*
  else if((warm_water_temperature >= 24) && (warm_water_temperature <= 26)) //적정온도일 때
  {
    digitalWrite(heater, HIGH);
    digitalWrite(cool_solenoid_pump_pin3, HIGH);
    digitalWrite(watertank_solenoid_pump_pin6, HIGH);  //모든 장치 동작 정지
  }
*/

//----------------------------냉수조----적정온도 16~18------------------
//온도가 16.5도 미만일 때
   if(cool_water_temperature <16.5)   
   {                        
    digitalWrite(warm_solenoid_pump_pin1, LOW); // 필수(온수조에서 냉수조로 물 공급)
    digitalWrite(watertank_solenoid_pump_pin5, LOW); // 온수조에 물 빠진만큼 물 공급
   }
   else
    {
    digitalWrite(warm_solenoid_pump_pin1, HIGH);
    digitalWrite(watertank_solenoid_pump_pin5, HIGH);
    }

     //온도가 18도 초과일 때
    if(cool_water_temperature > 18)         
    {
    digitalWrite(cool_solenoid_pump_pin4, LOW);  // 냉수조에서 물탱크로 주수
    digitalWrite(watertank_solenoid_pump_pin6, LOW);  // 물탱크에서 냉수조로 주수
    digitalWrite(coolingpan, LOW);  //쿨링팬 작동
    }
    else
    {
      digitalWrite(cool_solenoid_pump_pin4, HIGH);
      digitalWrite(watertank_solenoid_pump_pin6, HIGH);
      digitalWrite(coolingpan, HIGH);
    }

/*
   else if((cool_water_temperature>=16.5)&& (cool_water_temperature<=18))
  {
    digitalWrite(coolingpan, HIGH); 
    digitalWrite(warm_solenoid_pump_pin1, HIGH);
    digitalWrite(warm_solenoid_pump_pin5, HIGH);
    digitalWrite(cool_solenoid_pump_pin4, HIGH);
    digitalWrite(watertank_solenoid_pump_pin6, HIGH); //모든 장치 동작 정지
  }
  */                                           
}



  // pH 센서1 값 읽기
  //float ph_value1 = analogRead(ph_sensor_pin1);
  //float ph_voltage1 = ph_value1 * (5.0 / 1023.0);  // 아날로그 값을 전압으로 변환
  //float ph1 = 3.5 * ph_voltage1;  // 전압 값을 pH 값으로 변환
  
  // pH 센서2 값 읽기
  //float ph_value2 = analogRead(ph_sensor_pin2);
  //float ph_voltage2 = ph_value2 * (5.0 / 1023.0);
  //float ph2 = 3.5 * ph_voltage2;
 


//--------------------------------------------------함수-------------------------------------------------------
// 온도센서 변환 함수
float getTemp(){                                   //온도 측정 후 반환하는 함수
 byte data[12];
 byte addr[8];
 if ( !ds.search(addr)) {
   ds.reset_search();
   return -1000;
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }
 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }
 ds.reset();
 ds.select(addr);
 ds.write(0x44,1);                                   
 byte present = ds.reset();
 ds.select(addr);  
 ds.write(0xBE); 
 
 for (int i = 0; i < 9; i++) { 
  data[i] = ds.read();                                                          
 }
 
 ds.reset_search(); 
 byte MSB = data[1];
 byte LSB = data[0];
 float tempRead = ((MSB << 8) | LSB); 
 float TemperatureSum = tempRead / 16; 
 return TemperatureSum;                                                                    
}
float getTemp_1(){                                   //온도 측정 후 반환하는 함수
 byte data[12];
 byte addr[8];
 if ( !ds_1.search(addr)) {
   ds_1.reset_search();
   return -1000;
 }
 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }
 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }
 ds_1.reset();
 ds_1.select(addr);
 ds_1.write(0x44,1);                                   
 byte present = ds_1.reset();
 ds_1.select(addr);  
 ds_1.write(0xBE); 
 
 for (int i = 0; i < 9; i++) { 
  data[i] = ds_1.read();                                                          
 }
 
 ds_1.reset_search(); 
 byte MSB = data[1];
 byte LSB = data[0];
 float tempRead = ((MSB << 8) | LSB); 
 float TemperatureSum = tempRead / 16; 
 return TemperatureSum;                                                                    
}
