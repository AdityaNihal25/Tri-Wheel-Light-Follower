# Tri-Wheel Light Follower

This project builds a simple three-wheel vehicle that autonomously steers towards the brightest light source. It uses two LDR sensors to detect light intensity and differentially controls two DC motors to turn toward light, with a third caster wheel providing balance.

---

## 📝 How it Works
- Reads analog values from two LDR sensors mounted on the front left and right.
- If the left sensor detects more light, slows the left wheel, turning the vehicle left.
- If the right sensor detects more light, slows the right wheel, turning the vehicle right.
- When both sensors see roughly equal light, it moves straight.

---

## ⚙️ Hardware Used
- Arduino Uno
- L298N Motor Driver
- 2 DC Motors (mounted on left & right sides)
- 1 free-rotating caster wheel (rear or front for stability)
- 2 LDR sensors + resistors for voltage divider
- Power supply (battery pack)

---

## 🔌 Arduino Pin Connections
| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| LDR Left  | A0          | Reads analog light intensity |
| LDR Right | A1          | Reads analog light intensity |
| ENA (Motor Left PWM) | 9 | Controls speed of left motor |
| IN1 (Motor Left) | 2   | Direction pin 1 |
| IN2 (Motor Left) | 3   | Direction pin 2 |
| ENB (Motor Right PWM) | 10 | Controls speed of right motor |
| IN3 (Motor Right) | 4 | Direction pin 1 |
| IN4 (Motor Right) | 5 | Direction pin 2 |

*(L298N VCC and GND connected to battery, ENA/ENB tied to Arduino PWM pins.)*

---

## 🚀 Usage
1. Upload `Tri_Wheel_Light_Follower.ino` to your Arduino Uno.
2. Place your vehicle in an environment with varying light sources.
3. It will automatically steer towards the brightest area by adjusting left/right motor speeds.

---

## ⚡ Tips for Reliable Operation
- Ensure LDR voltage dividers are tuned so `analogRead()` ranges from ~100 (dark) to ~900 (bright).
- Keep wires neat to avoid noise on analog pins.
- Use a sufficient power source for motors to prevent brownouts.

---

## 📷 Example Wiring Diagram
