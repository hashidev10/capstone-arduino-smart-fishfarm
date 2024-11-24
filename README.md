### 포트폴리오

### 에너지절감, 스마트 양식장의 환경제어와 어플리케이션 개발

팀명 S팜은 나야, 들이 될 수 없어
조원 김동석, 이재훈, 박성민, 박은서, 이지현, 정동민
지도교수 정지원 교수님

## 개요

• 고령화 및 어업종사자 수의 감소로 인하여 비교적은 적은 인원으로도 관리가 가능한 스마트 양식장이 필요
<br/>
• 현재 양식업은 수온을 조절하는 과정에서 수온 조절이 효율적이지
못하게 에너지가 낭비되는 문제가 존재
<br/>
• 스마트 양식을 통해 물고기가 살기에 최적의 환경을 유지하고, 양식에 필요한 정보를 사용자가  <br/>  무선으로 실시간으로 확인함으로써 양식생산량의 증대를 기대할 수 있음.
<br/>
• 따라서 현재 양식업자가 가지는 인력 및 자본 부족, 에너지 낭비와 같은 문제점을 위와 같은 에너지 절감 스마트 양식장을 통해 해결하고자 함.
<br/>

![image](https://github.com/user-attachments/assets/58d0e1a1-8316-49ad-82ba-a9ef5ed1745e)

# 아두이노를 사용하여 환경을 통제 및 측정

1. 각 수조의 온도를 실시간으로 측정, 온도가 서로 대비되는 각 수조 간 주수를 통해 적정 온도를 유지.
2. 각 수조에 수위 센서를 통해 적정 수위를 벗어나는 순간 물탱크를 활용하여 적정 수위를 유지.
3. 스마트폰 어플리케이션을 통해 실시간으로 관측 및 제어.

## 블록도

![image](https://github.com/user-attachments/assets/140403c4-7f5a-40a6-a91b-9a02f1c48024)


## 아두이노와 스마트폰 어플리케이션의 연동사진
![image](https://github.com/user-attachments/assets/cc4e903d-2b7e-4989-9511-481ddf1075a5)

- 아두이노와 스마트폰 어플리케이션 간 블루투스 통신으로 사용자가 필요한 정보를 정상적으로 수신

## 실물동작도
  
![image](https://github.com/user-attachments/assets/60c7bdfe-8443-4a11-b9d7-9e8cb92ff9cf)


## 온도 증감에 따른 수조 온도 변화 그래프

![image](https://github.com/user-attachments/assets/c0cc8cf6-2d28-40d2-9818-2476815a0e3c)

- 최대 기준온도로부터 약 1°c 증가함에 따라 냉수조로부터 차가운 물을 주수받아 기준온도에 도달하여 정상 작동함을 확인 (a)
- 최소 기준온도로부터 약 1°C 감소함에 따라 온수조로부터 따뜻한 물을 주수받아 기준온도에 도달하여 정상 작동함을 확인 (b)

# 기대효과


- 온도, 수위 같은 수치 뿐 아니라 차후 사용자가 원하는 측정값을 추가하고, 다양한 편의기능을 추가함으로써 사용자의 사업이익 극대화
- 각 수조의 낭비되는 물을 재활용하여 기존 양식장 대비 에너지 효율이 개선되며, 이는 비용절감과 직결되어 사업경쟁력의 증대를 기대할 수 있음.

## 완성모델 실물도

![image](https://github.com/user-attachments/assets/f44045f1-1f7f-4486-b8bd-34c0580c155a)


## 프로젝트 후기
어떤 프로젝트든 마찬가지지만 역시 기획 단계에서 가장 많은 논의를 하였다. 충전식 배터리 도입이나 좀 더 대형의 수조를 자체 제작하는 방안도 검토해봤으나 예산의 문제로 기각되었고, 모바일 시스템 어플리케이션 개발이 처음이다 보니 블루투스 클라이언트 접속에서부터 애를 먹었다. 특히 아두이노의 모듈이 작고 품질이 좋지 않아 쉽게 방전되거나 망가져 분명 코드상으로는 문제가 없는데 접속이 되지 않는 문제가 많이 발생했다. 하지만 팀원들과 밤새가며 모델을 수정하고 코드 컴토를 수없이 해 멋진 결과물을 만들어 냈을때 성취감은 말로 이루어 할 수 없을 만큼 기뻣다. 덕분에 캡스톤 대회에서 대상이라는 큰상을 수상하게 되었고 상금으로 다 같이 먹은 소고기의 맛은 아직도 있을 수 없다. 마지막으로 통학하는 학생들을 위해 자취방을 빌려준 재훈, 지현 그리고 부족한 부분을 든든하게 서포트 해준 팀원 모두와 지도 교수 정지원 교수님께 감사의 인사를 드립니다.

![image](https://github.com/user-attachments/assets/c77105d9-ee92-46aa-9e2b-86ab7d0c97b3)




