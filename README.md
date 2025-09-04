# 🔥 Real-time Flame Intensity Classification using Machine Learning and IoT

This project combines **Machine Learning** and **IoT** to classify the **real-time intensity of kitchen flame** using a flame sensor connected to Arduino and deployed on a Raspberry Pi.

A **Decision Tree Classifier** is trained on labeled current readings from the flame sensor to identify four flame levels:
- **No Flame**
- **Low Flame**
- **Medium Flame**
- **High Flame**

The model is deployed on a Raspberry Pi which receives live sensor data from Arduino via serial communication and classifies the flame intensity in real-time.


### ⚙️ Technologies Used

- **Python**, **Arduino C**
- **scikit-learn**, **pandas**, **numpy**, **joblib**
- **Arduino Uno**, **Flame Sensor**, **Raspberry Pi 3B+**
- **Serial Communication (USB)**


### 🧠 Machine Learning Workflow

- Data Collection using Arduino
- Manual Labeling of flame intensity levels
- Model Training using `DecisionTreeClassifier`
- Model Export as `.pkl` (Pickle) files
- Model Deployment on Raspberry Pi using Python
- Real-time classification of streaming sensor data


### ✅ Features

- Real-time flame intensity classification
- End-to-end ML pipeline from data collection to deployment
- Edge ML deployment without cloud or internet dependency
- Easy integration with IoT platforms


### 🚀 Future Scope

- **Upgrade to TinyML** with model conversion to `.tflite` for microcontroller-only deployment
- **Cloud Integration** for storing flame level logs and remote monitoring
- **Alerting System** using email/SMS on unsafe flame levels
- **Mobile Dashboard** for live flame status monitoring
