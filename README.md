
# ESP32기반 3상유도전동기 진동 감지 및 원격 전송 프로그램, 진동 데이터 Predictive Maintenance 알고리즘 개발


### 배경
참여기업 ㈜페스코에서 현재 개발중인 스마트팩토리 교육용 장비에 큰 하드웨어 변경없이 Machine Learning과 관련된 교육용 컨텐츠를 개발하고자 하며 이의 개발은 

1) 3상 유도전동기에 3축 가속도 센서(IMU 센서)를 장착하고 원격의 PC로 wifi를 이용하여 측정값을 전송하는 ESP32 기반의 IoT 단말 및 전송 프로그램 개발
2) ESP32로부터 wifi를 통해 전송된 진동값을 수신하고 이를 데이터 베이스에 저장한 후, 다양한 predictive maintenance를 구현하는 알고리즘 개발
로 크게 2분야로 구성됩니다. 


이 프로젝트는 3상 유도전동기에 3축 가속도 센서(IMU 센서)를 장착하고 ESP32를 사용하여 측정된 가속도 값을 원격으로 전송하는 IoT 시스템을 구축하는 것을 목표로 합니다. 또한, 원격에서 수신한 진동값을 데이터베이스에 저장하고 다양한 predictive maintenance 알고리즘을 개발하여 스마트팩토리 교육용 장비에 적용하는 것이 포함되어 있습니다.

- ESP32 본 과제에서 사용하고자 하는 보드의 외형은 다음과 같음

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/0cbef8a3-8c6c-414d-9ded-4357ca49d1fb)

=> ESP32 I2C 보드에는 통신을 위한 전용 포트가 상기와 같이 제공됨
 (GPIO22 : I2C SCL # I2C 통신에 사용되는 클럭
 GPIO21: I2C SDA # I2C data ) 통신에 클럭과 동기되어 전송되는 포트
=> IMU SCL, SDA GND VCC ESP32 센서의 및 및 를 보드에 연결해야 함

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/fa762047-3bd4-4d76-a6b5-f15b5de0594f)


프로젝트의 주요 단계는 다음과 같습니다

### 하드웨어 설정

3상 유도전동기에 3축 가속도 센서(IMU 9250)를 장착하고, 이를 ESP32에 연결합니다. 해당 연결은 I2C 통신을 사용하여 이루어집니다.

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/73221789-c255-438d-8741-fe67dd4426f7)


### 센서 데이터 수집 및 전송 


ESP32는 IMU 센서로부터 가속도 값을 측정하고, 이 값을 Wi-Fi를 통해 원격의 Web server로 전송합니다. 이때, 측정된 데이터는 JSON 형식으로 전송됩니다.



### 서버 측 데이터 수신 및 저장

Raspberry Pi에서 동작하는 서버는 ESP32로부터 전송된 가속도 데이터를 수신하고, 이를 데이터베이스에 저장합니다. 여기서는 CSV 파일 형식을 사용하여 저장합니다.

## 과정

## imu(mpu9250)센서 데이터 작동 확인
- IMU센서(MPU9250)센서를 ESP32보드에 장착하고 하기의 Arduino sketch 수행시킴 
- esp32_S_with_mpu9250.ino -> mpu9250 센서로부터 가속도 값의 측정이 잘 수행됨을 확인
- 
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/5801c183-1125-4c47-97d2-5cc634428509)

## HTTP통신

- Wi-Fi 서버 접속 주소를 자신의 라즈베리파이의 IP로 변경하여 두 장치 간의 통신을 설정
- ESP32 arduino 스케치 (esp32_imu_mpu9250_to_winpc_7_09.ino)에서 wifi 서버 접속 주소를 자신의 라파 ip로 변경

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/abd5acfb-162d-4dc2-8e40-4563f2b62ff4)


### ESP32에 장착된 imu 센서로부터의 값을 측정하고 이를 원격의 rapa로 json파일 형태로 전송하고 csv 파일로 저장되는 동작 확인.


https://github.com/yn0212/projectlab-2022-2/assets/105347300/84ed421d-b336-4828-93b7-2f57fe82bff4




###  3상 유도전동기에 imu센서를 장착하고, 측정된 가속도 값을 원격의 PC로 wifi 무선 통신을 이용하여 측정값을 전송하는 esp32기반의 iot단말 및 전송 프로그램. 

https://github.com/yn0212/projectlab-2022-2/assets/105347300/00476a3d-ea80-4193-a906-5724cf16241d

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/589ebeb0-ab43-4345-a7e0-65c3fdced75d)

클라이언트가 서버에게 어떤 동작이나 데이터를 원하는지를 명시적으로 전달

### Predictive Maintenance 알고리즘 개발

데이터베이스에 저장된 진동값을 기반으로 다양한 predictive maintenance 알고리즘을 개발합니다. 
normal 데이터는 정상으로 약한 진동값이고 abnormal 데이터는 비정상으로 강한 진동값을 주었을 경우입니다.

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/2a5d3fec-eac9-40b7-b928-6d0a896e7eba)

고속 푸리에 변환(Fast Fourier Transform, FFT)은 주로 시간 도메인에서 주파수 도메인으로 신호를 변환하는 데 사용되며, 주파수 변화를 분석하는 데 유용합니다.

- 진동 분석(Vibration Analysis): 기계의 작동 상태를 진동 신호에서 판단할 때 FFT를 사용하여 주파수 성분을 분석할 수 있습니다. 특정 주파수 성분의 변화가 기계의 이상을 나타낼 수 있습니다.

- 주기성 신호 탐지: FFT를 사용하여 주기성 신호의 주파수를 분석하고 주기성 변화를 감지할 수 있습니다. 이는 예를 들어 펌프나 모터와 같은 회전 기계의 상태를 감지하는 데 유용할 수 있습니다.

- 스펙트럼 분석(Spectrum Analysis): FFT는 시계열 데이터를 주파수 영역으로 변환하므로, 시계열 데이터에서 발생하는 주파수 성분을 분석하는 데 사용될 수 있습니다.

--> 주파수 도메인에서의 변화를 분석하여 기계의 작동 상태를 파악하거나, 예측 유지보수에 활용가능!


### 고속 푸리에 변환

FFT(고속 푸리에 변환)를 사용하여 데이터를 시각화하고, 정상과 비정상 데이터를 구분하는 그래프를 생성합니다.
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/02df8156-a0bf-4f60-b8de-cb7c88a09e51)

### 모니터링
esp32보드와 raspberry pi 보드간의 http 프로토콜에서 제공하는 get/post method를 사용하여 node-red확인
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/ccf07acc-29f9-45b7-a5fc-a497eff44c8a)
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/f0d59eca-95bf-4c78-bf7a-a9d92e1b3df4)



### 최종 결과:

최종적으로 정상과 비정상 데이터를 비교하여 동영상으로 결과를 시연합니다.
프로젝트의 마무리는 predictive maintenance 알고리즘을 통해 유지보수가 필요한 상태를 감지하고, 시스템의 안정성을 높이는 데에 중점을 둔 것 입니다. 또한, 교육용 장비에 적용되어 스마트팩토리의 학습과 이해를 촉진하는 목적이 있습니다.

https://github.com/yn0212/projectlab-2022-2/assets/105347300/db709de1-ff90-48e7-9774-c89d14f1c0dc

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/a372bb6c-7548-40b4-83c8-39286c746051)



