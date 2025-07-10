# 🚨 SmokeSense: Arduino-Based Fire & Gas Detection System

*SmokeSense* is a smart safety system designed using Arduino that detects gas leaks and fire hazards in real time.  
It was built and tested using *Tinkercad Circuits*, allowing for a complete simulation of hardware behavior before implementation.

---

## 🎯 Features

- 🔥 Detects high temperature using TMP36 sensor
- 🧪 Detects smoke/gas using MQ2 sensor
- 🚨 Activates buzzer and LED when danger is detected
- 🧠 Ignores fake readings like -38°C for accuracy
- ⚡ Real-time status via Serial Monitor
- 🛠 Simulated and verified using *Tinkercad*

---

## 🧰 Components Used

| Component                | Quantity |
|--------------------------|----------|
| Arduino Uno              | 1        |
| MQ2 Gas Sensor           | 1        |
| TMP36 Temperature Sensor | 1        |
| LED                      | 1        |
| Piezo Buzzer             | 1        |
| Breadboard & Wires       | -        |

---

## ⚙ How It Works

- The *gas sensor (MQ2)* detects smoke or flammable gases.
- The *temperature sensor (TMP36)* checks for rising heat.
- If either gas > 400 or temperature > 45°C → it triggers:
  - ✅ LED ON
  - ✅ Buzzer ON
- If values are fake (like -38°C), they are *ignored* in code to avoid false alarms.

---

## 🔍 Threshold Logic

```cpp
if (temperature > 45°C || gas > 400)
{
    activate alarm (LED + buzzer)
}
