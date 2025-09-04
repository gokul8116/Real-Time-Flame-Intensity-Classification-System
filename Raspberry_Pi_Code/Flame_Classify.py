import serial
import joblib
import numpy as np

# Load the model and label encoder
model = joblib.load('flame_model.pkl')
le = joblib.load('label_encoder.pkl')

print("Model and label encoder loaded successfully.")
print("Waiting for sensor data...")

# Connect to Arduino (adjust port if needed)
ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

while True:
    try:
        line = ser.readline().decode('utf-8').strip()

        if line and not line.startswith("Flame Current"):
            # Expected format: "45.27,Low Flame" → take only the current
            try:
                current_str = line.split(',')[0]
                current_val = float(current_str)

                # Reshape and cast to correct type
                input_data = np.array([[current_val]], dtype=np.float32)

                # Predict
                prediction = model.predict(input_data)
                predicted_label = le.inverse_transform(prediction)

                # Output the result
                print(predicted_label[0])

            except Exception as e:
                print(f"Parse error: {e}")

    except KeyboardInterrupt:
        print("\nStopped by user.")
        break

ser.close()
