# ♻️ AI-Based Intelligent Dustbin (AIDB)

An AI-powered smart waste segregation system designed for high-traffic environments like airports.

---

## 🚀 Features

- 🧠 AI-based waste classification (MobileNetV2)
- 📷 Real-time image capture using Raspberry Pi
- ⚙️ Arduino-controlled automation
- 🔄 Servo-based bin opening
- 📡 Ultrasonic sensor for object detection
- 💧 Soil moisture sensor for liquid vs solid detection
- 📺 LCD display output

---

## 🧠 Technologies Used

- Python
- TensorFlow / TFLite
- OpenCV
- Arduino C++
- Embedded Systems

---

## 🔧 Hardware Components

- Raspberry Pi
- Arduino Uno
- Servo Motors (MG90S)
- Ultrasonic Sensor (HC-SR04)
- Soil Moisture Sensor
- I2C LCD Display
- USB Camera

---

## ⚙️ System Workflow

1. User approaches dustbin
2. Ultrasonic sensor detects presence
3. Camera captures waste image
4. AI model classifies waste
5. Moisture sensor detects liquid/solid
6. Raspberry Pi sends result to Arduino
7. Servo opens corresponding bin
8. LCD displays waste type

---

## 🧪 Model Details

- Model: MobileNetV2
- Dataset: TrashNet
- Classes:
  - Cardboard
  - Glass
  - Metal
  - Paper
  - Plastic
  - Trash

---

## 🌍 Applications

- Airports
- Smart Cities
- Public Waste Management
- Railway Stations

---

## 🔮 Future Improvements

- Multi-class waste segregation
- IoT monitoring dashboard
- Cloud integration
- Smart bin fill-level detection

---

## 📌 Project Status

✅ Prototype Completed  
🚀 Ready for Hackathon Demo  

---

## 👨‍💻 Author

**Prajith Sekar**