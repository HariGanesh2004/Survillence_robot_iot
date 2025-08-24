# Survillence_robot_iot
Remote controlled through internet Survillence robot(IoT)

# 🚗 Mobile-Controlled Robot using ESP32 (IoT Project)

This project is an **IoT-based robot** controlled through a mobile device using **Wi-Fi and ESP32**.  
The ESP32 board hosts a web server that allows the user to control the robot's movement (forward, backward, left, right, and stop) via a smartphone browser or a custom app.

---

## 🛠️ Tech Stack
- **Hardware**: ESP32, Motor Driver (L298N), DC Motors, Power Supply, Chassis
- **Software**: Arduino IDE, Embedded C
- **Communication**: Wi-Fi (ESP32 Web Server)

---

## 📸 Project Images
### Robot Setup
![Robot Setup](./photos/robot.jpg)
![Robot Setup](./photos/group.jpg)

---

## ⚙️ How It Works
1. The ESP32 is programmed to act as a **Wi-Fi Access Point** and a **Web Server**.
2. The user connects their phone to the ESP32 Wi-Fi and opens the control page.
3. Commands (forward, backward, left, right, stop) are sent via HTTP requests.
4. The ESP32 processes these commands and controls the motor driver to move the robot.

---

## 🧾 Features
- Wireless control via mobile device  
- Simple web interface with control buttons  
- Real-time movement response  
- Low-cost and easy to build 
