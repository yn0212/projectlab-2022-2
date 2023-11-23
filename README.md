
# ESP32기반 3상유도전동기 진동 감지 및 원격 Predictive Maintenance 시스템

이 프로젝트는 3상 유도전동기에 3축 가속도 센서(IMU 센서)를 장착하고 ESP32를 사용하여 측정된 가속도 값을 원격으로 전송하는 IoT 시스템을 구축하는 것을 목표로 합니다. 또한, 원격에서 수신한 진동값을 데이터베이스에 저장하고 다양한 predictive maintenance 알고리즘을 개발하여 스마트팩토리 교육용 장비에 적용하는 것이 포함되어 있습니다.

프로젝트의 주요 단계는 다음과 같습니다

### 하드웨어 설정

3상 유도전동기에 3축 가속도 센서(IMU 9250)를 장착하고, 이를 ESP32에 연결합니다. 해당 연결은 I2C 통신을 사용하여 이루어집니다.

![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/73221789-c255-438d-8741-fe67dd4426f7)


### 센서 데이터 수집 및 전송

ESP32는 IMU 센서로부터 가속도 값을 측정하고, 이 값을 Wi-Fi를 통해 원격의 Web server로 전송합니다. 이때, 측정된 데이터는 JSON 형식으로 전송됩니다.



### 서버 측 데이터 수신 및 저장

Raspberry Pi에서 동작하는 서버는 ESP32로부터 전송된 가속도 데이터를 수신하고, 이를 데이터베이스에 저장합니다. 여기서는 CSV 파일 형식을 사용하여 저장합니다.

#### ESP32에 장착된 imu 센서로부터의 진동값을 측정하고 이를 원격의 rapa로 전송하는 동작영상


https://github.com/yn0212/projectlab-2022-2/assets/105347300/84ed421d-b336-4828-93b7-2f57fe82bff4


####  esp32에서 json 파일을 라파로 전송하고 csv 파일로 저장되는 동작화면

https://github.com/yn0212/projectlab-2022-2/assets/105347300/00476a3d-ea80-4193-a906-5724cf16241d



### Predictive Maintenance 알고리즘 개발

데이터베이스에 저장된 진동값을 기반으로 다양한 predictive maintenance 알고리즘을 개발합니다. 
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/748baf56-f16a-46df-beb7-2992b9dabd31)


### 데이터 시각화

FFT(고속 푸리에 변환)를 사용하여 데이터를 시각화하고, 정상과 비정상 데이터를 구분하는 그래프를 생성합니다.
![image](https://github.com/yn0212/projectlab-2022-2/assets/105347300/02df8156-a0bf-4f60-b8de-cb7c88a09e51)

### 최종 결과:

최종적으로 정상과 비정상 데이터를 비교하여 동영상으로 결과를 시연합니다.
프로젝트의 마무리는 predictive maintenance 알고리즘을 통해 유지보수가 필요한 상태를 감지하고, 시스템의 안정성을 높이는 데에 중점을 둔 것 입니다. 또한, 교육용 장비에 적용되어 스마트팩토리의 학습과 이해를 촉진하는 목적이 있습니다.

https://github.com/yn0212/projectlab-2022-2/assets/105347300/db709de1-ff90-48e7-9774-c89d14f1c0dc


